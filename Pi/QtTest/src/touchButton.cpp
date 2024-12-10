#include "touchButton.h"

TouchButton::TouchButton(QWidget *parent) : QPushButton(parent)
{
    setAttribute(Qt::WA_AcceptTouchEvents, true); // 터치 이벤트 허용
}

// 터치 이벤트 처리
bool TouchButton::event(QEvent *event)
{
    if (event->type() == QEvent::TouchBegin || event->type() == QEvent::TouchEnd) {
        QTouchEvent *touchEvent = static_cast<QTouchEvent *>(event);
        if (!touchEvent->touchPoints().isEmpty()) {
            qDebug() << "Touch event detected!";
            // 추가적인 터치 처리 로직 추가 가능
        }
        return true;
    }
    return QPushButton::event(event);
}
