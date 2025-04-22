#include <iostream>
#include <list>
#include "ListStackImplementation.h"

ListStackImplementation::ListStackImplementation(){}
ListStackImplementation::ListStackImplementation(const ValueType* valueArray, const size_t arraySize)
{
    data.insert(data.begin(), valueArray, valueArray + arraySize);
}

ListStackImplementation::ListStackImplementation(const ListStackImplementation& copyStack)
{
    if (this == &copyStack)
    {
        return;
    }
    data.clear();
    data.insert(data.begin(), copyStack.data.begin(), copyStack.data.end());
}
ListStackImplementation& ListStackImplementation::operator=(const ListStackImplementation& copyStack)
{
    if (this == &copyStack)
    {
        return *this;
    }
    data.clear();
    data.insert(data.begin(), copyStack.data.begin(), copyStack.data.end());
    return *this;
}

ListStackImplementation::ListStackImplementation(ListStackImplementation&& moveStack) noexcept
{
    if (this == &moveStack)
    {
        return;
    }
    data.clear();
    data.insert(data.begin(), moveStack.data.begin(), moveStack.data.end());
    moveStack.data.clear();
}
ListStackImplementation& ListStackImplementation::operator=(ListStackImplementation&& moveStack) noexcept
{
    if (this == &moveStack)
    {
        return *this;
    }
    data.clear();
    data.insert(data.begin(), moveStack.data.begin(), moveStack.data.end());
    moveStack.data.clear();
    return *this;
}


void ListStackImplementation::push(const ValueType& value)
{
    data.push_back(value);
}
void ListStackImplementation::pop()
{
    data.pop_back();
}
const ValueType& ListStackImplementation::top() const
{
    auto it = data.begin();
    advance(it, data.size()-1);
    return *it;
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
    auto it = data.begin();
    for (size_t i = 0; i < n; i++)
    {
        arr[n - i - 1] = *it;
        advance(it, 1);
    }
    data.clear();
    for (size_t i = 0; i < n; i++)
    {
        data.push_back(arr[i]);
    }
}

ListStackImplementation* ListStackImplementation::clone() const
{
    return new ListStackImplementation(*this);
}