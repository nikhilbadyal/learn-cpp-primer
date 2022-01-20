#include<iostream>
#include<iostream>
#include<vector>
#include<string.h>
#include<cctype>
using std::cin ; using std::cout; using std::endl; using std::vector ; using std::string;
int main()
{
    /*Iterators - although we can use subscript operator to access individual element but
    iterators are more efficient to be used.
    Like pointers iterators give direct access to the object in this case objects are
    element of a container or char in string
    unlike pointer we don't have address of the pointer . instead types that have iterator has members that
    return iterators
    in particular they have types end and begin
    begin return the an iterator that denotes first member . the iterator return by end is an iterator positioned at
    one past the end . This iterator denotes a nonexistent element  off the end of the container
    it is used as marker that we have processed all the elements.the iterator returned by end is oftenly
    called as off the end iterator.if container is empty begin and end are same.


    vector<int>v(10,15);
    cout<<*(v.begin())<<endl;
    auto b = v.begin();
    auto c = v.end();
    cout<<*b<<endl;

  //  cout<<*(c-1)<<endl;
    string s = ("nikhil Badyal");

    if(s.begin()!= s.end() ){
        auto it = s.begin();
        (*it) = toupper(*it);}
    cout<<s<<endl;

    string t = ("nikhil Badyal");
    auto it = t.begin();
    for(it ;it != s.end() && !isspace(*it); it++ ){

            cout<<*it<<endl;
        *it = toupper(*it);
    }
    cout<<t<<endl;

    2. Iterator types
    just as we don't know the type of size_t and size_type we don't know the type of iterator and we don't even need it
    Library defines two type to handle them
    a. iterators
    b. const_iterators

    vector<int>::iterator it; // it can read and write
    vector<int>::const_iterator it2; // it can read only
    string::iterator st;  // it can read and write
    string::const_iterator st2;  // it can  read only but not write

    3. begun and end
    type return by end depend on the whether the object is const

    vector<int>v1;
    const vector<int>v2;
    auto v11 = v1.begin(); // it can read and write1
    auto v22 = v2.begin(); // it can read only


    this type of behavior is not what we need.
    so c++ defines two need functions.


    auto i3 = v1.cbegin(); // it is of type const_iterator ;

    3. sometime we have vector of class object and we want to access object to do so,
    we do something like
    (*it).size() or we can use dereference operator it->size(); // parenthesis are must here

    4. iterator arithmetic


    vector<int>v = {1,2,3,4,5,6,7,8,9,10};
    auto a = v.begin();
    a= a+3;
    cout<<*a<<endl;
    a+=3;
    cout<<*a<<endl;
    cout<<*a<<endl;

    we can't add two iterator but we can subtract them */


    return 0;
}

