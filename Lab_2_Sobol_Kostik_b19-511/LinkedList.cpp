#include "LinkedList.h"

#include <exception>
#include <stdexcept>
#include <string>

using namespace std;

template<class T>
class LinkedList
{
private:
    struct List
    {
        T info;
        List* next;
    };
    List *head, *tail;
    int size;
public:
    LinkedList(T* items, int count)
    {
        if (size == 0)
        {
            head->info = items[0];
            head->next = nullptr;
            tail = head;
            for (int i = 1; i < count; i++)
            {
                tail->next = new List(items[i], nullptr);
                tail = tail->next;
            }
            size = count;
        }
        else
        {
            for (int i = 0; i < count; i++)
            {
                tail->next = new List(item[i], nullptr);
                tail = tail->next;
            }
            size += count;
        }
    }
    LinkedList()
    {
        size = 0;
        head = nullptr;
        tail = head;
    }
    LinkedList(const LinkedList<T> &list)
    {
        size = list.size;
        List *tmp = list.head;
        while (tmp != nullptr)
        {
            Prepend(tmp->info);
            tmp = tmp->next;
        }
    }
public:
    T GetFirst()
    {
        if (size == 0)
        {
            throw IndexOutOfRange("The list is empty");
        }
        return head->info;
    }
    T GetLast()
    {
        if (size == 0)
        {
            throw IndexOutOfRange("The list is empty");
        }
        return tail->info;
    }
    T Get(int index)
    {
        if (index < 0)
        {
            throw IndexOutOfRange("Negative index");
        }
        if (index >= size)
        {
            throw IndexOutOfRange("Index out of range");
        }
        List *tmp = head;
        for (int i = 0; i != index; i++)
        {
            tmp = tmp->next;
        }
        return tmp->info;
    }
    LinkedList<T>* GetSubList(int startIndex, int endIndex)
    {
        if (startIndex < 0 || endIndex < 0)
        {
            throw IndexOutOfRange("Negative index");
        }
        if (startIndex >= size || endIndex >= size)
        {
            throw IndexOutOfRange("Index out of range");
        }

        int resSize = endIndex - startIndex + 1;
        T mas[resSize];
        for (int i = startIndex, int j = 0; i <= endIndex; i++, j++)
        {
            T[j] = Get(i);
        }

        LinkedList<T> *res = new LinkedList(mas, resSize);
        return res;
    }
    int GetLength()
    {
        return size;
    }
public:
    void Append(T item)
    {
        size++;
        List *tmp = new(item, head);
        head = tmp;
    }
    void Prepend(T item)
    {
        size++;
        List *tmp = new List(item, nullptr);
        tail->next = tmp;
        tail = tmp;
    }
    void InsertAt(T item, int index)
    {
        if (index < 0)
        {
            throw IndexOutOfRange("Negative index");
        }
        if (index >= size)
        {
            throw IndexOutOfRange("Index out of range");
        }
        List tmp = head;
        for (int i = 0; i != index; i++)
        {
            tmp = tmp->next;
        }
        tmp->info = item;
    }
    LinkedList<T>* Concat(LinkedList<T> *list)
    {
        LinkedList<T> *res = new LinkedList();
        res->size = size + list->size;
        res->head = head;
        res->tail = tail;
        res->tail->next = list->head;
        res->tail = list->tail;

        return res;
    }
};

class IndexOutOfRange : exception
{
public:
    IndexOutOfRange(char* str) : exception(str)
    {
    }
};