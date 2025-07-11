#ifndef TEST_CHISLA_H
#define TEST_CHISLA_H

#include <QtTest>
#include "chisla.h"

class TestChisla : public QObject
{
    Q_OBJECT

private slots:
    void testB5_Druzhestvenie();
    void testB5_Nedruzhestvenie();
    void testB10_NoDuplicates();
    void testC5_Division();
    void testC5_ZeroDivision();
    void testC10_EgyptianFraction();
    void testC10_WholeNumber();
};

#endif // TEST_CHISLA_H
