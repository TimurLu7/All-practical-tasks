#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QQueue>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

struct Car {
    QString brand;
    QString type;
    QString number;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addButton_clicked();

    void on_calculateButton_clicked();

    void on_clearButton_clicked();

private:
    Ui::MainWindow *ui;
    QQueue<Car> cars;

    void updateTable();
    void processCalculation();
};
#endif // MAINWINDOW_H
