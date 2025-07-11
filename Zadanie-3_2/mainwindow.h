#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class Student
{
protected:
    QString name;
    int age;
    int course;
    QString group;

public:
    Student(QString Name, int Age, int Course, QString Group)
    {
        name = Name;
        age = Age;
        course = Course;
        group = Group;
    }
    virtual ~Student() {}
    virtual QString getType() const { return "Student"; }
    int getAge() const { return age; }
    int getCourse() const { return course; }
    QString getName() const { return name; }
    QString getGroup() const { return group; }
    void setAge(int a) { age = a; }
    void setGroup(const QString& newGroup) {
        group = newGroup;
    }
};
class School : public Student {
private:
    int year;
public:
    School() : Student("No", 0, 0, "No")
    {
        year = 0;
    }

    School(QString Name, int Age, int Year)
        : Student(Name, Age, 0, "School")
    {
        year = Year;
    }

    School(QString Name, int Age, int Course, QString Group, int Year)
        : Student(Name, Age, 0, Group)
    {
        year = Year;
    }
    QString getType() const override { return "School"; }
    int getYear() const { return year; }
    void setYear(int y) { year = y; }
    void setGroup(const QString& newGroup) {
        group = newGroup;
    }
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
