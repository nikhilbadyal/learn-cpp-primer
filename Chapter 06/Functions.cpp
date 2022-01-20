#include<iostream>
#include<string>
#include<vector>
#include<cctype>
using std::string ; using std::cin ; using std::cout ; using std::cin ; using std::endl; using std::vector; using std::initializer_list;
void str(string &s){}
void error_msg(initializer_list<string> il)
{
    for (auto beg = il.begin(); beg != il.end(); ++beg)
        cout << *beg << " " ;
    cout << endl;
}
bool lengthCompare(const string &, const string &);
// to declare its type we will use its type
bool (*pf)(const string &, const string &); // braces are must  here.

string make_plural(size_t count, const string &s , const string &word)
{
    return (count>1) ? string+word : string ;
}
const string &shorterString(const string &s1, const string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}
const string &manip()
{
string ret;
// transform ret in some way
if (!ret.empty())
return ret; // WRONG: returning a reference to a local object!
else
return "Empty"; // WRONG: "Empty" is a local temporary string
}
int main()
{
    /* Functions
    it mainly consists of return type, a name , an empty or non empty list of parameters , and  BODY
    .WE call functions through a call operator.

    a function call do 2 things.
    1. it initialize the function parameter.
    2. it transfer control to the that function.at that time execution of calling function stops and control
    goes to called function. it then executes and returns back to the calling function.

    execution of fun stops when it encounters return statement.return do 2 things
    1. it sends control back
    2. returns and value , if mentioned to the calling expression


    arguments and initializers

    arguments are functions parameters. they are initialized in sequence and we have and no idea how they
    are evaluated.

    fact(2)// ok as 2 is  int.
  //  fact("nikhil"); // error as its type is const char *
    fact(2.3); // ok as double will convert to int


    function parameter list can be empty but cant be omitted. we write void keyword to show that it doesnt take parameters
    fact(){}  // implicit void
    fact(void){}// explicit void

    return type -
    most types can be used as return type. even we can use void as return type. but we cant use array or function type for return
    however it may return pointer to  array or function.

    local objects-

    in c++ names have scopes and objects have lifetimes
    the scope of the name is the part of program in which that name is visible
    lifetime is the time duration time execution  that the object exist
    as we know function are defined in block .  hence parameter and variables defined in it are called
    local variables.


    automatic objects -

    objects that correspond to ordinary local variable are created when functions control passes through variable
    function. objects that are inside a block are know as automatic objects.

    local static objects -

    it is useful to have local variable whose lifetime remain for all calls to that function, for this task we
    can define object as static.they are destroyed when program finishes.
    if value is not provided they are initialized ie they have value of zero.

    function declaration

    as like variables name of function must be declared before we can use it. as with variables
    a function can be defined once but can be declared once;

    Remember a variable can be declared many time but defined once.
    void fun();
    void fun();
    extern int x ;
    extern int x ;

    although no one can stop us. we can define parameters in the declaration of function  it has ; instead o f
    function body.declaration is also called as function prototype.


    in multi file scenarios they should be declared in header and defined in main


    2. Argument passing

    if the parameter is an reference then parameter is bound to argument else it is copied.when a parameter is a
        reference we simply call it call by reference. when it is copied it is called called by value.

     a. passing by value -
     in these cases they dont effect the original value eg fact(i) in function we can we do anything and it wont effect
     i.

    b. pointer parameter -
    they behave like non reference type.

    int n = 0, i = 42;
    int *p = &n, *q = &i; // p points to n; q points to i
    *p = 42; // value in n is changed; p is unchanged
    cout<<n;
    p = q;

    void reset(int *);
    int x = 10;
    int *q = &x;
    reset(q);
    // reset(&x); we can reference here and it will be converted to int *
    cout<<x<<endl;
    cout<<*q<<endl;
    return 0;
    void reset(int *p)
    {
        *p = 0;
        p = NULL; // it only changes the local copied pointer not the original pointer

    }
    in c we oftenly use pointer for passing to function in reference passing while in c++ we use reference.

    passing arguments by reference

    in actual reference is just another name of argument hence any operation on operation is operation
    on actual object.

    use reference to avoid copies - it is efficient to copy large structure hence we must reference for it.
    also there are some classes which dont allow copying and hence we need to pass reference to them as parameter
    reference parameter that dont change inside a function should be reference to const.


    using reference to return additional information -
    as we know that we can return only 1 object from return statement.

    string::size_type find_char(const string &s, char c,
    string::size_type &occurs)
    {
    auto ret = s.size(); // position of the first occurrence, if any
    occurs = 0; // set the occurrence count parameter
    for (decltype(ret) i = 0; i != s.size(); ++i) {
    if (s[i] == c) {
    if (ret == s.size())
    ret = i; // remember the first occurrence of c
    ++occurs; // increment the occurrence count
    }
    }
    return ret; // count is returned implicitly in occurs
     }
     as an example we can use this function to get the first occurrence and count of a particular variable.


    const parameter and arguments

    as we have seen top level consts are the one that are applied  to object itself.



    int  x = 10,y;
    const int* p = &x; //low level const
    int * const q = &x; // top level const
  //  when we copy an argument top level const are ignore. so we can pass const or non const to a parameter that has top level const
    void fun(const int i);
    void fun(int i);
    since top level consts are ignore during  initialization hence both have same implication hence it would be redeclaration and hence an error.




  int x = 10;
  int y = 10;
  int * const p = &x;
 // p = &y; // error as p is const
 *p= 20; // it is ok
 const int *q =  &y;
// *q = 20; // q is pointer to const
  q = &x; // it is ok because pointer is not const


  pointer or reference parameter and const

  low level const can be initialized with non const.
  but non const cant be initialized with low level
  we can initialize top level const with non const or const
  int x = 10;
  const int * p = &x;

  int y = x;
//  int *s = p; error as we cant initialize const non with low level const


   use reference to const whenever possible
string s = "nikhil";
str(s);



  array reference as parameter
  Just as we can define a reference to array we can also define reference parameter to array.
  void print( int (&arr)[10])
  parenthesis are must as without them , it will declare array of reference
  because size is part  of array it is safe to rely on array for size.


  passing multi dimensional array

  when we pass array we are passing pointer to first element size of second dimension must be passed.


  int (*matrix)[10];  or
  void print(int matrix[][10], int rowSize)

  no matter what other object is we can use const to initialize it.
  int x = 10;
  int y = 20;
  int const &p = x;  // p is const reference
//  p = 20;
   int x = 10;
    const int y = 20; // top level const
   const int *p = &x; // const is low level
   int *const q = &x; // q is top level const
 //   q = &y; // as q is top level



   initialization and const

  1.  when we use an object to initialize another object, it doesn't matter whether either or
both of the objects are consts: from which to be initialized must be non const.
  2.  for const object reference must be const ie both side must be const
   3.  const int reference can be initialized with literal value
   4. reference to const may be of any type( but they arent of much use)
   5. in case of   pointer too (case2) , const object can be stored only in const pointer
  6. like 4 we can use pointer to const to point to non const object( but they arent of much use)
  7 unlike reference we can const pointer. to do so we put const after *
  8. when we copy top level consts are ignored.
  copied from or copied into is const

  but low level const are not ignored .ie both side must have low level constness or conversion must be there(non const to const can be done)

  1. value from which initialization is to be done -- it must be non- const.if it is const then the value to which we initialize must be const.

 str("nikhil");


   functions with variation parameters

   sometimes we dont know how many parameter we will need in parameter list . let us take a case where we want to print all errors encountered by the program
  new standard provides two ways to handle these kind of condition

  1. if all are of same type we can pass a library type initializer_list
  2. if they are of different type  , we can write a variadic  template

  c++ also has special type known as ellipsis that can be used to pass varying no . of parameters.

  initializer_list - this is library that represent an array of values of specified type.

  following operations are available in the library

  a. initializer_list<T>1st;
  default initialization ; an empty list of elements of type T;
  b. initializer_list<T>1st{a,b,v,c,ff,g,h,} // it has as many elements as in list. elements are of const nature
  lst2(lst) - copy or initializing a list doesnt copy elements  . both share same copy of elements
  lst.size() - tells the size of the list
  lst.begin()- return pointer to the beginning of the list
  lst.end() - return pointer to the end of the list

  it is a type of template hence we must define during initialization the type of elements it will handle.
  initializer_list<string>1st;
  initializer_list<int>1st;

  unlike vectors elements in this are always const and hence there is not way to change the elements.
  we can write our error function to produce error for varying number of arguments.



  elipsis parameter



  3. return type and return statement -

  a return statement stops of execution of current executing function and returns control to the function who called it.
  return ;
  return expression ;


  a. functions with no return value

  return with no value can be used inside only those functions whose return type is void
  functions that return void are not required to contain return. in void function implicit return  takes pace.


   function that return a value


   3. overloaded functions

   Functions that have the same name but different parameter lists and that appear
   in the same scope are overloaded. main cant be overloaded.


   Defining a overloaded function
   let us suppose we have system to find name roll other data from a database

   we can define lookup function

   Record lookup(const Account&);
   Record lookup(const Name&);
   Record lookup(const Phone&);

   Account acc;
   Phone ph;
   lookup(acc); // calls account version
   lookup(ph); // calls phone version

   overloaded must differ by number of type of parameter.


   overloading and const parameter
   as we know that top level const has no effect on object that can be passes to the function. hence there is no difference
   between a top level const and and without it.
   eg
   lookup(const acc&);
   lookup( acc&); // both are same and hence redeclaration

   but we can overload on the bases of reference ie it is reference to const or non const. because they are low level const
   hence all are ok:

   Record lookup(const acc&);
   Record lookup( acc&);
   Record lookup(acc*);
   Record lookup(const acc*);

   because there is no conversion from const hence we can pass const object to only const version.
   but there is conversion to const hence we can call from either non const or const. however compiler prefers non const version more when we pass non const object

  const_cast and overloading

  as we have seen const_cast is very useful overloading like in program to find smalls string

  const string &shorterString(const string &s1, const string &s2)
   {
   return s1.size() <= s2.size() ? s1 : s2;
   }

   since this function returns const type and even if we give non const . suppose we want to make it that if passed
   non const then will give non const. we can use const_cast

   string &short(string &s1, string &s2)
   {
      auto &r = shorterString(const_cast<const string&>(s1), const_cast<const string>(s2));
      return const_cast<string &>(r);

    it will cast s1 and s2 into const and then call const version and after the return of that const we again casted it into non const and then returned it.


   calling an overloaded function.

   once we made it . now we need to call them. function matching  is the procedure used to match the correct version

   rules used by compiler -
   1. finds the exact match with exact number and exact type.


   these are possible 3 outcomes during overload call -
   1. it will try to find exact match .
   2. if not found itll give error.
   3. it can give ambiguous  error if found of same type.


   overloading and scope


   name loop up happens before type checking

   features for specialized uses -

   a. default argument -
    sometimes we have parameter that is called often but not every time. in those cases we use default parameter.
    function of such type can be called with or without them .

    typedef string::size_type sz; // typedef see § 2.5.1 (p. 67)
   string screen(sz ht = 24, sz wid = 80, char n   = ' ');

   we can them in following ways

   string window;
    window = screen();
    window = screen(66);// equivalent to screen(66,80,' ')
    window = screen(66, 256); // screen(66,256,' ')
    window = screen(66, 256, '#'); // screen(66,256,'#')

    window = screen(, , '?'); // error: can omit only trailing arguments
     window = screen('?');  // it is not error as ? is implicitly type casted


    pointer to function -
    A function pointer is just that—a pointer that denotes a function rather than an
object. Like any other pointer, a function pointer points to a particular type. A
function's type is determined by its return type and the types of its parameters. The
function's name is not part of its type

 pf = length ;
 pf = &length ; // equivalent assignment
 during call there is no need to dereference it.

 bool b1 = pf("hello", "goodbye"); // calls lengthCompare
bool b2 = (*pf)("hello", "goodbye"); // equivalent call
bool b3 = lengthCompare("hello", "goodbye"); // equivalent call

pointer to overloaded function ---
void ff(int*);
void ff(unsigned int);
void (*pf1)(unsigned int) = ff; // pf1 points to ff(unsigned)


function pointer parameters---

just like array we cant have function parameter but we can have pointer to function as parameter.
void useBigger(const string &s1, const string &s2,
bool pf(const string &, const string &));
// equivalent declaration: explicitly define the parameter as a pointer to function
void useBigger(const string &s1, const string &s2,
bool (*pf)(const string &, const string &));
When we pass a function as an argument, we can do so directly. It will be
automatically converted to a pointer:

// automatically converts the function lengthCompare to a pointer to function
useBigger(s1, s2, lengthCompare);



as it can be tedious we can use type alias with decltype for convince.
typedef bool Func(const string&, const string&);
typedef decltype(lengthCompare) Func2; // equivalent type

typedef bool(*FuncP)(const string&, const string&);
typedef decltype(lengthCompare) *FuncP2; // equivalent type

returning pointer to function --


using F = int(int*, int); // F is a function type, not a pointer
using PF = int(*)(int*, int); // PF is a pointer type

PF f1(int); // ok: PF is a pointer to function; f1 returns a pointer to function
F f1(int); // error: F is a function type; f1 can't return a function
F *f1(int); // ok: explicitly specify that the return type is a pointer to function
Of course, we can also declare f1 directly, which we'd do as
int (*f1(int))(int*, int);

using auto
auto f1(int) -> int (*)(int*, int);


string::size_type sumLength(const string&, const string&);
string::size_type largerLength(const string&, const string&);
// depending on the value of its string parameter,
// getFcn returns a pointer to sumLength or to largerLength
decltype(sumLength) *getFcn(const string &);
The only tricky part in declaring getFcn is to remember that when we apply
decltype to a function, it returns a function type, not a pointer to function type. We
must add a * to indicate that we are returning a pointer, not a function.
return type and return statement--

it terminates a function which is currently executing.
they are of 2 type ;
return ;
return statement
A return with no value may be used only in a function that has a return type of
void. Functions that return void are not required to contain a return. In a void
function, an implicit return takes place after the function's last statement

A function with a void return type may use the second form of the return
statement only to return the result of calling another function that returns void.


The second form of the return statement provides the function's result. Every return
in a function with a return type other than void must return a value.
The value
returned must have the same type as the function return type, or it must have a type
that can be implicitly converted

Failing to provide a return after a loop that contains a return is an error.
The return value is used to initialize a temporary at the call site, and that
temporary is the result of the function call.

Never return reference to local object.
above return second is also wrong as EMPTY is first stored in some temperory variable and then returned.
For the same reasons that it is wrong to return a reference to a local object, it is
also wrong to return a pointer to a local object. Once the function completes, the local
objects are freed. The pointer would point to a nonexistent object



Like any operator the call operator has associativity and precedence (§ 4.1.2, p. 136).
The call operator has the same precedence as the dot and arrow operators (§ 4.6, p.
150).


call to function that return reference always return lvalue other yield rvalue.
then we can assign to function.


list initializing the return value ---

In a function that returns a built-in type, a braced list may contain at most one
value, and that value must not require a narrowing conversion (§ 2.2.1, p. 43). If the
function returns a class type, then the class itself defines how the intiailizers are used.

return from main ---

The main function is allowed to terminate without a return. If
control reaches the end of main and there is no return, then the compiler implicitly
inserts a return of 0.

 To make return values machine
independent, the cstdlib header defines two preprocessor variables (§ 2.3.2, p. 54)
that we can use to indicate success or failure.

int main()
{
if (some_failure)
return EXIT_FAILURE; // defined in cstdlib
else
return EXIT_SUCCESS; // defined in cstdlib
}

main may not call itself.

returning pointer to array -- -
because we cant pass array we cant return array.

typedef int arrT[10]; // arrT is a synonym for the type array of ten ints
using arrtT = int[10]; // equivalent declaration of arrT;
arrT* func(int i); // func returns a pointer to an array of five ints

int arr[10]; // arr is an array of ten ints
int *p1[10]; // p1 is an array of ten pointers
int (*p2)[10] = &arr; // p2 points to an array of ten ints

function returning pointer to array
Type (*function(parameter_list))[dimension]



trailing return type ---

 another way to simplify the declaration of func is by using
a trailing return type. Trailing returns can be defined for any function, but are most
useful for functions with complicated return types, such as pointers (or references) to
arrays.

A trailing return type follows the parameter list and is preceded by ->. To
signal that the return follows the parameter list, we use auto where the return type
ordinarily appears
// fcn takes an int argument and returns a pointer to an array of ten ints
auto func(int i) -> int(*)[10];

using decltype ---
int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,6,8};
// returns a pointer to an array of five int elements
decltype(odd) *arrPtr(int i)
C++ Primer, Fifth Edition
The only tricky part is that we must remember that decltype
does not automatically convert an array to its corresponding pointer type. The type
returned by decltype is an array type, to which we must add a * to indicate that
arrPtr returns a pointer


*/


return 0;

}

