#pragma once

#include <exception>

using namespace std;

class MyException : public exception
{
public:
    MyException(const char* str) : exception(str)
    {
    }
};