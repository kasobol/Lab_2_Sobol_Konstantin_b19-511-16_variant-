#include "LinkedListSequence.h"

#include <exception>
#include <stdexcept>
#include <string>

template <class T> 
class LinkedListSequence : public Sequence<T>
{
private:
    LinkedList<T> *list;
public:
    LinkedListSequence(T* items, int count)
    {
        list = new LinkedList(items, count);
    }
    LinkedListSequence()
    {
        list = new LinkedList();
    }
    LinkedListSequence(const LinkedList<T> &list)
    {
        list = new LinkedList(list);
    }
public:
    T GetFirst() override
    {
        list->GetFirst();
    }
    T GetLast() override
    {
        list->GetLast();
    }
    T Get(int index) override
    {
        list->Get(index);
    }
    Sequence<T>* GetSubsequence(int startIndex, int endIndex) override
    {
        list->GetSubList(startIndex, endIndex);
    }
    int GetLength() override
    {
        list->GetLength();
    }
public:
    void Append(T item) override
    {
        list->Append(item);
    }
    void Prepend(T item) override
    {
        list->Prepend(item);
    }
    void InsertAt(T item, int index) override
    {
        list->InsertAt(item, index);
    }
    Sequence <T>* Concat(Sequence <T> *list) override
    {
        this->list->Concat(list);
    }

    ~LinkedListSequence()
    {
        items;
    }
};