#include <iostream>
#include "List.h"

List::List(const ValueType* rawArray, const size_t size)
{
    if (rawArray != nullptr)
    {
        for (size_t i = 0; i < size; i++)
        {
            pushBack(rawArray[i]);
        }
    }
    else
    {
        _data = nullptr;
        _size = 0;
    }
}

List::List(const List& other)
{
    for (size_t i = 0; i < other._size; i++)
    {
        pushBack(other[i]);
    }
}

List& List::operator=(const List& other)
{
    if (this == &other)
    {
        return *this;
    }
    clear();
    for (size_t i = 0; i < other._size; i++)
    {
        pushBack(other[i]);
    }
    return *this;
}

List::List(List&& other) noexcept
{
    for (size_t i = 0; i < other._size; i++)
    {
        pushBack(other[i]);
    }
    other.clear();
}

List& List::operator=(List&& other) noexcept
{
    if (this == &other)
    {
        return *this;
    }
    clear();
    for (size_t i = 0; i < other._size; i++)
    {
        pushBack(other[i]);
    }
    other.clear();
    return *this;
}

List::~List()
{
    clear();
}

void List::pushBack(const ValueType& value)
{
    Node* newnode = new Node(value);
    if (_size > 0)
    {
        Node* fnd = _data;
        for (size_t i = 0; i < _size-1; i++)
        {
            fnd = fnd->next;
        }
        fnd->next = newnode;
    }
    else
    {
        _data = newnode;
    }
    _size++;
}

void List::pushFront(const ValueType& value)
{
    Node* newnode = new Node(value);
    if (_size > 0)
    {
        Node* nxt = _data;
        _data = newnode;
        newnode->next = _data;
    }
    else
    {
        _data = newnode;
    }
    _size++;
}

void List::insert(const ValueType& value, size_t pos)
{
    if (pos > _size)
    {
        throw std::invalid_argument("Cannot insert value: position must be lesser than size.");
    }
    else if (pos < 0)
    {
        throw std::invalid_argument("Cannot insert value: position cannot be negative.");
    }
    if (pos == 0)
    {
        pushFront(value);
    }
    else if (pos == _size)
    {
        pushBack(value);
    }
    else
    {
        Node* newnode = new Node(value);
        Node* fnd = _data;
        for (size_t i = 0; i < pos-1; i++)
        {
            fnd = fnd->next;
        }
        newnode->next = fnd->next;
        fnd->next = newnode;
        _size++;
    }
}

void List::insert(const ValueType* values, size_t size, size_t pos)
{
    if (size <= 0)
    {
        throw std::invalid_argument("Cannot insert values: length of array must be greater than 0.");
    }
    else if (pos > _size)
    {
        throw std::invalid_argument("Cannot insert values: position must be lesser than size.");
    }
    else if (pos < 0)
    {
        throw std::invalid_argument("Cannot insert values: position cannot be negative.");
    }
    else if (values == nullptr)
    {
        throw std::invalid_argument("Cannot insert values: pointer must not be null.");
    }
    for (int i = size - 1; i >= 0; i--)
    {
        insert(values[i], pos);
    }
}

void List::insert(const List& list, size_t pos)
{
    if (pos > _size)
    {
        throw std::invalid_argument("Cannot insert List: position must be lesser than size.");
    }
    else if (pos < 0)
    {
        throw std::invalid_argument("Cannot insert List: position cannot be negative.");
    }
    size_t cur_pos = pos;
    for (size_t i = 0; i < list._size; i++)
    {
        insert(list[i], cur_pos);
        cur_pos++;
    }
}

void List::popBack()
{
    if (_size == 0)
    {
        return;
    }
    else if (_size == 1)
    {
        delete _data;
        _data = nullptr;
        _size = 0;
        return;
    }
    Node* fnd = _data;
    for (size_t i = 0; i < _size - 2; i++)
    {
        fnd = fnd->next;
    }
    delete fnd->next;
    fnd->next = nullptr;
    _size--;
}

void List::popFront()
{
    if (_size == 0)
    {
        return;
    }
    Node* fnd = _data->next;
    delete _data;
    _data = fnd;
    _size--;
}

void List::erase(size_t pos, size_t count)
{
    if (pos >= _size)
    {
        return;
    }
    else if (pos < 0)
    {
        return;
    }
    else if (count < 0)
    {
        return;
    }
    if (pos == 0)
    {
        for (size_t i = 0; i < count; i++)
        {
            popFront();
        }
    }
    else
    {
        Node* fnd = _data;
        for (size_t i = 0; i < pos-1; i++)
        {
            fnd = fnd->next;
        }
        for (size_t i = 0; i < count; i++)
        {
            Node* dlnd = fnd->next;
            fnd->next = dlnd->next;
            delete dlnd;
            _size--;
            if (fnd->next == nullptr)
            {
                break;
            }
        }
    }
}

void List::clear()
{
    if (_size == 0)
    {
        return;
    }
    erase(0, _size);
    _size = 0;
}

void List::eraseBetween(size_t beginPos, size_t endPos)
{
    if (beginPos < 0 || beginPos >= endPos)
    {
        throw std::invalid_argument("Cannot erase elements: positions incorrect.");
    }
    erase(beginPos, endPos - beginPos);
}

size_t List::size() const
{
    return _size;
}

ValueType& List::operator[](size_t idx)
{
    if (_size == 0)
    {
        throw std::invalid_argument("Cannot get element: size of List is 0.");
    }
    size_t _idx = idx;
    _idx = _idx % _size;
    Node* nd = _data;
    for (size_t i = 0; i < _idx; i++)
    {
        nd = nd->next;
    }
    return nd->data;
}

const ValueType& List::operator[](size_t idx) const
{
    if (_size == 0)
    {
        throw std::invalid_argument("Cannot get element: size of List is 0.");
    }
    size_t _idx = idx;
    _idx = _idx % _size;
    Node* nd = _data;
    for (size_t i = 0; i < _idx; i++)
    {
        nd = nd->next;
    }
    return nd->data;
}

long long List::find(const ValueType& value) const
{
    long long idx = -1;
    Node* nd = _data;
    for (size_t i = 0; i < _size; i++)
    {
        if (nd->data == value)
        {
            idx = (long long)i;
            break;
        }
        nd = nd->next;
    }
    return idx;
}
