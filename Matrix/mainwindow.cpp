#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTextStream>
#include <QRegularExpression>

class Matrix
{
private:
    QVector<QVector<int>> ma;
    int str;
    int stl;
public:
    Matrix(int rows = 0, int cols = 0) : str(rows), stl(cols)
    {
        ma.resize(str);
        for (int i = 0; i < str; ++i)
        {
            ma[i].resize(stl, 0);
        }
    }

   bool fillFromString(const QString& text)
    {
        QStringList numbers = text.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
        if (numbers.size() < str * stl)
            return false;

        int index = 0;
        for (int i = 0; i < str; i++)
        {
            for (int j = 0; j < stl; j++)
            {
                bool ok;
                ma[i][j] = numbers[index++].toInt(&ok);
                if (!ok) return false;
            }
        }
        return true;
    }

    int Characteristic(int col) const
    {
        int sum = 0;
        for (int i = 0; i < str; i++)
        {
            if (ma[i][col] < 0 && ma[i][col] % 2 != 0)
            {
                sum += -ma[i][col];
            }
        }
        return sum;
    }

    void sort()
    {
        QVector<int> characteristics(stl);
        QVector<int> index(stl);

        for (int a = 0; a < stl; a++)
        {
            characteristics[a] = Characteristic(a);
            index[a] = a;
        }

        for (int i = 0; i < stl - 1; i++)
        {
            for (int j = 0; j < stl - i - 1; j++)
            {
                if (characteristics[j] > characteristics[j + 1])
                {
                    std::swap(index[j], index[j + 1]);
                }
            }
        }

        QVector<QVector<int>> sortedMatrix(str, QVector<int>(stl));
        for (int i = 0; i < str; i++)
        {
            for (int j = 0; j < stl; j++)
            {
                sortedMatrix[i][j] = ma[i][index[j]];
            }
        }

        ma = sortedMatrix;
    }

    QString toString() const
    {
        QString result;
        QTextStream out(&result);
        for (int i = 0; i < str; i++)
        {
            for (int j = 0; j < stl; j++)
            {
                out << ma[i][j] << "\t";
            }
            out << "\n";
        }
        return result;
    }
};

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

void MainWindow::on_pushButton_clicked()
{
    bool ok1, ok2;
    int n = ui->lineEdit->text().toInt(&ok1);
    int m = ui->lineEdit_2->text().toInt(&ok2);

    if (!ok1 || !ok2 || n <= 0 || m <= 0)
    {
        QMessageBox::warning(this, "Ошибка", "Введите корректные размеры матрицы!");
        return;
    }

    Matrix matrix(n, m);
    QString inputText = ui->textEdit->toPlainText();

    if (!matrix.fillFromString(inputText))
    {
        QMessageBox::warning(this, "Ошибка",
                             "Не удалось заполнить матрицу. Проверьте, что введено достаточно чисел и все они целые.");
        return;
    }

    matrix.sort();
    ui->textEdit_2->setPlainText(matrix.toString());
}
