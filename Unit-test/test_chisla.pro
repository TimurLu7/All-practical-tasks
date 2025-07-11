QT += testlib
QT -= gui
CONFIG += testcase

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_test_chisla.cpp \
    chisla.cpp

HEADERS += \
    chisla.h \
    test_chisla.h
