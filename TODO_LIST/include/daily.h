#ifndef DAILY_H
#define DAILY_H

#include <QWidget>

namespace Ui {
class DAILY;
}

class DAILY : public QWidget
{
    Q_OBJECT

public:
    explicit DAILY(QWidget *parent = nullptr);
    ~DAILY();

private:
    Ui::DAILY *ui;
};

#endif // DAILY_H
