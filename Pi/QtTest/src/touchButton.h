#ifndef TOUCHBUTTON_H
#define TOUCHBUTTON_H

#include <QPushButton>
#include <QTouchEvent>
#include <QDebug>

class TouchButton : public QPushButton
{
    Q_OBJECT

public:
    explicit TouchButton(QWidget *parent = nullptr);  // 선언만 남김

protected:
    bool event(QEvent *event) override;  // 선언만 남김
};

#endif // TOUCHBUTTON_H
