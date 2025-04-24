#include <iostream>
#include "ListStackImplementation.h"
#include "List.h"

ListStackImplementation::ListStackImplementation(){}
ListStackImplementation::ListStackImplementation(const ValueType* valueArray, const size_t arraySize)
{
    data.insert(valueArray, arraySize, 0);
}

ListStackImplementation::ListStackImplementation(const ListStackImplementation& copyStack)
{
    if (this == &copyStack)
    {
        return;
    }
    data.clear();
    data.insert(copyStack.data, 0);
}
ListStackImplementation& ListStackImplementation::operator=(const ListStackImplementation& copyStack)
{
    if (this == &copyStack)
    {
        return *this;
    }
    data.clear();
    data.insert(copyStack.data, 0);
    return *this;
}

ListStackImplementation::ListStackImplementation(ListStackImplementation&& moveStack) noexcept
{
    if (this == &moveStack)
    {
        return;
    }
    data.clear();
    data.insert(moveStack.data, 0);
    moveStack.data.clear();
}
ListStackImplementation& ListStackImplementation::operator=(ListStackImplementation&& moveStack) noexcept
{
    if (this == &moveStack)
    {
        return *this;
    }
    data.clear();
    data.insert(moveStack.data, 0);
    moveStack.data.clear();
    return *this;
}


void ListStackImplementation::push(const ValueType& value)
{
    data.pushBack(value);
}
void ListStackImplementation::pop()
{
    data.popBack();
}
const ValueType& ListStackImplementation::top() const
{
    return data[data.size()-1];
}
bool ListStackImplementation::isEmpty() const
{
    if (data.size() <= 0)
    {
        return true;
    }
    return false;
}
size_t ListStackImplementation::size() const
{
    return data.size();
}

void ListStackImplementation::clear()
{
    data.clear();
}
void ListStackImplementation::reverse()
{
    size_t n = data.size();
    ValueType arr[n];
    for (size_t i = 0; i < n; i++)
    {
        arr[n - i - 1] = data[i];
    }
    data.clear();
    for (size_t i = 0; i < n; i++)
    {
        data.pushBack(arr[i]);
    }
}

ListStackImplementation* ListStackImplementation::clone() const
{
    return new ListStackImplementation(*this);
}