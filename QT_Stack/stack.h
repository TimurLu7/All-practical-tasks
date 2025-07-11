#ifndef STACK_H
#define STACK_H

#include <QVector>

class Stack
{
public:
    Stack();

    void push(int value);
    int pop();
    int size() const;
    bool isEmpty() const;
    const QVector<int>& getData() const;
    void clear();

private:
    QVector<int> data;
};

#endif // STACK_H
