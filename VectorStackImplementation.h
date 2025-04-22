#pragma once

#include <iostream>
#include <vector>
#include "StackImplementation.h"


class VectorStackImplementation : public IStackImplementation
{
public:
    VectorStackImplementation();
    VectorStackImplementation(const ValueType* valueArray, const size_t arraySize);

    VectorStackImplementation(const VectorStackImplementation& copyStack);
    VectorStackImplementation& operator=(const VectorStackImplementation& copyStack);

    VectorStackImplementation(VectorStackImplementation&& moveStack) noexcept;
    VectorStackImplementation& operator=(VectorStackImplementation&& moveStack) noexcept;

    ~VectorStackImplementation() = default;


    void push(const ValueType& value) override;
    void pop() override;
    const ValueType& top() const override;
    bool isEmpty() const override;
    size_t size() const override;
    void clear() override;
    void reverse() override;
    VectorStackImplementation* clone() const override;
private:
    std::vector<ValueType> data;
};