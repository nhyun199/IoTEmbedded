#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string>
#include <cstring>
#include <chrono>
#include <sstream>
#include "menu.h"
#include "orderTime.h"

using namespace std;
#define PORT 8080

int main()
{
    string current_time = printOrderTime();

    int server_fd, client_fd;                    // 소켓 FD
    struct sockaddr_in server_addr, client_addr; // IP 주소와 포트 정보
    socklen_t client_len = sizeof(client_addr);  // 클라이언트 주소 길이 저장, accept에서 필요함

    // #1 소켓 생성
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    // AF_INET : IPv4, SOCK_STREAM : TCP/IP, 0 : protocol
    if (server_fd == 0) // 0 이라면 소켓 생성에 실패한 것
    {
        cerr << "서버 소켓 생성에 실패했습니다.\n";
        return -1;
    }
    cout << "서버 소켓 생성 성공\n";

    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
    {
        cerr << "Failed to set SO_REUSEADDR" << endl;
        close(server_fd);
        return -1;
    }

    // #2 서버 주소 설정
    server_addr.sin_family = AF_INET;         // IPv4
    server_addr.sin_addr.s_addr = INADDR_ANY; // 모든 요청 허용
    server_addr.sin_port = htons(PORT);       // Port Numbers

    // #3 Binding : 만든 server_fd 객체를 서버쪽으로 붙이는 작업
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        cerr << "바인딩에 실패했습니다.\n";
        close(server_fd);
        return -1;
    }
    cout << "바인딩 성공.\n";

    // #4 Listen : 서버를 열고 클라이언트의 연결을 기다리는 작업
    if (listen(server_fd, 3) < 0)
    {
        cerr << "대기 작업에 실패했습니다.\n";
        close(server_fd);
        return -1;
    }
    cout << "8080 포트에서 클라이언트의 연결을 대기중입니다.........\n";

    // #5 Accept : 클라이언트의 연결이 확인되면 연결을 허용하는 작업
    client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);
    if (client_fd < 0)
    {
        cerr << "클라이언트가 접속에 실패하였습니다.\n";
        close(server_fd);
        return -1;
    }
    cout << client_fd << "번 클라이언트가 접속되었습니다.\n";

    // 환영 메시지와 메뉴 전송
    string welcome = "\n---- 카페에 오신 걸 환영합니다 ----\n";
    string fullMenu = welcome;

    vector<Menu> menuList = getMenuList();
    for (const auto &menu : menuList)
    {
        fullMenu += '(' + to_string(menu.id) + ") " + menu.name + " : " + to_string(menu.price) + "원\n";
    }
    fullMenu += "(0): 주문 완료 및 내역 출력\n";
    send(client_fd, fullMenu.c_str(), fullMenu.size(), 0);

    vector<Menu> orderList; // 주문한 메뉴들을 저장할 리스트
    int total_price = 0;

    while (true)
    {
        char buffer[1024] = {0};
        int size = recv(client_fd, buffer, sizeof(buffer), 0);
        if (size > 0)
        {
            int selected_id = buffer[0] - '0'; // 첫 번째 문자로 선택된 ID 확인
            if (selected_id == 0)
            {
                sort(orderList.begin(), orderList.end(), [](const Menu &a, const Menu &b)
                     { return a.name < b.name; });

                // 주문 완료 처리
                string orderSummary = "\n---- 주문 일시 ----\n";
                orderSummary += current_time;
                orderSummary += "\n\n---- 주문 내역 ----\n";

                for (const auto &item : orderList)
                {
                    orderSummary += item.name + " : " + to_string(item.price) + "원\n";
                }

                // for (const auto& item : orderList)
                // {
                //     ostringstream line;
                //     line << left << setw(20) << item.name << right << setw(10) << item.price << "원\n";
                //     orderSummary += line.str();
                // }

                orderSummary += "\n--------------------\n총 결제 금액: " + to_string(total_price) + "원\n";
                orderSummary += "이용해주셔서 감사합니다.\n";
                send(client_fd, orderSummary.c_str(), orderSummary.size(), 0);
                break; // 주문 완료 후 종료
            }
            else if (selected_id >= 1 && selected_id <= menuList.size()) // 유효한 메뉴 선택 시 주문에 추가
            {
                const Menu &selected_menu = menuList[selected_id - 1];
                orderList.push_back(selected_menu);
                total_price += selected_menu.price;

                string response = to_string(selected_id) + "번 메뉴가 선택되었습니다: " + selected_menu.name + "\n";
                send(client_fd, response.c_str(), response.size(), 0);
            }
            else // 잘못된 선택 시
            {
                string response = "잘못된 선택입니다. 다시 선택해주세요.\n";
                send(client_fd, response.c_str(), response.size(), 0);
            }
        }
    }

    cout << "연결을 종료합니다.\n";
    close(client_fd);
    close(server_fd);

    return 0;
}