#include <gtk/gtk.h>
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

// 서버 응답을 받아 요약 창을 표시하는 함수
void display_order_summary(const char* summary) {
    GtkWidget *summary_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(summary_window), "주문 내역");
    gtk_window_set_default_size(GTK_WINDOW(summary_window), 300, 200);

    GtkWidget *label = gtk_label_new(summary);
    gtk_container_add(GTK_CONTAINER(summary_window), label);

    gtk_widget_show_all(summary_window);

    // 요약 창을 닫아도 프로그램이 종료되지 않도록 설정
    g_signal_connect(summary_window, "destroy", G_CALLBACK(gtk_widget_destroy), NULL);
}

// 버튼 클릭 시 서버로 메뉴 ID 전송
void on_button_clicked(GtkWidget *widget, gpointer data) {
    const char* message = static_cast<const char*>(data);

    // 서버로 메시지 전송
    if (send(client_fd, message, strlen(message), 0) < 0) {
        cerr << "서버로 메시지 전송 실패\n";
        return;
    }

    // 서버 응답 수신
    int bytes_received = recv(client_fd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received > 0) {
        buffer[bytes_received] = '\0';

        // "주문 완료" 버튼으로 전체 주문 내역을 요청할 때만 요약 창 표시
        if (string(message) == "0") {
            display_order_summary(buffer);  // 주문 요약 창을 표시
        } else {
            cout << buffer << endl;  // 일반 주문 응답 출력
        }
    } else {
        cerr << "서버 응답 수신 실패\n";
    }
}

int main(int argc, char *argv[]) {
    struct sockaddr_in server_addr;

    // GTK 초기화
    gtk_init(&argc, &argv);

    // 소켓 생성 및 서버 연결
    client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd < 0) {
        cerr << "소켓 생성에 실패했습니다.\n";
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        cerr << "주소 형식이 알맞지 않거나 지원하지 않는 형식입니다.\n";
        return -1;
    }

    if (connect(client_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        cerr << "서버에 연결하지 못했습니다.\n";
        close(client_fd);
        return -1;
    }

    // 서버로부터 초기 환영 메시지 수신 및 출력
    int bytes_received = recv(client_fd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received > 0) {
        buffer[bytes_received] = '\0';
        cout << buffer << '\n';
    } else {
        cerr << "초기 서버 메시지 수신 실패\n";
    }

    // 메인 윈도우 생성
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "카페 키오스크");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    // 메인 창이 닫힐 때만 프로그램이 종료되도록 설정
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // 버튼 박스 생성
    GtkWidget *button_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), button_box);

    // 메뉴 버튼 생성 (예시로 3개 생성)
    GtkWidget *button1 = gtk_button_new_with_label("1번 메뉴 선택");
    GtkWidget *button2 = gtk_button_new_with_label("2번 메뉴 선택");
    GtkWidget *button3 = gtk_button_new_with_label("주문 완료");

    // 각 버튼 클릭 시 서버로 메뉴 ID 전송
    g_signal_connect(button1, "clicked", G_CALLBACK(on_button_clicked), (gpointer)"1");
    g_signal_connect(button2, "clicked", G_CALLBACK(on_button_clicked), (gpointer)"2");

    // "주문 완료" 버튼 클릭 시 전체 주문 내역 요청
    g_signal_connect(button3, "clicked", G_CALLBACK(on_button_clicked), (gpointer)"0");

    // 버튼 박스에 버튼 추가
    gtk_box_pack_start(GTK_BOX(button_box), button1, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(button_box), button2, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(button_box), button3, TRUE, TRUE, 0);

    // 창과 위젯을 화면에 표시
    gtk_widget_show_all(window);
    gtk_main();

    // 프로그램 종료 시 소켓 닫기
    close(client_fd);
    return 0;
}
