#include<iostream>
#include<string>
#include<vector>
#include<cctype>
#include<stdexcept>
#include"sales_data.h"
using std::string ; using std::cin ; using std::cout ; using std::cin ; using std::endl; using std::vector; using std::runtime_error;
/* To define several features of class we will make two dependent class. one named screen and other names migrate.
screen represent window on the screen. Screen has string type to handle the content of screen
and three string::size_type for position of cursor and height and width of cursor.

although we are not required but we can write inline in both definition declaration.

overloading member function
Sometimes but not very often we want a member function whom we want to modify even in const function.
we declare them as mutable.

live move our set return reference to the object. hence we can cascade the operation like
screen.move(20,39).set('@');
had we not returned reference the statement wont work as expected. it will do such thing.
Screen temp = screen.move(29,30);
temp.set('@'); hence it wont make any difference on screen.
we will now define a set a display function to show content on screen.Since it should be compatible with
set move hence we will be returning reference from it.
But logically saying display wont change anything so we should make it const but if we make const then
this would be pointer to const and hence it will return reference to const on which we cant cascade.
hence we can overload based on const.
non const wont be viable for const but we can call non const on any object but non will be preferred.
hence we will define a do_display function.

we can use incomplete description only in limited ways.such as reference to it
With one exception that we'll describe, data members can be
specified to be of a class type only if the class has been defined

*/
class Screen{
public:
    friend class Manager;
  //  friend Manager::index(index );
    using pos = std::string::size_type; // we defined pos in public so that every will use pos and no one know we used string::size_type
    Screen() = default; // needed because we'll be defining our own constructor.
    Screen(pos ht , pos wd , char c): height(ht) , width(wd), content(ht*wd,c) {}
    char get() const {return content[cursor];} // implicitly inline
    inline char get(pos , pos ) const ; // explicitly inline
    Screen &move(pos , pos ); // can be made inline later.
    void count() const;
    Screen & set(char ) ;
    Screen &set(pos , pos ,char );
    const Screen & display(ostream &os ) const
            {do_display(os); return *this; }
    Screen & display(ostream &os )
            { do_display(os); return *this; }


private:
    void do_display(ostream &os) const {cout<<content; }
    mutable size_t access_ctr;
    pos cursor=0 ;
    pos height=0, width = 0;
    string content;
};
inline Screen & Screen::move(pos r , pos c)
{
    pos row = r*width;
    cursor = row + c;
    return *this;
}
char Screen::get(pos r , pos c) const //const is must
{
    pos row = r*width;
    return content[row+c];
}
void Screen::count() const
{
    ++access_ctr; // it will count call to any member function
}
inline
Screen &Screen::set(char c)
{
    content[cursor] = c;
    return *this;
}
inline
Screen & Screen::set(pos r , pos c , char )
{
    content[r*width+c] = c;
    return *this;
}

