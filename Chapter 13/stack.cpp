#include<iostream>
using std::cin; using std::cout;

#include<string>
using std::string;
class Hasptr{
public:
    Hasptr(const Hasptr& given):s(new string(*given.s)), i(given.i){}
    Hasptr(const string & given = string()): s(new string(given)), i(0){}
    Hasptr& operator = (const Hasptr &);
    ~Hasptr(){delete s;};
private:
    string *s;
    int i ;
};
HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
auto newp = new string(*rhs.ps); // copy the underlying string
delete ps; // free the old memory
ps = newp; // copy data from rhs into this object
i = rhs.i;
return *this; // return this object
}
