#ifndef ARRAY_H
#define ARRAY_H

#include <QVector>
#include <QString>

class Array
{
private:
    QVector<int> array;

public:
    Array(const QVector<int>& arr = {})
    {
        array = arr;
    }

    QString toString();
    QString B5();
    QString B10(int k);
    void Sort();
    QString maxApproximate(int q);
    int findDuplicate();
    int checkArrays(int N);
};

#endif // ARRAY_H
