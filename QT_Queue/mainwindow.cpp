#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTableWidgetItem>

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

void MainWindow::on_addButton_clicked()
{
    Car car;
    car.brand = ui->brandEdit->text().trimmed();
    car.type = ui->comboBox->currentText();
    car.number = ui->numberEdit->text().trimmed();

    if(car.brand.isEmpty() || car.number.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Все поля должны быть заполнены");
        return;
    }

    cars.enqueue(car);
    updateTable();

    ui->brandEdit->clear();
    ui->numberEdit->clear();
    ui->brandEdit->setFocus();
}


void MainWindow::on_calculateButton_clicked()
{
    if(cars.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Нет автомобилей для обработки");
        return;
    }

    if(ui->searchNumberEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите номер для поиска");
        return;
    }

    processCalculation();
}


void MainWindow::on_clearButton_clicked()
{
    cars.clear();
    updateTable();
    ui->label->clear();
}

void MainWindow::updateTable()
{
    ui->tableWidget->setRowCount(cars.size());
    int row = 0;

    for (const Car &car : cars) {
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(car.brand));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(car.type));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(car.number));
        row++;
    }
}

void MainWindow::processCalculation()
{
    const int tc = ui->tcspinBox->value();
    const int gc = ui->gcspinBox->value();
    const int t = ui->tspinBox->value();
    const QString searchNumber = ui->searchNumberEdit->text();

    bool found = false;
    int greenTime = t * 60;
    int totalTime = 0;
    QQueue<Car> tempQueue = cars;

    while (!tempQueue.isEmpty() && greenTime > 0) {
        Car car = tempQueue.dequeue();
        int processTime;
        if (car.type == "Легковая")
        {
            processTime = tc;
        }
        else
        {
            processTime = gc;
        }
        totalTime += processTime;
        greenTime -= processTime;

        if (car.number == searchNumber)
        {
            found = true;
            break;
        }
    }

    QString result = found ?
                         QString("Yes! Затрачено времени: %1 сек")
                             .arg(totalTime) :
                         QString("No");

    ui->label->setText(result);
}

