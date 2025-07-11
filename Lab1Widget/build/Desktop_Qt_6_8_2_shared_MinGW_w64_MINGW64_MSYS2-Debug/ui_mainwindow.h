/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit1;
    QLineEdit *lineEdit2;
    QPushButton *pushButtonB5;
    QPushButton *pushButtonB10;
    QPushButton *pushButtonC5;
    QPushButton *pushButtonC10;
    QTextEdit *textEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1305, 790);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        lineEdit1 = new QLineEdit(centralwidget);
        lineEdit1->setObjectName("lineEdit1");
        lineEdit1->setGeometry(QRect(120, 70, 113, 28));
        lineEdit2 = new QLineEdit(centralwidget);
        lineEdit2->setObjectName("lineEdit2");
        lineEdit2->setGeometry(QRect(560, 70, 113, 28));
        pushButtonB5 = new QPushButton(centralwidget);
        pushButtonB5->setObjectName("pushButtonB5");
        pushButtonB5->setGeometry(QRect(40, 330, 431, 91));
        QFont font;
        font.setPointSize(11);
        pushButtonB5->setFont(font);
        pushButtonB10 = new QPushButton(centralwidget);
        pushButtonB10->setObjectName("pushButtonB10");
        pushButtonB10->setGeometry(QRect(40, 460, 631, 101));
        pushButtonB10->setFont(font);
        pushButtonC5 = new QPushButton(centralwidget);
        pushButtonC5->setObjectName("pushButtonC5");
        pushButtonC5->setGeometry(QRect(610, 330, 641, 91));
        QFont font1;
        font1.setPointSize(9);
        pushButtonC5->setFont(font1);
        pushButtonC10 = new QPushButton(centralwidget);
        pushButtonC10->setObjectName("pushButtonC10");
        pushButtonC10->setGeometry(QRect(710, 460, 571, 101));
        pushButtonC10->setFont(font1);
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(240, 150, 301, 131));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 20, 231, 31));
        QFont font2;
        font2.setPointSize(12);
        label->setFont(font2);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(520, 20, 211, 31));
        label_2->setFont(font2);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(960, 10, 281, 91));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1305, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButtonB5->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\262\320\265\321\200\320\270\321\202\321\214 \321\217\320\262\320\273\321\217\321\216\321\202\321\201\321\217 \320\273\320\270 \321\207\320\270\321\201\320\273\320\260 \320\264\321\200\321\203\320\266\320\265\321\201\321\202\320\262\320\265\320\275\320\275\321\213\320\274\320\270", nullptr));
        pushButtonB10->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\262\320\265\321\201\321\202\320\270 \320\262 \320\277\320\276\321\200\321\217\320\264\320\272\320\265 \320\262\320\276\320\267\321\200\320\260\321\201\321\202\320\260\320\275\320\270\321\217 \320\262\321\201\320\265 \321\207\320\270\321\201\320\273\320\260, \320\274\320\265\320\275\321\214\321\210\320\270\320\265 \320\267\320\260\320\264\320\260\320\275\320\275\320\276\320\263\320\276\n"
"\320\275\320\260\321\202\321\203\321\200\320\260\320\273\321\214\320\275\320\276\320\263\320\276 \321\207\320\270\321\201\320\273\320\260 N, \320\262 \320\264\320\265\321\201\321\217\321\202\320\270\321\207\320\275\320\276\320\271 \320\267\320\260\320\277\320\270\321\201\320\270 \320\272\320\276\321\202\320\276\321\200\321\213\321\205 \320\275\320\265\321\202 \320\276\320\264\320\270\320\275\320\260\320\272\320\276\320\262\321\213\321\205 \321\206\320\270\321\204\321\200. ", nullptr));
        pushButtonC5->setText(QCoreApplication::translate("MainWindow", "\320\224\320\260\320\275\321\213 \320\275\320\260\321\202\321\203\321\200\320\260\320\273\321\214\320\275\321\213\320\265 \321\207\320\270\321\201\320\273\320\260 n \320\270 k, n > 1.  \320\235\320\260\320\277\320\265\321\207\320\260\321\202\320\260\321\202\321\214  k \320\264\320\265\321\201\321\217\321\202\320\270\321\207\320\275\321\213\321\205 \320\267\320\275\320\260\320\272\320\276\320\262 \321\207\320\270\321\201\320\273\320\260 1/n.", nullptr));
        pushButtonC10->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\265\320\264\321\201\321\202\320\260\320\262\320\270\321\202\321\214 \320\264\321\200\320\276\320\261\321\214 p/q (0<p<q<16) \320\262 \320\262\320\270\320\264\320\265 \321\201\321\203\320\274\320\274\321\213 \321\200\320\260\320\267\320\273\320\270\321\207\320\275\321\213\321\205 \320\264\321\200\320\276\320\261\320\265\320\271,\n"
"\321\207\320\270\321\201\320\273\320\270\321\202\320\265\320\273\321\214 \320\272\320\276\321\202\320\276\321\200\321\213\321\205 \321\200\320\260\320\262\320\265\320\275 1.", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\265\321\200\320\262\320\276\320\265 \321\207\320\270\321\201\320\273\320\276", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\262\321\202\320\276\321\200\320\276\320\265 \321\207\320\270\321\201\320\273\320\276", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\264\320\263\320\276\321\202\320\276\320\262\320\270\320\273 \320\233\321\203 \320\242\320\270\320\274\321\203\321\200 5 \320\263\321\200\321\203\320\277\320\277\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
