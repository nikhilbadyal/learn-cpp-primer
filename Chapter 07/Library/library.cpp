#include<iostream>
#include<string>
#include<vector>
#include<cctype>
#include<stdexcept>
#include"Book.h"
#include"Status.h"
//#include"Student.h"
#include"MemberList.h"
using std::istream; using std::ostream;
using std::string ; using std::cin ; using std::cout ; using std::cin ; using std::endl; using std::vector; using std::runtime_error; using std::end; using std::begin;
int main()
{
    Booklist b;
    b.addBook();
    MemberList ml;
    ml.sl.addStudent();
    ml.issueRequest(b);
    return 0;
}
