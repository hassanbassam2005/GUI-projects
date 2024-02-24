#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <Qfile>
#include <QStandardPaths>
#include <QTextStream>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ADD_BTN_clicked();

    void on_DLT_ALL_BTN_clicked();

    void on_DLT_BTN_clicked();

private:
    Ui::MainWindow *ui;

    QString path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation)+"\\todoFile.txt";
};
#endif // MAINWINDOW_H
