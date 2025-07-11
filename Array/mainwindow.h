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

    void on_pushButtonSort_clicked();

    void on_pushButtonApp_clicked();

private:
    Ui::MainWindow *ui;
     QVector<int> Input();
};
#endif // MAINWINDOW_H
