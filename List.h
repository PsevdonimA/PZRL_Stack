#pragma once

#include <stdlib.h>
#include "Stack.h"

class Node;

class List
{
public:
    List() = default;
    List(const ValueType* rawArray, const size_t size);
    explicit List(const List& other);
    List& operator=(const List& other);
    explicit List(List&& other) noexcept;
    List& operator=(List&& other) noexcept;
    ~List();

    void pushBack(const ValueType& value);
    void pushFront(const ValueType& value);

    void insert(const ValueType& value, size_t pos);
    void insert(const ValueType* values, size_t size, size_t pos);
    void insert(const List& List, size_t pos);

    void popBack();
    void popFront();

    void erase(size_t pos, size_t count = 1);
    void clear();

    void eraseBetween(size_t beginPos, size_t endPos);

    size_t size() const;

    ValueType& operator[](size_t idx);
    const ValueType& operator[](size_t idx) const;

    long long find(const ValueType& value) const;
private:
    Node* _data = nullptr;
    size_t _size = 0;
};

class Node
{
public:
    friend List;
private:
    Node(const ValueType& value) : data(value) {}
    ~Node()
    {
        delete next;
    }

    Node* next = nullptr;
    ValueType data;
};