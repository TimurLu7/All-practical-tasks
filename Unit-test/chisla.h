#ifndef CHISLA_H
#define CHISLA_H

#include <QString>

class Chisla
{
private:
    int x;
    int y;
public:
    Chisla(int a = 0, int b = 0) : x(a), y(b) {}

    QString B5();
    QString B10();
    QString C5();
    QString C10();
};
#endif // CHISLA_H
