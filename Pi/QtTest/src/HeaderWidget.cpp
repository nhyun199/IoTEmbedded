#include "HeaderWidget.h"
#include <QHBoxLayout>
#include <QFrame>

HeaderWidget::HeaderWidget(const QString &logoPath, const QString &titlePath, QWidget *parent)
    : QWidget(parent)
{
    QFrame *backgroundFrame = new QFrame(this);
    backgroundFrame->setStyleSheet("background-color: white;");
    QHBoxLayout *frameLayout = new QHBoxLayout(backgroundFrame);
    frameLayout->setContentsMargins(0, 0, 0, 0);
    frameLayout->setSpacing(0);

    QLabel *emptyLabel = new QLabel(backgroundFrame);
    emptyLabel->setFixedWidth(100);

    QLabel *titleLabel = new QLabel(backgroundFrame);
    QPixmap titlePixmap(titlePath);
    titleLabel->setPixmap(titlePixmap.scaled(70, 70, Qt::KeepAspectRatioByExpanding));
    titleLabel->setAlignment(Qt::AlignCenter);

    QLabel *logoLabel = new QLabel(backgroundFrame);
    QPixmap logoPixmap(logoPath);
    logoLabel->setPixmap(logoPixmap.scaled(70, 70, Qt::KeepAspectRatioByExpanding));
    logoLabel->setAlignment(Qt::AlignCenter);
    logoLabel->setStyleSheet("padding-right: 50px;");

    frameLayout->addWidget(emptyLabel, 0, Qt::AlignCenter);
    frameLayout->addWidget(titleLabel, 0,Qt::AlignCenter);
    frameLayout->addWidget(logoLabel, 0, Qt::AlignRight);

    backgroundFrame->setLayout(frameLayout);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->addWidget(backgroundFrame);

    setLayout(layout);
}
