#pragma once

#include "OutOfRangeException.h"

using namespace std;

template<class T>
class DynamicArray
{
private:
    T* items;
    int size;
public:
    DynamicArray(T* items, int count)
    {
        int oldSize = size;
        Resize(size + count);
        for (int i = oldSize, j = 0; i < size; i++, j++)
        {
            this->items[i] = items[j];
        }
    }
    DynamicArray(int size)
    {
        items = new T[size];
        this->size = size;
    }
    DynamicArray(DynamicArray<T> &dynamicArray)
    {
        size = dynamicArray.size;
        items = new T[size];
        for (int i = 0; i < size; i++)
        {
            items[i] = dynamicArray.items[i];
        }
    }
public:
    T Get(int i)
    {
        try
        {
            if (i < 0)
            {
                throw IndexOutOfRange("Negative index");
            }
            if (i >= size)
            {
                throw IndexOutOfRange("Index out of range");
            }
        }
        catch (IndexOutOfRange &ex)
        {
            cout << "Error: " << ex.what() << endl;
        }
    }
    int GetSize()
    {
        return size;
    }
public:
    void Set(int index, T value)
    {
        if (index < 0)
        {
            throw IndexOutOfRange("Negative value");
        }
        if (index >= size)
        {
            throw IndexOutOfRange("Index out of range");
        }
        items[index] = value;
    }
    void Resize(int newSize)
    {
        if (newSize == size)
        {
            return;
        }
        if (newSize > size)
        {
            T* help = new T[newSize];
            for (int i = 0; i < size; i++)
            {
                help[i] = items[i];
            }
            items = help;
            delete help;
            return;
        }
        if (newSize < size)
        {
            size = newSize;
        }
    }

    ~DynamicArray()
    {
        delete items;
    }
};
