#include "stack.h"

Stack::Stack()
{
}

void Stack::push(int value)
{
    data.append(value);
}

int Stack::pop()
{
    if (isEmpty()) return 0;
    return data.takeLast();
}

int Stack::size() const
{
    return data.size();
}

bool Stack::isEmpty() const
{
    return data.isEmpty();
}

const QVector<int>& Stack::getData() const
{
    return data;
}

void Stack::clear()
{
    data.clear();
}
