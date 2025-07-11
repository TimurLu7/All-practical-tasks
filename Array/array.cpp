#include "array.h"
#include <algorithm>

QString Array::toString()
{
    QString result;
    for (int a : array)
    {
        result += QString::number(a) + " ";
    }
    return result.trimmed();
}

QString Array::B5()
{
    QString result;
    int length = 1;
    for (int i = 1; i < array.size(); i++)
    {
        if (array[i] == array[i - 1])
        {
            length++;
        } else
        {
            result += QString::number(length) + " ";
            length = 1;
        }
    }
    result += QString::number(length);
    return result.trimmed();
}

QString Array::B10(int k)
{
    QVector<int> coeff = array;
    int n = coeff.size() - 1;
    QString result;

    for (int p = 1; p <= k; p++)
    {
        for (int i = 0; i < n; i++)
        {
            coeff[i] = (i + 1) * coeff[i + 1];
        }
        result += QString::number(p) + "-я производная: ";
        for (int j = 0; j <= n - p; j++) {
            result += "+" + QString::number(coeff[j]) + "x^" + QString::number(j) + " ";
        }
        result += "\n";
    }

    return result.trimmed();
}

void Array::Sort()
{
    std::sort(array.begin(), array.end());
}

QString Array::maxApproximate(int q)
{
    int maxApprox = array[0];
    int p = 1;
    while (p < array.size() && array[p] <= q)
    {
        maxApprox = array[p];
        p++;
    }

    if (p < array.size() && (array[p] - q) < (q - maxApprox))
    {
        maxApprox = array[p];
    }

    return QString::number(maxApprox);
}

int Array:: findDuplicate()
{
    int n=array.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (array[i] == array[j])
            {
                return j + 1;
            }
        }
    }
    return -1;
}

int Array::checkArrays( int N)
{
    QVector<int> arr1=array;
    int n=arr1.size();
    for (int j = 0; j < n; j++)
    {
        bool found = false;
        for (int i = 0; i < N; i++)
        {
            if (arr1[j] == array[i])
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            return j + 1;
        }
    }
    return -1;
}
