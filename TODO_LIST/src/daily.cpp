#include "daily.h"
#include "ui_daily.h"

DAILY::DAILY(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DAILY)
{
    ui->setupUi(this);
}

DAILY::~DAILY()
{
    delete ui;
}
