#include <QtTest/QtTest>
#include "chisla.h"

class TestChisla : public QObject
{
    Q_OBJECT

private slots:
    void testB5_Druzhestvenie() {
        Chisla c(220, 284);
        QCOMPARE(c.B5(), QString("Chisla druzhestvenie"));
    }

    void testB5_Nedruzhestvenie() {
        Chisla c(10, 20);
        QCOMPARE(c.B5(), QString("Chisla nedruzhestvenie"));
    }

    void testB10_NoDuplicates() {
        Chisla c(20);
        QString expected = "1 2 3 4 5 6 7 8 9 10 12 13 14 15 16 17 18 19";
        QCOMPARE(c.B10(), expected);
    }

    void testB10_EmptyIfXIs1() {
        Chisla c(1);
        QCOMPARE(c.B10(), QString(""));
    }

    void testC5_Division() {
        Chisla c(8, 10);
        QCOMPARE(c.C5(), QString("0.125"));
    }

    void testC5_ZeroDivision() {
        Chisla c(0, 10);
        QCOMPARE(c.C5(), QString("0."));
    }

    void testC10_EgyptianFraction() {
        Chisla c(3, 7);
        QCOMPARE(c.C10(), QString("1/3 + 1/11 + 1/231"));
    }

    void testC10_WholeNumber() {
        Chisla c(4, 2);
        QCOMPARE(c.C10(), QString("1/1"));
    }
};

QTEST_APPLESS_MAIN(TestChisla)
#include "test_chisla.moc"
