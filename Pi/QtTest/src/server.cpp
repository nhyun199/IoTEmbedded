#include <iostream>
#include <iomanip>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
using namespace std;
#define PORT 8080

int main()
{
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd < 0)
    {
        cerr << "서버 소켓 생성 실패\n";
        return -1;
    }
    cout << "서버 소켓 생성\n";
    
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
    {
        cerr << "Failed to set SO_REUSEADDR" << endl;
        close(server_fd);
        return -1;
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if(bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
    {
        cerr << "바인드 실패\n";
        return -1;
    }
    cout << "바인드 성공\n";

    if(listen(server_fd, 3)< 0)
    {
        cerr << "대기열 생성 실패\n";
        close(server_fd);
        return -1;
    }
    cout << "------ 클라이언트 연결 대기 ------\n";

    client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_len);
    if(client_fd  < 0)
    {
        cerr << "클라이언트 접속 실패\n";
        close(server_fd);
        return -1;
    }
    cout << client_fd << "번 클라이언트 접속\n";

    
    
    const char* message = "RUN_GUI";
    send(client_fd, message, strlen(message), 0);

    char buffer[1024];
    while (true)
    {
        int bytes_received = recv(client_fd, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0)
        {
            cout << "클라이언트 연결 종료\n";
            break;
        }
    }
    cout << "연결 종료\n";
    
    close(client_fd);
    close(server_fd);
}