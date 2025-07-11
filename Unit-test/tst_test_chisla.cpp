#include "chisla.cpp"
#include "test_chisla.h"

    void TestChisla::testB5_Druzhestvenie() {
        Chisla c(220, 284);
        QCOMPARE(c.B5(), QString("Chisla druzhestvenie"));
    }

    void TestChisla::testB5_Nedruzhestvenie() {
        Chisla c(10, 20);
        QCOMPARE(c.B5(), QString("Chisla nedruzhestvenie"));
    }

    void TestChisla::testB10_NoDuplicates() {
        Chisla c(20);
        QString expected = "1 2 3 4 5 6 7 8 9 10 12 13 14 15 16 17 18 19";
        QCOMPARE(c.B10(), expected);
    }

    void TestChisla::testC5_Division() {
        Chisla c(8, 10);
        QCOMPARE(c.C5(), QString("0.125"));
    }

    void TestChisla::testC5_ZeroDivision() {
        Chisla c(0, 10);
        QCOMPARE(c.C5(), QString("0."));
    }

    void TestChisla::testC10_EgyptianFraction() {
        Chisla c(3, 7);
        QCOMPARE(c.C10(), QString("1/3 + 1/11 + 1/231"));
    }

    void TestChisla::testC10_WholeNumber() {
        Chisla c(4, 2);
        QCOMPARE(c.C10(), QString("1/1"));
    }

QTEST_APPLESS_MAIN(TestChisla)
