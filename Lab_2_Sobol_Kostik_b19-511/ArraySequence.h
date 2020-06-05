#pragma once

#include "Sequence.h"
#include "DynamicArray.h"
#include "MyException.h"

using namespace std;

template <class T>
class ArraySequence : public Sequence<T>
{
private:
    DynamicArray<T> *items;
public:
    
    ArraySequence(T* items, int count)
    {
        items = new DynamicArray<T>(items, count);
    }
    ArraySequence(int size)
    {
        items = new DynamicArray<T>(size);
    }
    ArraySequence(const DynamicArray<T> &dynamicArray)
    {
        items->DynamicArray(dynamicArray);
    }
public:
    T GetFirst() override
    {
        throw MyException("Don't use ArraySequence");
    }
    T GetLast() override
    {
        throw MyException("Don't use ArraySequence");
    }
    T Get(int index) override
    {
        return items->Get(index);
    }
    Sequence<T>* GetSubsequence(int startIndex, int endIndex) override
    {
        int newSize = endIndex - startIndex + 1;
        T *mas = new T[newSize];
        for (int i = startIndex, j = 0; i <= endIndex; i++, j++)
        {
            mas[j] = items->items[i];
        }
        auto *res = new ArraySequence(mas, newSize);
        return res;
    }
    int GetLength()
    {
        items->GetSize();
    }
public:
    void Append(T item) override
    {
        throw MyException("Don't use ArraySequence");
    }
    void Prepend(T item) override
    {
        throw MyException("Don't use ArraySequence");
    }
    void InsertAt(T item, int index) override
    {
        throw MyException("Don't use ArraySequence");
    }
    Sequence <T>* Concat(Sequence <T> *list) override
    {
        throw MyException("Don't use ArraySequence");
    }

    ~ArraySequence()
    {
        delete items;
    }
};