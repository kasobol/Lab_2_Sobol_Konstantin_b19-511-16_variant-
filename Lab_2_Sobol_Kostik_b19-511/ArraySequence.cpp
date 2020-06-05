#include "ArraySequence.h"

#include <exception>
#include <stdexcept>
#include <string>

template <class T>
class ArraySequence : public Sequence<T>
{
private:
    DynamicArray<T> *items;
public:
    ArraySequence(T* items, int count)
    {
        items = new DynamicArray(items, count);
    }
    //ArraySequence();
    ArraySequence(const DynamicArray<T> &dynamicArray)
    {
        items->DynamicArray(DynamicArray);
    }
public:
    T GetFirst() override
    {

    }
    T GetLast() override
    {

    }
    T Get(int index) override
    {
        return items->Get(index);
    }
    Sequence<T>* GetSubsequence(int startIndex, int endIndex) override
    {
        int newSize = endIndex - startIndex + 1;
        T *mas = new T[newSize];
        for (int i = startIndex, int j = 0; i <= endIndex; i++, j++)
        {
            mas[j] = items->items[i];
        }
        auto *res = new ArraySequence(mas, newSize);
        retu res;
    }
    int GetLength()
    {
        items->GetSize();
    }
public:
    void Append(T item) override
    {
        
    }
    void Prepend(T item) override
    {

    }
    void InsertAt(T item, int index) override
    {

    }
    Sequence <T>* Concat(Sequence <T> *list) override
    {

    }
};