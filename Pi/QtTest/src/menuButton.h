#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QString>
#include <QPixmap>
#include "touchButton.h"

class MenuButton : public TouchButton
{
    Q_OBJECT

private :
    QLabel *imageLabel;
    QLabel *menuInfoLabel;
    QString buttonId;
public:
    MenuButton(const QString &imagePath, const QString &menuInfo, const QString &id, QWidget *parent = nullptr);
public slots:
    void handleClick();
};

#endif