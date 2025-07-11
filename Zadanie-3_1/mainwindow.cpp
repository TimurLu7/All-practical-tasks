// Лу Тимур 5 группа
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
#include <QTableWidgetItem>

class Figure
{
protected:
    double a;
    double b;

public:
    Figure(double a1, double b1){
        a=a1;
        b=b1;
    }
    virtual ~Figure() {}

    virtual double square() = 0;
    virtual double perimeter() = 0;
    virtual QString name() = 0;
    virtual void move(double A, double B)
    {
        a = A;
        b = B;
    }
};

class Rectangle : public Figure
{
public:
    Rectangle(double len, double wid) : Figure(0, 0)
    {
        a = len;
        b = wid;
    }
    QString name() override { return "Rectangle"; }
    double square() override { return a * b; }
    double perimeter() override { return 2 * (a + b); }
};

class Triangle : public Figure
{
public:
    Triangle(double osn, double hei) : Figure(0, 0)
    {
        a=osn;
        b=hei;
    }
    QString name() override { return "Triangle"; }
    double square() override { return 0.5 * a * b; }
    double perimeter() override
    {
        double side = sqrt(pow(a / 2, 2) + pow(b, 2));
        return 2 * side + a;
    }
};


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupTable();
}

void MainWindow::setupTable()
{
    QTableWidget *table = ui->tableWidget;

    table->setColumnCount(5);
    table->setHorizontalHeaderLabels({"Figure", "Parameter 1", "Parameter 2", "Square", "Perimeter"});
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table->setRowCount(4);

    Rectangle rec(9.0, 6.0);
    Triangle tr(6.0, 4.0);

    table->setItem(0, 0, new QTableWidgetItem(rec.name()));
    table->setItem(0, 1, new QTableWidgetItem(QString::number(9.0)));
    table->setItem(0, 2, new QTableWidgetItem(QString::number(6.0)));
    table->setItem(0, 3, new QTableWidgetItem(QString::number(rec.square())));
    table->setItem(0, 4, new QTableWidgetItem(QString::number(rec.perimeter())));

    table->setItem(1, 0, new QTableWidgetItem(tr.name()));
    table->setItem(1, 1, new QTableWidgetItem(QString::number(6.0)));
    table->setItem(1, 2, new QTableWidgetItem(QString::number(4.0)));
    table->setItem(1, 3, new QTableWidgetItem(QString::number(tr.square())));
    table->setItem(1, 4, new QTableWidgetItem(QString::number(tr.perimeter())));

    rec.move(12.0, 7.0);
    tr.move(10.0, 12.0);

    table->setItem(2, 0, new QTableWidgetItem(rec.name()));
    table->setItem(2, 1, new QTableWidgetItem(QString::number(12.0)));
    table->setItem(2, 2, new QTableWidgetItem(QString::number(7.0)));
    table->setItem(2, 3, new QTableWidgetItem(QString::number(rec.square())));
    table->setItem(2, 4, new QTableWidgetItem(QString::number(rec.perimeter())));

    table->setItem(3, 0, new QTableWidgetItem(tr.name()));
    table->setItem(3, 1, new QTableWidgetItem(QString::number(10.0)));
    table->setItem(3, 2, new QTableWidgetItem(QString::number(12.0)));
    table->setItem(3, 3, new QTableWidgetItem(QString::number(tr.square())));
    table->setItem(3, 4, new QTableWidgetItem(QString::number(tr.perimeter())));

}
MainWindow::~MainWindow()
{
    delete ui;
}
