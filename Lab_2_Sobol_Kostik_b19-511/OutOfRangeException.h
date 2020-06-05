#pragma once

#include <exception>

using namespace std;

class IndexOutOfRange : public exception
{
public:
    IndexOutOfRange(const char* str) : exception(str)
    {
    }
};
