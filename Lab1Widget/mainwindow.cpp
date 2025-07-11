#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chisla.h"

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

void MainWindow::on_pushButtonB5_clicked()
{
    int x = ui->lineEdit1->text().toInt();
    int y = ui->lineEdit2->text().toInt();
    Chisla c(x, y);
    ui->textEdit->setText("Результат: " + c.B5());
}


void MainWindow::on_pushButtonB10_clicked()
{
    int a = ui->lineEdit1->text().toInt();
    Chisla c(a);
    ui->textEdit->setText("Результат: " + c.B10());
}


void MainWindow::on_pushButtonC5_clicked()
{
    int n = ui->lineEdit1->text().toInt();
    int k = ui->lineEdit2->text().toInt();
    Chisla c(n, k);
    ui->textEdit->setText("Результат: " + c.C5());
}


void MainWindow::on_pushButtonC10_clicked()
{
    int p = ui->lineEdit1->text().toInt();
    int q = ui->lineEdit2->text().toInt();
    Chisla c(p, q);
    ui->textEdit->setText("Результат: " + c.C10());
}

