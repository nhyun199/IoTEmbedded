#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>
#include <cstring>
// #include <QApplication>
// #include <QPushButton>
// #include <QWidget>
// #include <QGridLayout>
// #include <QVBoxLayout>
// #include <vector>
// #include "menuButton.h"
// #include "menuList.h"

using namespace std;
#define PORT 8080
#define SERVER_IP "127.0.0.1"

int client_fd;
char buffer[1024];
//vector<MenuList> menu_list = getMenuList();

int main(int argc, char *argv[])
{
    struct sockaddr_in server_addr;
    
    client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(client_fd < 0)
    {
        cerr << "클라이언트 소켓 생성 실패\n";
        return -1;
    }
    cout << "클라이언트 소켓 생성\n";

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    if(inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0)
    {
        cerr << "주소 형식이 알맞지 않거나 지원하지 않는 형식입니다.\n";
        return -1;
    }
    cout << "유효한 주소 - 변환 성공\n";

    if(connect(client_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
    {
        cerr << "서버 연결 실패\n";
        close(client_fd);
        return -1;
    }
    cout << "------" << PORT << "포트 연결------\n";

    // GUI 시작
    // QApplication app(argc, argv);
    // QWidget window;
    // window.resize(1000, 900);

    // QGridLayout *buttonLayout = new QGridLayout;
    // QVBoxLayout *mainLayout = new QVBoxLayout;
    
    // for (int i = 0; i < 8; i++)
    // {
    //     MenuButton *newButton = new MenuButton(QString::fromStdString(menu_list[i].menu_name), QString::number(menu_list[i].menu_price));
    //     newButton->setFixedSize(200, 200);
    //     buttonLayout->addWidget(newButton, i / 4, i % 4);
    // }

    // mainLayout->addLayout(buttonLayout);
    // mainLayout->addStretch(1);

    // window.setLayout(mainLayout);
    // window.show();

    // int result = app.exec();

    int valread = recv(client_fd, buffer, sizeof(buffer), 0);
    if(valread > 0)
    {
        buffer[valread] = '\0';  // 문자열 끝 처리
        cout << "서버로부터 메시지 수신: " << buffer << endl;

        // 받은 메시지가 "RUN_GUI"라면 GUI 실행
        if(strcmp(buffer, "RUN_GUI") == 0)
        {
            cout << "GUI 실행 중...\n";
            system("./main");  // test 파일 실행
        }
    }

    // 연결 종료
    close(client_fd);

    //return result;
}
