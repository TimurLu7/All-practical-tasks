#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <algorithm>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(
        this,
        tr("Открыть текстовый файл"),
        "",
        tr("Текстовые файлы (*.txt)")
        );
    if (fileName.isEmpty()) {
        return;
    }
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(
            this,
            tr("Ошибка"),
            tr("Не удалось открыть файл: %1").arg(file.errorString())
            );
        return;
    }

    numbers.clear();

    QTextStream in(&file);

    while (!in.atEnd()) {
        int value;
        in >> value;
        if (!in.status()) {
            numbers.append(value);
        }
    }

    file.close();
}

void MainWindow::on_action_2_triggered()
{
    if(result.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Нет результата для сохранения");
        return;
    }

    QString fileName = QFileDialog::getSaveFileName(this, "Сохранить результат", "", "Текстовые файлы (*.txt)");
    if(fileName.isEmpty()) return;

    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось сохранить файл");
        return;
    }

    QTextStream out(&file);
    for(int value : result) {
        out << value << " ";
    }
    file.close();
    ui->outputText->append("Результат сохранен в файл: " + fileName);
}


void MainWindow::on_action_4_triggered()
{
    numbers.clear();
    result.clear();
    ui->outputText->clear();
}


void MainWindow::on_action_3_triggered()
{
    close();
}

void MainWindow::processNumbers()
{
    auto min = std::min_element(numbers.begin(), numbers.end());
    auto max = std::max_element(numbers.begin(), numbers.end());

    result.clear();
    result.append(*min);
    result.append(*max);

    for(auto it = numbers.begin(); it != numbers.end(); ++it) {
        if(it != min && it != max) {
            result.append(*it);
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    processNumbers();
    updateOutput();
}

void MainWindow::updateOutput()
{
    QString original = "Исходные: ";
    for(int num : numbers) {
        original += QString::number(num) + " ";
    }

    QString processed = "Результат: ";
    for(int num : result) {
        processed += QString::number(num) + " ";
    }

    ui->outputText->append(original);
    ui->outputText->append(processed);
}


void MainWindow::on_action_5_triggered()
{
    QString task =
        "5. В файле input.txt задан набор целых чисел.\n Записать их в память.\n Просматривая список,  найти  наибольший и наименьший элементы\n  и переставить их в начало,\nрезультат записать в новый список и вывести в файл Output.txt";

    QMessageBox::information(this,
                             "Условие задачи:",
                             task);
}

