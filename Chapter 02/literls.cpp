#include<iostream>
using namespace std;
int main()
{
    /* A value is called as literal like 42 .
    1. INTEGER and floating Literal
    we can write these in decimal hexadecimal or octal.
    ex - 20 Decimal by default they are signed.
    020 - octal
    0x14 - hexadecimal

    2. Character and character string literal
    A. character stored in single quotes is character literal and is of type char.
    B.  0 or more character enclosed in double quotes are string literals and it's type is array of const char.
    'a' - character literal
    "a" - string literal.

    if we use /x we can as many octal values . if we use \1234 it will take first three as octal
    and last 4 as plain char.

    3. bool literal
    bool true = false;

    4. nullptr is pointer literal*/
   // cout<<"Hi \n";
   // cout<<"Hi \t nikhil";
    std::cout << "Hi \x4dO\115!\n";

    cout<<u8"hi!";







    return 0;
}
