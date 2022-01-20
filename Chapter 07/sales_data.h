#include<iostream>
#include<string>
#include<vector>
#include<cctype>
#include<stdexcept>
using std::string ; using std::cin ; using std::cout ; using std::cin ; using std::endl; using std::vector; using std::runtime_error; using std::istream; using std::ostream;
class Sales_data{
friend Sales_data add(const Sales_data & , const Sales_data&);
friend istream print(istream  & , const Sales_data&);
friend ostream read(ostream & , Sales_data&);
public:
    Sales_data()= default;
    string isbn() const {return bookNo;}
    Sales_data & combine(Sales_data&);
private:
    string bookNo;
    unsigned unit ;
    double revenue ;
};
