#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "array.h"
#include <QRegularExpression>

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

QVector<int> MainWindow::Input()
{
    QString text = ui->lineEditArr->text();
    QStringList parts = text.split(' ');
    QVector<int> numbers;

    for (const QString &s : parts)
    {
        if (!s.isEmpty())
        {
            numbers.append(s.toInt());
        }
    }

    return numbers;
}

void MainWindow::on_pushButtonB5_clicked()
{
    Array arr(Input());
    ui->textEditRes->setText("Длины серий: " + arr.B5());
}

void MainWindow::on_pushButtonB10_clicked()
{
    Array arr(Input());
    int k = ui->lineEditK->text().toInt();
    ui->textEditRes->setText(arr.B10(k));
}


void MainWindow::on_pushButtonSort_clicked()
{
    Array arr(Input());
    int N = ui->lineEditQ->text().toInt();
    QVector<int> arr3;
    int value = 1;
    for (int i = 0; i < N; i++)
    {
        arr3.push_back(value);
        value++;
    }
    int IndexDuplicate = arr.findDuplicate();
    int Element_Comparison = arr.checkArrays(N);
    if (IndexDuplicate == -1 && Element_Comparison == -1) {
       ui->textEditRes->setText("Перестановка");
    }
    else if (IndexDuplicate == -1 && Element_Comparison != -1) {
         ui->textEditRes->setText(QString::number(Element_Comparison));
    }
    else if (IndexDuplicate != -1 && Element_Comparison == -1) {
        ui->textEditRes->setText(QString::number(IndexDuplicate));
    }
    else
    {
        if (IndexDuplicate < Element_Comparison) {
           ui->textEditRes->setText(QString::number(IndexDuplicate));
        }
        else {
            ui->textEditRes->setText(QString::number(Element_Comparison));
        }
    }
}

void MainWindow::on_pushButtonApp_clicked()
{
    Array arr(Input());
    arr.Sort();
    int q = ui->lineEditQ->text().toInt();
    ui->textEditRes->setText("Макс. приближенное: " + arr.maxApproximate(q));
}

