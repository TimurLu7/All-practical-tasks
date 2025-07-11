#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     updateDisplay();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::updateDisplay()
{
    ui->textEdit->clear();
    const QVector<int>& data = stack.getData();
    for (int value : data)
    {
        ui->textEdit->append(QString::number(value));
    }
}

int MainWindow::countEqualNeighbors() const
{
    const QVector<int>& data = stack.getData();
    int count = 0;

    for (int i = 1; i < data.size() - 1; i++)
    {
        if (data[i - 1] == data[i + 1])
        {
            count++;
        }
    }

    return count;
}

void MainWindow::on_action_2_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Открыть текстовый файл", "", "Текстовые файлы (*.txt)");
    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл");
        return;
    }

    stack.clear();
    QTextStream in(&file);
    while (!in.atEnd())
    {
        int value;
        in >> value;
        stack.push(value);
    }
    file.close();

    updateDisplay();
}


void MainWindow::on_action_3_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Сохранить текстовый файл", "", "Текстовые файлы (*.txt)");
    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Ошибка", "Не удалось сохранить файл");
        return;
    }

    QTextStream out(&file);
    const QVector<int>& data = stack.getData();
    for (int value : data)
    {
        out << value << "\n";
    }
    file.close();
}


void MainWindow::on_action_4_triggered()
{
    close();
}



void MainWindow::on_action_5_triggered()
{
    stack.clear();
    updateDisplay();
}


void MainWindow::on_action_6_triggered()
{
    int count = countEqualNeighbors();
    QMessageBox::information(this, "Результат",
                             QString("Количество элементов с равными соседями: %1").arg(count));
}

