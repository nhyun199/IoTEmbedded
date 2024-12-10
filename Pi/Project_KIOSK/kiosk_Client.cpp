#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>
#include <cstring>

using namespace std;
#define PORT 8080
#define SERVER_IP "127.0.0.1"

int client_fd;
char buffer[1024];

int main()
{
    
    struct sockaddr_in server_addr;
    

    client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(client_fd < 0)
    {
        cerr << "소켓 생성에 실패했습니다.\n";
        return -1;
    }
    cout << "클라이언트 소켓 생성 성공\n";

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    if(inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0)
    {
        cerr << "주소 형식이 알맞지 않거나 지원하지 않는 형식입니다.\n";
        return -1;
    }
    cout << "알맞은 주소입니다. 변환에 성공했습니다.\n";

    if(connect(client_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
    {
        cerr << "서버에 연결하지 못했습니다.\n";
        close(client_fd);
        return -1;
    }
    cout << "포트 " << PORT << "에 연결하는데 성공했습니다.\n";

    int bytes_received = recv(client_fd, buffer, sizeof(buffer)-1, 0);
    if(bytes_received > 0)
    {
        buffer[bytes_received] = '\0';
        cout << buffer << '\n';
    }

    while (true) {
        // 사용자 입력
        cout << "번호를 입력해주세요 : ";
        string client_message;
        getline(cin, client_message);

        // 서버로 메시지 전송
        send(client_fd, client_message.c_str(), client_message.size(), 0);

        // 서버의 응답 수신
        bytes_received = recv(client_fd, buffer, sizeof(buffer) - 1, 0);
        if (bytes_received > 0) {
            buffer[bytes_received] = '\0';
            cout << buffer << endl;

            // "이용해주셔서 감사합니다." 메시지로 종료 조건 확인
            if (string(buffer).find("이용해주셔서 감사합니다.") != string::npos) {
                break;
            }
        }
    }

    cout << "연결을 종료합니다.\n";
    close(client_fd);

}