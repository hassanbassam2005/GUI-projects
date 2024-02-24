#include "mainwindow.h"
#include "daily.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile file(QStandardPaths::writableLocation(QStandardPaths::HomeLocation)+"\\todoFile.txt");
    if(!file.open(QIODevice::ReadWrite))
    {
        QMessageBox::information(0,"error",file.errorString());
    }

    QTextStream in(&file);

    while(!in.atEnd())
    {
        QListWidgetItem* item = new QListWidgetItem(in.readLine(), ui->listWidget);
        ui->listWidget->addItem(item);
        item->setFlags(item->flags() | Qt::ItemIsEditable);
    }

    file.close();
}

MainWindow::~MainWindow()
{
    QFile file = (path);

    if(!file.open(QIODevice::ReadWrite))
    {
        QMessageBox::information(0,"error",file.errorString());
    }

    QTextStream out(&file);

    for(int i = 0;i<ui->listWidget->count(); ++i)
    {
        out<<ui->listWidget->item(i)->text()<<"\n";
    }

    file.close();

    delete ui;
}

void MainWindow::on_ADD_BTN_clicked()
{
    QString newItemTxt = ui->TXT_BTN->text();
    QMessageBox msgBox;

    if(!newItemTxt.isEmpty())
    {
        QListWidgetItem* item = new QListWidgetItem(ui->TXT_BTN->text(),ui->listWidget);
        ui->listWidget->addItem(item);
        item->setFlags(item->flags() | Qt::ItemIsEditable);
        ui->TXT_BTN->clear();
        ui->TXT_BTN->setFocus();
    }
    else
    {
        msgBox.setWindowTitle("Info");
        msgBox.setText("you should write task");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setIcon(QMessageBox::Information);
        msgBox.exec();
    }
}


void MainWindow::on_DLT_BTN_clicked()
{
    QListWidgetItem* item = ui->listWidget->takeItem(ui->listWidget->currentRow());
    delete item;
}


void MainWindow::on_DLT_ALL_BTN_clicked()
{
    ui->listWidget->clear();
}
