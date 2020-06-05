#pragma once

#include <complex>
#include <string>

#include "Dec.h"
#include "LinkedListSequence.h"
#include "ArraySequence.h"

using namespace std;

bool operator >(const complex<double> a1, const complex<double> a2)
{
    if (a1.real() * a1.real() + a1.imag() * a1.imag() > a2.real() * a2.real() + a2.imag() * a2.imag())
    {
        return true;
    }
    return false;
}

template<class T>
int Equal_Decs(Dec<T> *dec1, Dec<T> *dec2)
{
    Sequence<T> *list1 = dec1->Get_Items();
    Sequence<T> *list2 = dec2->Get_Items();

    if (list1->GetLength() != list2->GetLength())
    {
        return 0;
    }

    for (int i = 0; i < list1->GetLength(); i++)
    {
        if (list1->Get(i) != list2->Get(i))
        {
            return 0;
        }
    }
    return 1;
}

void Test_Sort()
{
    int check = 0;
    int i = 0;

    Dec<string> *dec_str = new Dec<string>(new LinkedListSequence<string>(new string[5]{ "bca", "abc", "srdg", "qwew", "peihrt" }, 5));
    Dec<string> *dec_str_sort = new Dec<string>(new LinkedListSequence<string>(new string[5]{ "abc", "bca", "peihrt", "qwew", "srdg" }, 5));
    dec_str->Sort();
    check += Equal_Decs<string>(dec_str, dec_str_sort);
    i++;

    dec_str = new Dec<string>(new LinkedListSequence<string>(new string[5]{ "e", "d", "c", "b", "a" }, 5));
    dec_str_sort = new Dec<string>(new LinkedListSequence<string>(new string[5]{ "a", "b", "c", "d", "e" }, 5));
    dec_str->Sort();
    check += Equal_Decs<string>(dec_str, dec_str_sort);
    i++;

    dec_str = new Dec<string>(new LinkedListSequence<string>(new string[5]{ "", "dasffsad", "fadsf", "wqrr", "" }, 5));
    dec_str_sort = new Dec<string>(new LinkedListSequence<string>(new string[5]{ "", "", "dasffsad", "fadsf", "wqrr" }, 5));
    dec_str->Sort();
    check += Equal_Decs<string>(dec_str, dec_str_sort);
    i++;

    Dec<double> *dec_double = new Dec<double>(new LinkedListSequence<double>(new double[6]{ 6, 5, 4, 3, 2, 1 }, 6));
    Dec<double> *dec_double_sort = new Dec<double>(new LinkedListSequence<double>(new double[6]{ 1, 2, 3, 4, 5, 6 }, 6));
    dec_double->Sort();
    check += Equal_Decs<double>(dec_double, dec_double_sort);
    i++;

    dec_double = new Dec<double>(new LinkedListSequence<double>(new double[6]{ 2133, 645, 90654878, 0, -13244, -1 }, 6));
    dec_double_sort = new Dec<double>(new LinkedListSequence<double>(new double[6]{ -13244, -1, 0, 645, 2133, 90654878 }, 6));
    dec_double->Sort();
    check += Equal_Decs<double>(dec_double, dec_double_sort);
    i++;

    dec_double = new Dec<double>(new LinkedListSequence<double>(new double[6]{ -1.001, -1.002, -1.0009, -2.123, 0, -3.987}, 6));
    dec_double_sort = new Dec<double>(new LinkedListSequence<double>(new double[6]{ -3.987, -2.123, -1.002, -1.001, -1.0009, 0 }, 6));
    dec_double->Sort();
    check += Equal_Decs<double>(dec_double, dec_double_sort);
    i++;

    Dec<complex<double>> *dec_complex = new Dec<complex<double>>(new LinkedListSequence<complex<double>>(new complex<double>[4]{ {5, 6}, {6, 5}, {1, 2}, {10, 9} }, 4));
    Dec<complex<double>> *dec_complex_sort = new Dec<complex<double>>(new LinkedListSequence<complex<double>>(new complex<double>[4]{ {1, 2}, {5, 6}, {6, 5}, {10, 9} }, 4));
    dec_complex->Sort();
    check += Equal_Decs<complex<double>>(dec_complex, dec_complex_sort);
    i++;

    dec_complex = new Dec<complex<double>>(new LinkedListSequence<complex<double>>(new complex<double>[4]{ {0, 1}, {0, 1}, {1, 2}, {4.65, 5.214} }, 4));
    dec_complex_sort = new Dec<complex<double>>(new LinkedListSequence<complex<double>>(new complex<double>[4]{ {0, 1}, {0, 1}, {1, 2}, {4.65, 5.214} }, 4));
    dec_complex->Sort();
    check += Equal_Decs<complex<double>>(dec_complex, dec_complex_sort);
    i++;

    dec_complex = new Dec<complex<double>>(new LinkedListSequence<complex<double>>(new complex<double>[4]{ {-2, -2}, {1, 1}, {-1, -1}, {0, 0} }, 4));
    dec_complex_sort = new Dec<complex<double>>(new LinkedListSequence<complex<double>>(new complex<double>[4]{ {0, 0}, {1, 1}, {-1, -1}, {-2, -2} }, 4));
    dec_complex->Sort();
    check += Equal_Decs<complex<double>>(dec_complex, dec_complex_sort);
    i++;

    if (check == i)
    {
        cout << "Test_Sort: GOOD" << endl;
    }
    else
    {
        cout << "Test_Sort: FAIL" << endl;
    }
}

string func_for_Map(string a)
{
    a = a + "_Map_oooo";
    return a;
}
double func_for_Map(double a)
{
    a += 1.999999;
    return a;
}
complex<double> func_for_Map(complex<double> a)
{
    a = a + complex<double>(1.99999, 1.00001);
    return a;
}

void Test_Map()
{
    int check = 0;
    int i = 0;

    string str = "_Map_oooo";

    Dec<string> *dec_str = new Dec<string>(new LinkedListSequence<string>(new string[5]{ "bca", "abc", "srdg", "qwew", "peihrt" }, 5));
    Dec<string> *dec_str_map = new Dec<string>(new LinkedListSequence<string>(new string[5]{ "bca" + str, "abc" + str, "srdg" + str, "qwew" + str, "peihrt" + str }, 5));
    dec_str = dec_str->Map(func_for_Map);
    check += Equal_Decs<string>(dec_str, dec_str_map);
    i++;

    dec_str = new Dec<string>(new LinkedListSequence<string>(new string[5]{ "e", "d", "c", "b", "a" }, 5));
    dec_str_map = new Dec<string>(new LinkedListSequence<string>(new string[5]{ "e" + str, "d" + str, "c" + str, "b" + str, "a" + str }, 5));
    dec_str = dec_str->Map(func_for_Map);
    check += Equal_Decs<string>(dec_str, dec_str_map);
    i++;

    dec_str = new Dec<string>(new LinkedListSequence<string>(new string[5]{ "", "dasffsad", "fadsf", "wqrr", "" }, 5));
    dec_str_map = new Dec<string>(new LinkedListSequence<string>(new string[5]{ "" + str, "dasffsad" + str, "fadsf" + str, "wqrr" + str, "" + str }, 5));
    dec_str = dec_str->Map(func_for_Map);
    check += Equal_Decs<string>(dec_str, dec_str_map);
    i++;

    double num = 1.999999;

    Dec<double> *dec_double = new Dec<double>(new LinkedListSequence<double>(new double[6]{ 6, 5, 4, 3, 2, 1 }, 6));
    Dec<double> *dec_double_map = new Dec<double>(new LinkedListSequence<double>(new double[6]{ 6 + num, 5 + num, 4 + num, 3 + num, 2 + num, 1 + num }, 6));
    dec_double = dec_double->Map(func_for_Map);
    check += Equal_Decs<double>(dec_double, dec_double_map);
    i++;

    dec_double = new Dec<double>(new LinkedListSequence<double>(new double[6]{ 2133, 645, 90654878, 0, -13244, -1 }, 6));
    dec_double_map = new Dec<double>(new LinkedListSequence<double>(new double[6]{ 2133 + num, 645 + num, 90654878 + num, 0 + num, -13244 + num, -1 + num }, 6));
    dec_double = dec_double->Map(func_for_Map);
    check += Equal_Decs<double>(dec_double, dec_double_map);
    i++;

    dec_double = new Dec<double>(new LinkedListSequence<double>(new double[6]{ -1.001, -1.002, -1.0009, -2.123, 0, -3.987 }, 6));
    dec_double_map = new Dec<double>(new LinkedListSequence<double>(new double[6]{ -1.001 + num, -1.002 + num, -1.0009 + num, -2.123 + num, 0 + num, -3.987 + num }, 6));
    dec_double = dec_double->Map(func_for_Map);
    check += Equal_Decs<double>(dec_double, dec_double_map);
    i++;

    complex<double> com = { 1.99999, 1.00001 };

    Dec<complex<double>> *dec_complex = new Dec<complex<double>>(new LinkedListSequence<complex<double>>(new complex<double>[4]{ {5, 6}, {6, 5}, {1, 2}, {10, 9} }, 4));
    Dec<complex<double>> *dec_complex_map = new Dec<complex<double>>(new LinkedListSequence<complex<double>>(new complex<double>[4]{ complex<double>(5, 6) + com, complex<double>(6, 5) + com, complex<double>(1, 2) + com, complex<double>(10, 9) + com }, 4));
    dec_complex = dec_complex->Map(func_for_Map);
    check += Equal_Decs<complex<double>>(dec_complex, dec_complex_map);
    i++;

    dec_complex = new Dec<complex<double>>(new LinkedListSequence<complex<double>>(new complex<double>[4]{ {0, 1}, {0, 1}, {1, 2}, {4.65, 5.214} }, 4));
    dec_complex_map = new Dec<complex<double>>(new LinkedListSequence<complex<double>>(new complex<double>[4]{ complex<double>(0, 1) + com, complex<double>(0, 1) + com, complex<double>(1, 2) + com, complex<double>(4.65, 5.214) + com }, 4));
    dec_complex = dec_complex->Map(func_for_Map);
    check += Equal_Decs<complex<double>>(dec_complex, dec_complex_map);
    i++;

    dec_complex = new Dec<complex<double>>(new LinkedListSequence<complex<double>>(new complex<double>[4]{ {-2, -2}, {1, 1}, {-1, -1}, {0, 0} }, 4));
    dec_complex_map = new Dec<complex<double>>(new LinkedListSequence<complex<double>>(new complex<double>[4]{ complex<double>(-2, -2) + com, complex<double>(1, 1) + com, complex<double>(-1, -1) + com, complex<double>(0, 0) + com }, 4));
    dec_complex = dec_complex->Map(func_for_Map);
    check += Equal_Decs<complex<double>>(dec_complex, dec_complex_map);
    i++;

    if (check == i)
    {
        cout << "Test_Map: GOOD" << endl;
    }
    else
    {
        cout << "Test_Map: FAIL" << endl;
    }
}

bool func_for_Where(string a)
{
    if (a.length() == 4)
    {
        return true;
    }
    return false;
}
bool func_for_Where(double a)
{
    if (a > 4)
    {
        return true;
    }
    return false;
}
bool func_for_Where(complex<double> a)
{
    if (a.imag() > 4)
    {
        return true;
    }
    return false;
}

void Test_Where()
{
    int check = 0;
    int i = 0;

    Dec<string> *dec_str = new Dec<string>(new LinkedListSequence<string>(new string[5]{ "bca", "abc", "srdg", "qwew", "peihrt" }, 5));
    Dec<string> *dec_str_where = new Dec<string>(new LinkedListSequence<string>(new string[2]{ "srdg", "qwew" }, 2));
    dec_str = dec_str->Where(func_for_Where);
    check += Equal_Decs<string>(dec_str, dec_str_where);
    i++;

    dec_str = new Dec<string>(new LinkedListSequence<string>(new string[5]{ "e", "d", "c", "b", "a" }, 5));
    dec_str_where = new Dec<string>(new LinkedListSequence<string>());
    dec_str = dec_str->Where(func_for_Where);
    check += Equal_Decs<string>(dec_str, dec_str_where);
    i++;

    dec_str = new Dec<string>(new LinkedListSequence<string>(new string[5]{ "", "dasffsad", "fadsf", "wqrr", "" }, 5));
    dec_str_where = new Dec<string>(new LinkedListSequence<string>(new string[1]{ "wqrr" }, 1));
    dec_str = dec_str->Where(func_for_Where);
    check += Equal_Decs<string>(dec_str, dec_str_where);
    i++;

    Dec<double> *dec_double = new Dec<double>(new LinkedListSequence<double>(new double[6]{ 6, 5, 4, 3, 2, 1 }, 6));
    Dec<double> *dec_double_where = new Dec<double>(new LinkedListSequence<double>(new double[2]{ 6, 5 }, 2));
    dec_double = dec_double->Where(func_for_Where);
    check += Equal_Decs<double>(dec_double, dec_double_where);
    i++;

    dec_double = new Dec<double>(new LinkedListSequence<double>(new double[6]{ 2133, 645, 90654878, 0, -13244, -1 }, 6));
    dec_double_where = new Dec<double>(new LinkedListSequence<double>(new double[3]{ 2133, 645, 90654878 }, 3));
    dec_double = dec_double->Where(func_for_Where);
    check += Equal_Decs<double>(dec_double, dec_double_where);
    i++;

    dec_double = new Dec<double>(new LinkedListSequence<double>(new double[6]{ -1.001, -1.002, -1.0009, -2.123, 0, -3.987 }, 6));
    dec_double_where = new Dec<double>(new LinkedListSequence<double>());
    dec_double = dec_double->Where(func_for_Where);
    check += Equal_Decs<double>(dec_double, dec_double_where);
    i++;

    Dec<complex<double>> *dec_complex = new Dec<complex<double>>(new LinkedListSequence<complex<double>>(new complex<double>[4]{ {5, 6}, {6, 5}, {1, 2}, {10, 9} }, 4));
    Dec<complex<double>> *dec_complex_where = new Dec<complex<double>>(new LinkedListSequence<complex<double>>(new complex<double>[3]{ {5, 6}, {6, 5}, {10, 9} }, 3));
    dec_complex = dec_complex->Where(func_for_Where);
    check += Equal_Decs<complex<double>>(dec_complex, dec_complex_where);
    i++;

    dec_complex = new Dec<complex<double>>(new LinkedListSequence<complex<double>>(new complex<double>[4]{ {0, 1}, {0, 1}, {1, 2}, {4.65, 5.214} }, 4));
    dec_complex_where = new Dec<complex<double>>(new LinkedListSequence<complex<double>>(new complex<double>[1]{ {4.65, 5.214} }, 1));
    dec_complex = dec_complex->Where(func_for_Where);
    check += Equal_Decs<complex<double>>(dec_complex, dec_complex_where);
    i++;

    dec_complex = new Dec<complex<double>>(new LinkedListSequence<complex<double>>(new complex<double>[4]{ {-2, -2}, {1, 1}, {-1, -1}, {0, 0} }, 4));
    dec_complex_where = new Dec<complex<double>>(new LinkedListSequence<complex<double>>());
    dec_complex = dec_complex->Where(func_for_Where);
    check += Equal_Decs<complex<double>>(dec_complex, dec_complex_where);
    i++;

    if (check == i)
    {
        cout << "Test_Where: GOOD" << endl;
    }
    else
    {
        cout << "Test_Where: FAIL" << endl;
    }
}

string func_for_Reduce(string str1, string str2)
{
    return str1 + str2;
}
double func_for_Reduce(double a, double b)
{
    return a + b;
}
complex<double> func_for_Reduce(complex<double> a, complex<double> b)
{
    return a + b;
}

void Test_Reduce()
{
    int check = 0;
    int i = 0;

    Dec<string> *dec_str = new Dec<string>(new LinkedListSequence<string>(new string[5]{ "bca", "abc", "srdg", "qwew", "peihrt" }, 5));
    string dec_str_reduce = "peihrtqwewsrdgabcbca_dop_string";
    check += (int)(dec_str->Reduce(func_for_Reduce, "_dop_string") == dec_str_reduce);
    i++;

    dec_str = new Dec<string>(new LinkedListSequence<string>(new string[5]{ "e", "d", "c", "b", "a" }, 5));
    dec_str_reduce = "abcde_dop_string";
    check += (int)(dec_str->Reduce(func_for_Reduce, "_dop_string") == dec_str_reduce);
    i++;

    dec_str = new Dec<string>(new LinkedListSequence<string>(new string[5]{ "", "dasffsad", "fadsf", "wqrr", "" }, 5));
    dec_str_reduce = "wqrrfadsfdasffsad_dop_string";
    check += (int)(dec_str->Reduce(func_for_Reduce, "_dop_string") == dec_str_reduce);
    i++;

    Dec<double> *dec_double = new Dec<double>(new LinkedListSequence<double>(new double[6]{ 6, 5, 4, 3, 2, 1 }, 6));
    double dec_double_reduce = 6 + 5 + 4 + 3 + 2 + 1 + 20.6;
    check += (int)(dec_double->Reduce(func_for_Reduce, 20.6) - dec_double_reduce < 0.0000001);
    i++;

    dec_double = new Dec<double>(new LinkedListSequence<double>(new double[6]{ 2133, 645, 90654878, 0, -13244, -1 }, 6));
    dec_double_reduce = 2133 + 645 + 90654878 + 0 + -13244 + -1 + 20.6;
    check += (int)(dec_double->Reduce(func_for_Reduce, 20.6) - dec_double_reduce < 0.0000001);
    i++;

    dec_double = new Dec<double>(new LinkedListSequence<double>(new double[6]{ -1.001, -1.002, -1.0009, -2.123, 0, -3.987 }, 6));
    dec_double_reduce = -1.001 + -1.002 + -1.0009 + -2.123 + 0 + -3.987 + 20.6;
    check += (int)(dec_double->Reduce(func_for_Reduce, 20.6) - dec_double_reduce < 0.0000001);
    i++;

    Dec<complex<double>> *dec_complex = new Dec<complex<double>>(new LinkedListSequence<complex<double>>(new complex<double>[4]{ {5, 6}, {6, 5}, {1, 2}, {10, 9} }, 4));
    complex<double> dec_complex_reduce = complex<double>(5 + 6 + 1 + 10 + 20.6, 6 + 5 + 2 + 9 + 10.6);
    check += (int)(dec_complex->Reduce(func_for_Reduce, {20.6, 10.6}) == dec_complex_reduce);
    i++;

    dec_complex = new Dec<complex<double>>(new LinkedListSequence<complex<double>>(new complex<double>[4]{ {0, 1}, {0, 1}, {1, 2}, {4.65, 5.214} }, 4));
    dec_complex_reduce = complex<double>(0 + 0 + 1 + 4.65 + 20.6, 1 + 1 + 2 + 5.214 + 10.6);
    check += (int)(dec_complex->Reduce(func_for_Reduce, { 20.6, 10.6 }) == dec_complex_reduce);
    i++;

    dec_complex = new Dec<complex<double>>(new LinkedListSequence<complex<double>>(new complex<double>[4]{ {-2, -2}, {1, 1}, {-1, -1}, {0, 0} }, 4));
    dec_complex_reduce = complex<double>(-2 + 1 + -1 + 0 + 20.6, -2 + 1 + -1 + 0 + 10.6);
    check += (int)(dec_complex->Reduce(func_for_Reduce, { 20.6, 10.6 }) == dec_complex_reduce);
    i++;

    if (check == i)
    {
        cout << "Test_Reduce: GOOD" << endl;
    }
    else
    {
        cout << "Test_Reduce: FAIL" << endl;
    }
}

void Test_Concat()
{
    int check = 0;
    int i = 0;

    Dec<string> *dec_str_1 = new Dec<string>(new LinkedListSequence<string>(new string[5]{ "bca", "abc", "srdg", "qwew", "peihrt" }, 5));
    Dec<string> *dec_str_2 = new Dec<string>(new LinkedListSequence<string>(new string[5]{ "abc", "bca", "peihrt", "qwew", "srdg" }, 5));
    Dec<string> *dec_str_concat = new Dec<string>(new LinkedListSequence<string>(new string[10]{ "bca", "abc", "srdg", "qwew", "peihrt", "abc", "bca", "peihrt", "qwew", "srdg" }, 10));
    check += Equal_Decs<string>(dec_str_1->Concat(dec_str_2), dec_str_concat);
    i++;

    dec_str_1 = new Dec<string>(new LinkedListSequence<string>(new string[5]{ "e", "d", "c", "b", "a" }, 5));
    dec_str_2 = new Dec<string>(new LinkedListSequence<string>(new string[5]{ "a", "b", "c", "d", "e" }, 5));
    dec_str_concat = new Dec<string>(new LinkedListSequence<string>(new string[10]{ "e", "d", "c", "b", "a", "a", "b", "c", "d", "e" }, 10));
    check += Equal_Decs<string>(dec_str_1->Concat(dec_str_2), dec_str_concat);
    i++;

    dec_str_1 = new Dec<string>(new LinkedListSequence<string>(new string[5]{ "", "dasffsad", "fadsf", "wqrr", "" }, 5));
    dec_str_2 = new Dec<string>(new LinkedListSequence<string>(new string[5]{ "", "", "dasffsad", "fadsf", "wqrr" }, 5));
    dec_str_concat = new Dec<string>(new LinkedListSequence<string>(new string[10]{ "", "dasffsad", "fadsf", "wqrr", "", "", "", "dasffsad", "fadsf", "wqrr" }, 10));
    check += Equal_Decs<string>(dec_str_1->Concat(dec_str_2), dec_str_concat);
    i++;

    Dec<double> *dec_double_1 = new Dec<double>(new LinkedListSequence<double>(new double[6]{ 6, 5, 4, 3, 2, 1 }, 6));
    Dec<double> *dec_double_2 = new Dec<double>(new LinkedListSequence<double>(new double[6]{ 1, 2, 3, 4, 5, 6 }, 6));
    Dec<double> *dec_double_concat = new Dec<double>(new LinkedListSequence<double>(new double[12]{ 6, 5, 4, 3, 2, 1, 1, 2, 3, 4, 5, 6 }, 12));
    check += Equal_Decs<double>(dec_double_1->Concat(dec_double_2), dec_double_concat);
    i++;

    dec_double_1 = new Dec<double>(new LinkedListSequence<double>(new double[6]{ 2133, 645, 90654878, 0, -13244, -1 }, 6));
    dec_double_2 = new Dec<double>(new LinkedListSequence<double>(new double[6]{ -13244, -1, 0, 645, 2133, 90654878 }, 6));
    dec_double_concat = new Dec<double>(new LinkedListSequence<double>(new double[12]{ 2133, 645, 90654878, 0, -13244, -1, -13244, -1, 0, 645, 2133, 90654878 }, 12));
    check += Equal_Decs<double>(dec_double_1->Concat(dec_double_2), dec_double_concat);
    i++;

    dec_double_1 = new Dec<double>(new LinkedListSequence<double>(new double[6]{ -1.001, -1.002, -1.0009, -2.123, 0, -3.987 }, 6));
    dec_double_2 = new Dec<double>(new LinkedListSequence<double>(new double[6]{ -3.987, -2.123, -1.002, -1.001, -1.0009, 0 }, 6));
    dec_double_concat = new Dec<double>(new LinkedListSequence<double>(new double[12]{ -1.001, -1.002, -1.0009, -2.123, 0, -3.987, -3.987, -2.123, -1.002, -1.001, -1.0009, 0 }, 12));
    check += Equal_Decs<double>(dec_double_1->Concat(dec_double_2), dec_double_concat);
    i++;

    Dec<complex<double>> *dec_complex_1 = new Dec<complex<double>>(new LinkedListSequence<complex<double>>(new complex<double>[4]{ {5, 6}, {6, 5}, {1, 2}, {10, 9} }, 4));
    Dec<complex<double>> *dec_complex_2 = new Dec<complex<double>>(new LinkedListSequence<complex<double>>(new complex<double>[4]{ {1, 2}, {5, 6}, {6, 5}, {10, 9} }, 4));
    Dec<complex<double>> *dec_complex_concat = new Dec<complex<double>>(new LinkedListSequence<complex<double>>(new complex<double>[8]{ {5, 6}, {6, 5}, {1, 2}, {10, 9}, {1, 2}, {5, 6}, {6, 5}, {10, 9} }, 8));
    check += Equal_Decs<complex<double>>(dec_complex_1->Concat(dec_complex_2), dec_complex_concat);
    i++;

    dec_complex_1 = new Dec<complex<double>>(new LinkedListSequence<complex<double>>(new complex<double>[4]{ {0, 1}, {0, 1}, {1, 2}, {4.65, 5.214} }, 4));
    dec_complex_2 = new Dec<complex<double>>(new LinkedListSequence<complex<double>>(new complex<double>[4]{ {0, 1}, {0, 1}, {1, 2}, {4.65, 5.214} }, 4));
    dec_complex_concat = new Dec<complex<double>>(new LinkedListSequence<complex<double>>(new complex<double>[8]{ {0, 1}, {0, 1}, {1, 2}, {4.65, 5.214}, {0, 1}, {0, 1}, {1, 2}, {4.65, 5.214} }, 8));
    check += Equal_Decs<complex<double>>(dec_complex_1->Concat(dec_complex_2), dec_complex_concat);
    i++;

    dec_complex_1 = new Dec<complex<double>>(new LinkedListSequence<complex<double>>(new complex<double>[4]{ {-2, -2}, {1, 1}, {-1, -1}, {0, 0} }, 4));
    dec_complex_2 = new Dec<complex<double>>(new LinkedListSequence<complex<double>>(new complex<double>[4]{ {0, 0}, {1, 1}, {-1, -1}, {-2, -2} }, 4));
    dec_complex_concat = new Dec<complex<double>>(new LinkedListSequence<complex<double>>(new complex<double>[8]{ {-2, -2}, {1, 1}, {-1, -1}, {0, 0}, {0, 0}, {1, 1}, {-1, -1}, {-2, -2} }, 8));
    check += Equal_Decs<complex<double>>(dec_complex_1->Concat(dec_complex_2), dec_complex_concat);
    i++;

    if (check == i)
    {
        cout << "Test_Concat: GOOD" << endl;
    }
    else
    {
        cout << "Test_Concat: FAIL" << endl;
    }
}

void Test_GetSubDec()
{
    int check = 0;
    int i = 0;

    Dec<string> *dec_str = new Dec<string>(new LinkedListSequence<string>(new string[10]{ "bca", "abc", "srdg", "qwew", "peihrt", "abc", "bca", "peihrt", "qwew", "srdg" }, 10));
    Dec<string> *dec_str_getsubdec = new Dec<string>(new LinkedListSequence<string>(new string[3]{ "srdg", "qwew", "peihrt" }, 3));
    check += Equal_Decs<string>(dec_str->GetSubDec(2, 4), dec_str_getsubdec);
    i++;

    dec_str_getsubdec = new Dec<string>(new LinkedListSequence<string>(new string[1]{ "bca" }, 1));
    check += Equal_Decs<string>(dec_str->GetSubDec(0, 0), dec_str_getsubdec);
    i++;

    dec_str_getsubdec = new Dec<string>(new LinkedListSequence<string>(new string[3]{ "abc", "bca", "peihrt" }, 3));
    check += Equal_Decs<string>(dec_str->GetSubDec(5, 7), dec_str_getsubdec);
    i++;

    if (check == i)
    {
        cout << "Test_GetSubDec: GOOD" << endl;
    }
    else
    {
        cout << "Test_GetSubDec: FAIL" << endl;
    }
}

