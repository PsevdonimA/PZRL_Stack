#pragma once

#include <iostream>
#include <list>
#include "StackImplementation.h"


class ListStackImplementation : public IStackImplementation
{
public:
    ListStackImplementation();
    ListStackImplementation(const ValueType* valueArray, const size_t arraySize);

    ListStackImplementation(const ListStackImplementation& copyStack);
    ListStackImplementation& operator=(const ListStackImplementation& copyStack);

    ListStackImplementation(ListStackImplementation&& moveStack) noexcept;
    ListStackImplementation& operator=(ListStackImplementation&& moveStack) noexcept;

    ~ListStackImplementation() = default;


    void push(const ValueType& value) override;
    void pop() override;
    const ValueType& top() const override;
    bool isEmpty() const override;
    size_t size() const override;
    void clear() override;
    void reverse() override;
    ListStackImplementation* clone() const override;
private:
    std::list<ValueType> data;
};