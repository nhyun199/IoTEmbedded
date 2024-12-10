#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QDebug>
#include "menuButton.h"

using namespace Qt;

MenuButton::MenuButton(const QString &imagePath, const QString &menuInfo, const QString &id, QWidget *parent) 
    : TouchButton(parent), buttonId(id)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);

    setStyleSheet("QPushButton { background-color: white; border: none; }");
    
    imageLabel = new QLabel(this);
    QPixmap pixmap(imagePath);
    imageLabel->setPixmap(pixmap.scaled(200, 210, KeepAspectRatioByExpanding));
    imageLabel->setAlignment(AlignCenter);

    menuInfoLabel = new QLabel(menuInfo, this);
    menuInfoLabel->setAlignment(AlignCenter);
    menuInfoLabel->setStyleSheet("background-color: white;");

    layout->addWidget(imageLabel, 4);
    layout->addWidget(menuInfoLabel, 1);

    setLayout(layout);
    setFixedSize(200, 300);

    connect(this, &QPushButton::clicked, this, &MenuButton::handleClick);
}

void MenuButton::handleClick()
{
    qDebug() << buttonId << "버튼 클릭";
}