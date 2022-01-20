#include<iostream>
#include<iostream>
#include<vector>
#include<string.h>
using std::cin ; using std::cout; using std::endl; using std::vector ; using std::string;
int main()
{
    /*Iterators - although we can use subscript operator to access individual element but
    iterators are more efficient to be used.
    Like pointers iterators give direct access to the object in this case objects are element of a container
    or char in string
    unlike pointer we don't have address of the pointer . instead types that have iterator has members that
    return iterators
    in particular they have types end and begin
    begin return the an iterator that denotes first member

     */
    vector<int>v(10,15);
    auto b = v.begin();
    auto c = v.end();
    return 0;
}

