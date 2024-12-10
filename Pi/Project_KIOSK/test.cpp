#include <gtk/gtk.h>

void on_button_clicked(GtkWidget *widget, gpointer data) {
    g_print("Button clicked!\n");
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // 윈도우와 버튼 생성
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWidget *button = gtk_button_new_with_label("Click Me");

    // 윈도우 설정
    gtk_window_set_title(GTK_WINDOW(window), "Simple GTK Example");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 100);

    // 버튼 클릭 시 콜백 함수 연결
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), NULL);

    // 윈도우에 버튼 추가
    gtk_container_add(GTK_CONTAINER(window), button);

    // 창과 위젯을 화면에 표시
    gtk_widget_show_all(window);

    // 메인 루프 시작
    gtk_main();

    return 0;
}
