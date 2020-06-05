
#include <iostream>
#include "Tests.h"

using namespace std;

string F_Map(string str);
bool F_Where(string str);
string F_Reduce(string str1, string str2);

template<class T>
void Show(Dec<T> *dec, string str)
{
    cout << str << " ";
    for (int i = 0; i < dec->GetLength(); i++)
    {
        cout << dec->Get(i) << " ";
    }
    cout << "\n";
}

int main()
{
    Test_Sort();
    Test_Map();
    Test_Where();
    Test_Reduce();
    Test_Concat();
    Test_GetSubDec();

    string str;
    cout << "\nIf you want to use - press \"e\", else - press \"p\"\n";
    cin >> str;
    if (str != "e")
    {
        return 0;
    }

    char fun;

    do
    {
        system("color 7");
        try
        {
            Dec<string> *dec_str_1 = new Dec<string>(new LinkedListSequence<string>(new string[9]{ "bca", "abc", "srddg", "qwedw", "peihrt", "dfsafasd", "fdsafd", "ridd", "ppkk" }, 9));
            Dec<string> *dec_str_2 = new Dec<string>(new LinkedListSequence<string>(new string[5]{ "pla", "dasffsad", "fadsf", "wqrr", "dds" }, 5));

            cout << "\nEnter: 1 - Sort, 2 - Map, 3 - Where, 4 - Reduce, 5 - Concat, 6 - GetSubDec\n";
            std::cin >> fun;

            switch (fun)
            {
            case '1':
                Show<string>(dec_str_1, "Start Dec:");
                dec_str_1->Sort();
                Show(dec_str_1, "Sort:");
                break;
            case '2':
                Show<string>(dec_str_1, "Start Dec:");
                Show<string>(dec_str_1->Map(F_Map), "Map (+ _abcde):");
                break;
            case '3':
                Show<string>(dec_str_1, "Start Dec:");
                Show<string>(dec_str_1->Where(F_Where), "Where (str[3] == d):");
                break;
            case '4':
                Show<string>(dec_str_1, "Start Dec:");
                cout << "Reduce (+ _lalalala): " << dec_str_1->Reduce(F_Reduce, "_lalalala");
                cout << "\n";
                break;
            case '5':
                Show<string>(dec_str_1, "Dec 1:");
                Show<string>(dec_str_2, "Dec 2:");
                Show<string>(dec_str_1->Concat(dec_str_2), "Concat:");
                break;
            case '6':
                Show<string>(dec_str_1, "Start Dec:");
                int startIndex = 4;
                int endIndex = 6;
                string str = "GetSubDec, (" + to_string(startIndex) + (string)"," + to_string(endIndex) + (string)"):";
                Show<string>(dec_str_1->GetSubDec(startIndex, endIndex), str);
                break;
            }
        }
        catch (IndexOutOfRange ex)
        {
            system("color 4");
            cout << "\n" << "ERROR !!!";
            cout << "\n" << ex.what() << endl;
        }
        catch (MyException ex)
        {
            system("color 4");
            cout << "\n" << "ERROR !!!";
            cout << "\n" << ex.what() << endl;
        }
        cout << "\nIf you want to exit - press \"e\", else - press \"p\"" << endl;
        
        std::cin >> str;

    } while (str != "e");
}
string F_Map(string str)
{
    str += "_abcde";
    return str;
}
bool F_Where(string str)
{
    if (str.length() < 4)
    {
        return false;
    }
    if (str[3] == 'd')
    {
        return true;
    }
    return false;
}

string F_Reduce(string str1, string str2)
{
    return str1 + str2;
}
