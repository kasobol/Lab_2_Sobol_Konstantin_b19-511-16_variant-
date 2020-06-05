#pragma once

#include <iostream>

#include "LinkedListSequence.h"

#include "MyException.h";

using namespace std;

template<class T>
class Dec
{
private:
    Sequence<T> *items;
public:
    Sequence<T>* Get_Items()
    {
        return items;
    }
    Dec(Sequence<T> *items)
    {
        this->items = items;
    }
public:
    int GetLength()
    {
        return items->GetLength();
    }
    T Get(int index)
    {
        return items->Get(index);
    }
    void PushBack(T item)
    {
        items->Prepend(item);
    }
    void PushFront(T item)
    {
        items->Append(item);
    }
    T PopBack()
    {
        return items->GetLast();
    }
    T PopFront()
    {
        return items->GetFirst();
    }
    bool IsEmpty()
    {
        if (items->GetLength() == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void Clear()
    {
        delete items;
        items = new LinkedListSequence();
    }
public:
    void Sort()
    {
        if (items->GetLength() == 0)
        {
            throw MyException("Sort: Dec is empty");
        }
        int n = items->GetLength();
        int j = 1;
        while (true)
        {
            for (int i = 0; i < n - j; i++)
            {
                T a = items->Get(i);
                T b = items->Get(i + 1);
                if (a > b)
                {
                    items->InsertAt(a, i + 1);
                    items->InsertAt(b, i);
                }
            }
            j++;
            if (j == n)
            {
                break;
            }
        }
    }
    Dec<T>* Map(T(*fptr)(T))
    {
        if (items->GetLength() == 0)
        {
            throw MyException("Map: Dec is empty");
        }
        Sequence<T> *res = new LinkedListSequence<T>();
        for (int i = 0; i < items->GetLength(); i++)
        {
            res->Prepend(fptr(items->Get(i)));
        }
        Dec<T> *dec_res = new Dec<T>(res);
        return dec_res;
    }
    Dec<T>* Where(bool(*fptr)(T))
    {
        if (items->GetLength() == 0)
        {
            throw MyException("Where: Dec is empty");
        }
        Sequence<T> *res = new LinkedListSequence<T>();
        for (int i = 0; i < items->GetLength(); i++)
        {
            bool check = fptr(items->Get(i));
            if (check)
            {
                res->Prepend(items->Get(i));
            }
        }
        Dec<T> *dec_res = new Dec<T>(res);
        return dec_res;
    }
    T Reduce(T(*fptr)(T, T), T item)
    {
        if (items->GetLength() == 0)
        {
            throw MyException("Reduce: Dec is empty");
        }
        T res = fptr(items->Get(0), item);
        for (int i = 1; i < items->GetLength(); i++)
        {
            res = fptr(items->Get(i), res);
        }
        return res;
    }
    Dec<T>* Concat(Dec<T> *dec)
    {
        Dec<T> *res = new Dec(items->Concat(dec->Get_Items()));
        return res;

    }
    Dec<T>* GetSubDec(int startIndex, int endIndex)
    {
        Dec<T> *res = new Dec(items->GetSubsequence(startIndex, endIndex));
        return res;
    }

    void Show()
    {
        for (int i = 0; i < items->GetLength(); i++)
        {
            cout << items->Get(i) << endl;
        }
    }

    ~Dec()
    {
        delete items;
    }
};
