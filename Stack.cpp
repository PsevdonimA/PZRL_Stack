#include <iostream>
#include "Stack.h"
#include "VectorStackImplementation.h"
#include "ListStackImplementation.h"


IStackImplementation* create_stack(StackContainer container)
{
    if (container == StackContainer::Vector)
    {
        return new VectorStackImplementation();
    }
    else if (container == StackContainer::List)
    {
        return new ListStackImplementation();
    }
    return nullptr;
}


Stack::Stack(StackContainer container)
{
    _containerType = container;
    _pimpl = create_stack(_containerType);
}

Stack::Stack(const ValueType* valueArray, const size_t arraySize, StackContainer container)
{
    _containerType = container;
    _pimpl = create_stack(_containerType);
    for (size_t i = 0; i < arraySize; i++)
    {
        _pimpl->push(valueArray[i]);
    }
}

Stack::Stack(const Stack& copyStack)
{
    if (this == &copyStack)
    {
        return;
    }
    if (_pimpl == nullptr)
    {
        _pimpl = create_stack(copyStack.getContainerType());
    }
    auto ptr = copyStack._pimpl->clone();
    ptr->reverse();
    _pimpl->clear();
    size_t n = ptr->size();
    for (size_t i = 0; i < n; i++)
    {
        _pimpl->push(ptr->top());
        ptr->pop();
    }
    delete ptr;
}
Stack& Stack::operator=(const Stack& copyStack)
{
    if (this == &copyStack)
    {
        return *this;
    }
    auto ptr = copyStack._pimpl->clone();
    ptr->reverse();
    _pimpl->clear();
    size_t n = ptr->size();
    for (size_t i = 0; i < n; i++)
    {
        _pimpl->push(ptr->top());
        ptr->pop();
    }
    delete ptr;
    return *this;
}

Stack::Stack(Stack&& moveStack) noexcept
{
    if (this == &moveStack)
    {
        return;
    }
    auto ptr = moveStack._pimpl->clone();
    moveStack._pimpl->clear();
    ptr->reverse();
    _pimpl->clear();
    size_t n = ptr->size();
    for (size_t i = 0; i < n; i++)
    {
        _pimpl->push(ptr->top());
        ptr->pop();
    }
    delete ptr;
}
Stack& Stack::operator=(Stack&& moveStack) noexcept
{
    if (this == &moveStack)
    {
        return *this;
    }
    auto ptr = moveStack._pimpl->clone();
    moveStack._pimpl->clear();
    ptr->reverse();
    _pimpl->clear();
    size_t n = ptr->size();
    for (size_t i = 0; i < n; i++)
    {
        _pimpl->push(ptr->top());
        ptr->pop();
    }
    delete ptr;
    return *this;
}

Stack::~Stack()
{
    delete _pimpl;
}

// добавление в хвост
void Stack::push(const ValueType& value)
{
    _pimpl->push(value);
}
// удаление с хвоста
void Stack::pop()
{
    _pimpl->pop();
}
// посмотреть элемент в хвосте
const ValueType& Stack::top() const
{
    return _pimpl->top();
}
// проверка на пустоту
bool Stack::isEmpty() const
{
    return _pimpl->isEmpty();
}
// размер 
size_t Stack::size() const
{
    return _pimpl->size();
}

StackContainer Stack::getContainerType() const
{
    return _containerType;
}