#include <iostream>
#include <vector>
#include "VectorStackImplementation.h"

VectorStackImplementation::VectorStackImplementation(){}
VectorStackImplementation::VectorStackImplementation(const ValueType* valueArray, const size_t arraySize)
{
    data.insert(data.begin(), valueArray, valueArray + arraySize);
}

VectorStackImplementation::VectorStackImplementation(const VectorStackImplementation& copyStack)
{
    if (this == &copyStack)
    {
        return;
    }
    data.clear();
    data.insert(data.begin(), copyStack.data.begin(), copyStack.data.end());
}
VectorStackImplementation& VectorStackImplementation::operator=(const VectorStackImplementation& copyStack)
{
    if (this == &copyStack)
    {
        return *this;
    }
    data.clear();
    data.insert(data.begin(), copyStack.data.begin(), copyStack.data.end());
    return *this;
}

VectorStackImplementation::VectorStackImplementation(VectorStackImplementation&& moveStack) noexcept
{
    if (this == &moveStack)
    {
        return;
    }
    data.clear();
    data.insert(data.begin(), moveStack.data.begin(), moveStack.data.end());
    moveStack.data.clear();
}
VectorStackImplementation& VectorStackImplementation::operator=(VectorStackImplementation&& moveStack) noexcept
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


void VectorStackImplementation::push(const ValueType& value)
{
    data.push_back(value);
}
void VectorStackImplementation::pop()
{
    data.pop_back();
}
const ValueType& VectorStackImplementation::top() const
{
    return data[data.size()-1];
}
bool VectorStackImplementation::isEmpty() const
{
    if (data.size() <= 0)
    {
        return true;
    }
    return false;
}
size_t VectorStackImplementation::size() const
{
    return data.size();
}

void VectorStackImplementation::clear()
{
    data.clear();
}
void VectorStackImplementation::reverse()
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
        data.push_back(arr[i]);
    }
}

VectorStackImplementation* VectorStackImplementation::clone() const
{
    return new VectorStackImplementation(*this);
}