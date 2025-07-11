#include "chisla.h"
#include <QString>


QString Chisla::B5()
{
    int Sum = 0, Sum1 = 0;

    for (int d = 1; d <= y / 2; d++)
        if (y % d == 0)
            Sum += d;

    for (int d1 = 1; d1 <= x / 2; d1++)
        if (x % d1 == 0)
            Sum1 += d1;

    if (x == Sum && y == Sum1)
        return "Chisla druzhestvenie";
    else
        return "Chisla nedruzhestvenie";
}

QString Chisla::B10()
{
    QString result;

    for (int i = 1; i < x; i++)
    {
        int num = i;
        bool hasDuplicate = false;

        for (int d1 = num; d1 > 0; d1 /= 10)
        {
            int a1 = d1 % 10;
            for (int d2 = d1 / 10; d2 > 0; d2 /= 10)
            {
                int a2 = d2 % 10;
                if (a1 == a2)
                {
                    hasDuplicate = true;
                    break;
                }
            }
            if (hasDuplicate) break;
        }

        if (!hasDuplicate)
        {
            result += QString::number(i) + " ";
        }
    }

    return result.trimmed(); // убираем последний пробел
}

QString Chisla::C5()
{
    QString result;
    int a = 0;
    int r = 10;
    int i = 0;

    while (i < y)
    {
        i++;
        a = r / x;
        result += QString::number(a);
        r = (r % x) * 10;

        if (r == 0)
            break;
    }

    return "0." + result;
}

QString Chisla::C10()
{
    QString result;

    while (x != 0)
    {
        int n;
        int a = y % x;

        if (a > 0)
            n = y / x + 1;
        else
            n = y / x;

        result += "1/" + QString::number(n);

        x = x * n - y;
        y = y * n;

        if (x != 0)
            result += " + ";
    }

    return result;
}
