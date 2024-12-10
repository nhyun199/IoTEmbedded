#include <QWidget>
#include <QLabel>
#include <QPixmap>

class HeaderWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HeaderWidget(const QString &logoPath, const QString &titlepath, QWidget *parent = nullptr);
};