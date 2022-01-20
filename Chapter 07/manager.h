#include<iostream>
#include<string>
#include<vector>
#include<cctype>
#include<stdexcept>
//#include"screen.h"
using std::string ; using std::cin ; using std::cout ; using std::cin ; using std::endl; using std::vector; using std::runtime_error;
/*
we will be defining a manager class which will have collection of screens.
we will have vector of screen where each element represent screen.
we would like to start our screen with a default screen.best way to do so is to make in class initializers.

when we are creating we are calling constructor of that class to make a element.
using friendship we can define function clear the screen.
*/
class Manager{
public:
    using index  =  std::vector<Screen>::size_type;
    void clear(index);
    index addMember(const Screen &);
private:

    vector<Screen>screens{Screen{24,80,' '}}; // it will blank screen of given size.

};
void Manager::clear(index i)
{
    Screen &s = screens[i];
    s.content = string(s.height* s.width, ' ') ;
}
Manager::index
Manager::addMember(const Screen &s)
{
    screens.push_back(s);
    return screens.size()-1;
}
