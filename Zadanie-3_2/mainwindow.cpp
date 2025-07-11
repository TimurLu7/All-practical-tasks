#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTableWidget *table = ui->tableWidget;
    table->setColumnCount(5);
    table->setHorizontalHeaderLabels({"Type", "Name", "Age", "Course/Year", "Group"});
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table->setRowCount(5);


    Student student("Ivan", 19, 2, "2626");
    School school("Sasha", 15,1, "9B",9);
    School school2("Petr", 16,1, "10A", 10);

    table->setItem(0, 0, new QTableWidgetItem(student.getType()));
    table->setItem(0, 1, new QTableWidgetItem(student.getName()));
    table->setItem(0, 2, new QTableWidgetItem(QString::number(student.getAge())));
    table->setItem(0, 3, new QTableWidgetItem(QString::number(student.getCourse())));
    table->setItem(0, 4, new QTableWidgetItem(student.getGroup()));

    table->setItem(1, 0, new QTableWidgetItem(school.getType()));
    table->setItem(1, 1, new QTableWidgetItem(school.getName()));
    table->setItem(1, 2, new QTableWidgetItem(QString::number(school.getAge())));
    table->setItem(1, 3, new QTableWidgetItem(QString::number(school.getYear())));
    table->setItem(1, 4, new QTableWidgetItem(school.getGroup()));

    table->setItem(2, 0, new QTableWidgetItem(school2.getType()));
    table->setItem(2, 1, new QTableWidgetItem(school2.getName()));
    table->setItem(2, 2, new QTableWidgetItem(QString::number(school2.getAge())));
    table->setItem(2, 3, new QTableWidgetItem(QString::number(school2.getYear())));
    table->setItem(2, 4, new QTableWidgetItem(school2.getGroup()));

    school.setAge(16);
    school.setYear(10);
    school2.setAge(17);
    school2.setYear(11);
    school.setGroup("10B");
    school2.setGroup("11A");

    table->setItem(3, 0, new QTableWidgetItem(school.getType()));
    table->setItem(3, 1, new QTableWidgetItem(school.getName()));
    table->setItem(3, 2, new QTableWidgetItem(QString::number(school.getAge())));
    table->setItem(3, 3, new QTableWidgetItem(QString::number(school.getYear())));
    table->setItem(3, 4, new QTableWidgetItem(school.getGroup()));

    table->setItem(4, 0, new QTableWidgetItem(school2.getType()));
    table->setItem(4, 1, new QTableWidgetItem(school2.getName()));
    table->setItem(4, 2, new QTableWidgetItem(QString::number(school2.getAge())));
    table->setItem(4, 3, new QTableWidgetItem(QString::number(school2.getYear())));
    table->setItem(4, 4, new QTableWidgetItem(school2.getGroup()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
