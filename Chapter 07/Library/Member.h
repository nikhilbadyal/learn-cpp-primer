#include<iostream>
#include<string>
#include<vector>
#include<cctype>
#include<stdexcept>
//#include"Member.h"
using std::istream; using std::ostream;
using std::string ; using std::cin ; using std::cout ; using std::cin ; using std::endl; using std::vector; using std::runtime_error; using std::end; using std::begin;
class Member{
protected:
//public:

    unsigned id;
    string name;
public:
    int bookCount = 0;
    unsigned ID()
    {
        return id;
        }

};
