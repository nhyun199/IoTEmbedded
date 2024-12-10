#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTabWidget>
#include <vector>
#include "menuButton.h"
#include "menuList.h"
#include "HeaderWidget.h"
using namespace std;

vector<MenuList> menu_list = getMenuList();

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget window;

    window.resize(800, 1000);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setContentsMargins(0, 0, 0, 0);

    HeaderWidget *headerWidget = new HeaderWidget("/home/pi/QtTest/src/image/logo.png", "/home/pi/QtTest/src/image/title.png");
    mainLayout->addWidget(headerWidget);
    
    QHBoxLayout *tailLayout = new QHBoxLayout;
    tailLayout->addStretch();
    tailLayout->setContentsMargins(0, 10, 30, 30);
    QPushButton *emptyButton = new QPushButton("결제하기",&window);
    emptyButton->setStyleSheet("font-size: 20pt;");
    emptyButton->setFixedSize(180, 70);
    tailLayout->addWidget(emptyButton);

    QTabWidget *tabWidget = new QTabWidget;
    tabWidget->addTab(new QWidget, "시즌");
    tabWidget->addTab(new QWidget, "커피");
    tabWidget->addTab(new QWidget, "음료");
    tabWidget->addTab(new QWidget, "베이커리");
    tabWidget->setStyleSheet("QTabBar { alignment: center; } QTabBar::tab { height: 50px; width: 200px; font-size: 18px; }"); // 탭 크기와 글꼴 크기 조정
    tabWidget->setTabPosition(QTabWidget::North);  // 탭을 상단에 배치
    
    mainLayout->addWidget(tabWidget);

    QWidget *tabContentWidget = new QWidget;
    QGridLayout *buttonLayout = new QGridLayout(tabContentWidget);

    for (int i = 0; i < menu_list.size(); i++)
    {
        QString imagePath = QString::fromStdString(menu_list[i].image_path);
        QString menuInfo = QString::fromStdString(menu_list[i].menu_info);
        QString buttonId = QString::number(i + 1) + "번";

        MenuButton *newButton = new MenuButton(imagePath, menuInfo, buttonId);
        newButton->setFixedSize(200, 250);
        buttonLayout->addWidget(newButton, i / 4, i % 4);
    }

    mainLayout->addWidget(tabContentWidget);
    mainLayout->addStretch(1);

    mainLayout->addLayout(tailLayout);
    window.setLayout(mainLayout);
    window.show();
    
    return app.exec();
}
