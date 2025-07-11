#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_pushButtonB5_clicked();

    void on_pushButtonB10_clicked();

    void on_pushButtonC5_clicked();

    void on_pushButtonC10_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
