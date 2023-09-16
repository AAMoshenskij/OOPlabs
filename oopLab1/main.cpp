#include <iostream>
#include <cstring>
#include "func.h"

using namespace std;

int main()
{
    string str;
    cout << "Введите слово: ";
    cin >> str;
    if(check_palindrom(str)) {
        std::cout << "Слово является палиндромом\n";
    }
    else {
        std::cout << "Слово не является палиндромом\n";
    }
    return 0;
}
