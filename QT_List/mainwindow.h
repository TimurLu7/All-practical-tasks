#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>

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
    void on_action_2_triggered();

    void on_action_triggered();

    void on_action_4_triggered();

    void on_action_3_triggered();

    void on_pushButton_clicked();

    void on_action_5_triggered();

private:
    Ui::MainWindow *ui;
    QList<int> numbers;
    QList<int> result;

    void updateOutput();
    void processNumbers();
};
#endif // MAINWINDOW_H
