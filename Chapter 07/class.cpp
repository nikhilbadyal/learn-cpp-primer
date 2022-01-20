#include<iostream>
#include<string>
#include<vector>
#include<cctype>
#include<stdexcept>
#include"screen.h"
#include"manager.h"
using std::string ; using std::cin ; using std::cout ; using std::cin ; using std::endl; using std::vector; using std::runtime_error;
class LinkScreen{
    Screen window;
    LinkScreen *next;
    LinkScreen *prev;
};
int main()
{
    /* Class

    fundamental idea behind is data abstraction , encapsulation ,

    abstraction is a technique that relies on separating interface and implementation
    the interface included consist of operation that  user of  class can execute.
    The implementation includes the
    class data members, the bodies of the functions that constitute the interface, and any
    functions needed to define the class that are not intended for general use.

    encapsulation enforces  separation of implementation and interface
    a class that use abstraction and encapsulation defines ADT.in ADTS user worries how the class is implement but
   programmer can think in abstract way ie how it can use operands.


   designing the sales data class  -  ultimately we want sales data to behave like sales
   item class so that it can support operators.

   we need sales data to contain following things.
   a. a isbn member function
   b combine function to combine one sales object to other .
   c. add to add two sales data object.
   d. read - to read from istream
   e. print - to print to ostream


   introducing this -
   when we call an function on behalf of an object the address of object is implicitly stored in the this pointer.
  so when we call
  total.isbn()
  hence it something like sales_data::isbn(&total);
  inside the function we can directly call the object there is no need of this.
  but if we want we van use.
  this->bookNo;
  this is a const pointer
  another new thing is const used before parameter list.its purpose is to modify the type of implicit this
  by default this is const pointer to non const object

  members with this kind of const in them are called as const member function and and indicated that this is pointer to const object.


   Objects that are const, and references or pointers to const objects, may
   call only const member functions.

   IO classes cant be copied hence we take their reference.
   in case of read we take const while in write we take non const
   print should print a new line and it should depend on user to print it or not


   constructors

   each class defines how its objects should be initialized.it do so by using special member function called
   constructor. its job is to initialize its object . it run whenever an object is created.
   they have same name of class and no return type.constructor may be const and object doesnt consider its
   constness until constructor is run.thus they can write too const object


   the compiler generated compiler is called as synthesized constructor. it initialize in following manner
   1. if there are in class initializer then with them or
   2. default initialize
   Classes that have members of built-in or compound type usually should rely
on the synthesized default constructor only if all such members have in-class
initializers.

Under the new standard, if we want the default behavior, we can ask the compiler
to generate the constructor for us by writing = default after the parameter list

a constructor
initializer list, which specifies initial values for one or more data members of the
object being created.

When a member is omitted from the constructor initializer list, it is implicitly initialized
using the same process as is used by the synthesized default constructor


Copy, Assignment, and Destruction


mutable keyword is used when we our class to change the data member even if it is const
class may define a type so enforce encapsulation
like
class::size_type pos;
we define this in public past as user should not know that we have defined string to handle data
we can also use
using pos = class::size_type
function defined in class are by default inline
we can also explicitly define a function inline or writting inline in definition or declaration

sometime we have a data member which we want to modify inside an const function. To do so we use
mutable keyword.
mutable data member is never a const. Even when it member of const function.a const member may get change inside
function.

When we provide an in-class initializer, we must do so following an = sign or
inside braces.

function that return this -

return the reference to which they were called. functions that return reference are lvalue and hence we can
assign to to that function too.this mean they return the object itself not the copy of object.
hence we can cascade them and they will operate on same object.\

logically saying display wont change state so we should make i const but if we make it const then this will be
pointer to const and hence it will return const Sales_data& and hence we cant cascade on a const object.
we can overload based on consteness.
the non const will not be viable for const function but can call either on non const object


class member revisited

friendship-
a class can define another class friend or any class particular as friend. A friend can be defiened inside
a class.

overloaded functions and friendship

class Scope

Every class has its scope outside which they can be accessed by object pointer or scope
operator.

scope and member defined outside class-

name lookup and class scope-


class can override the variables of the outer scope but if it is typedef then   it is error.

constructor--

when we create variable , we prefer to initialize them than t create them and then assign.
Sales_data::Sales_data(const string &s,
unsigned cnt, double price)
{
bookNo = s;
units_sold = cnt;
revenue = cnt * price;
}
both will give same result in the end , but this is sloppier way to write constructors,
the other one assigns  but this one initialize.
members that are const must be initialized.

We must use the constructor initializer list to provide values for members that
are const, reference, or of a class type that does not have a default
constructor

Delegating constructors--

the delegating constructor use another constructor of its class to do its initialization.

class Sales_data {
public:
// non-delegating constructor initializes members from corresponding arguments
Sales_data(std::string s, unsigned cnt, double price):
bookNo(s), units_sold(cnt), revenue(cnt*price) {
}
// remaining constructors all delegate to another constructor
Sales_data(): Sales_data("", 0, 0) {}
Sales_data(std::string s): Sales_data(s, 0,0) {}
Sales_data(std::istream &is): Sales_data()
{ read(is, *this); }
// other members as before
};

role of default constructor--

it is automatically used when an object is default or value initialized.
default happens-
when we define  non static members or array at block scope without initializers.
when a class that itself has class type uses the synthesized  constructor.
when members are not explicitly initialized in initializer list.

value happens-
when we give fewer elements than the size of array.
when we define local static object without initializer.
when we explicitly asks for it by writting t().


The correct way to define an object that uses the default constructor for initialization
is to leave off the trailing, empty parentheses
class c(); // it is declare of function


IMPLICIT  class type conversion--

A constructor that can be called with a single argument defines an implicit
conversion from the constructor  parameter type to the class type.

hence we can call combine function on string or iostream. as they are converted to class type.
string null_book = "9-999-99999-9";
// constructs a temporary Sales_data object
// with units_sold and revenue equal to 0 and bookNo equal to null_book
item.combine(null_book);
this is legal.

only 1 conversion is possible like if we try to do so .
item.combine("9999999-9999"); // here two conversion are taking conversions first literal into string
then temp into string.

item.combine(string("999-999-999")); // implicit convert to string

item.combine(cin);
This code implicitly converts cin to Sales_data. This conversion executes the
Sales_data constructor that takes an istream. That constructor creates a
(temporary) Sales_data object by reading the standard input. That object is then
passed to combine.

we can stop all of this by defining the constructor explicit.

The explicit keyword is meaningful only on constructors that can be called with
a single argument. Constructors that require more arguments are not used to perform
an implicit conversion, so there is no need to designate such constructors as
explicit. The explicit keyword is used only on the constructor declaration inside
the class. It is not repeated on a definition made outside the class body

but remember explicit constructor can be used only in direct initialization
class V(v); // ok
class V = v ; // error;

although compiler dont use explicit constructor to  do conversion we can force it. by writting.
item.combine(Sales_data(null_book));
item.combine(static_cast<Sales_data>(cin)); // using static cast.


aggregate classes ---

they provide direct access to its data member and has special initialization.
1. all members are public.
2. no constructor.
3. no in class initializer.
4 it has no base class or virtual function.

eg -
struct Data{
int d;
int m;
}
we can initialize its member like
Data d{1,2}; // they must appear in same order.
if the no of elements ate less then remaining are value initialized.


literal class.---
An aggregate class (§ 7.5.5, p. 298) whose data members are all of literal type is a
literal class


non aggregate class can also be literal if
1. all data members are of literal type.
2. class must have at least one constexpr constructor.
3. If a data member has an in-class initializer, the initializer for a member of built-
in type must be a constant expression (§ 2.4.4, p. 65), or if the member has
class type, the initializer must use the member’s own constexpr constructor.
• The class must use default definition for its destructor, which is the member
that destroys objects of the class type

constexpr constructor--

although constructor cant be const but in literal class can be constexpr function.

it can be declared as = default or deleted function.



Otherwise, a constexpr
constructor must meet the requirements of a constructor—meaning it can have no
return statement—and of a constexpr function—meaning the only executable
statement it can have is a return statement (§ 6.5.2, p. 239). As a result, the body
of a constexpr constructor is typically empty. We define a constexpr constructor
by preceding its declaration with the keyword constexpr


class Debug {
public:
constexpr Debug(bool b = true): hw(b), io(b), other(b) {
}
constexpr Debug(bool h, bool i, bool o):
hw(h), io(i), other(o) {
}
constexpr bool any() { return hw || io || other; }
void set_io(bool b) { io = b; }
void set_hw(bool b) { hw = b; }
void set_other(bool b) { hw = b; }
private:
bool hw; // hardware errors other than IO errors
bool io; // IO errors
bool other; // other errors
};
A constexpr constructor must initialize every data member. The initializers must
either use a constexpr constructor or be a constant expression.

static member -

sometime we need a member which is associated with class rather than object.
The type of a static data member can be const, reference, array, class type, and
so forth.
static members dont have this pointer. and hence they may not be const.
even though object dont have static member we can still use them to access them.
Because static data members are not part of individual objects of the class type,
they are not defined when we create objects of the class. As a result, they are not
initialized by the class  constructors. Moreover, in general, we may not initialize a
static member inside the class. Instead, we must define and initialize each static
data member outside the class body. Like any other object, a static data member
may be defined only once.

ordinary we cant initialize static member in class body. but if they are const we can do this.
static constexpr int period = 30;


Even if a const static data member is initialized in the class body, that
member ordinarily should be defined outside the class definition.

properties of static member --

they can be used in many fetures where non static acnt like -
1.they can have static type.
2. class can contain static type (class type)

eg class A{
static A a;
A *p ;
A b; //error

we can use static member as default argument.
class Screen {
public:
// bkground refers to the static member
// declared later in the class definition
Screen& clear(char = bkground);
private:
static const char bkground;
};











    */
//    char c(10,c);
    Screen::pos ht = 20 , wd = 80;
    Screen scr(ht,wd,'@');
    Screen *p = &scr;
    char c = scr.get();
    char d = p->get();
    cout<<c<<endl;

    return 0;
}
