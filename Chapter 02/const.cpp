#include<iostream>
#include<string.h>
using namespace std;
constexpr int get_size()
{
    return 3;
}

int main()
{
    /* CONST qualifier
    Sometimes we want to keep the value of a variable constant so that no one else can change it
    in that case we make the variable const.Any try to change the value of that variable will produce
    error. as we can't modify const so it must be initialized .
    const can do almost any operation expect that tries to modify it. eg initialization
    compiler usually replace const values in the code.

    const int x = 6;
   // const int k; error uninitialized const.
  //  x =8;// it will give error as we are trying to modify x
   int i = x;
   const int j = x;

    1. Reference to const
    we can also bind reference to const object but unlike other reference we can't use it to
    change the object
    const int  x = 10;
    const &r = x;
    //r = 41; // error as I'm trying to modify x with const reference
    int &r2 = x; // non const reference to const object it is illegal as x is const so if we use non const reference we may modify the variable with this reference

    2. initialization and reference to const
    we studied that except two cases type of reference must match with type of it refers.
    1st exception is - reference to const may be initialized with the expression which can be
    converted to type of reference.


    int x = 10;
    const int &a = x;
    const int &b = 42;
    const int &c = b*2; // expression can be converted to the type of reference
//    int &d = a; error
    double d = 3.14;
    const int &r = d; // here is of type r but d is of type double so ensure that operation of r would be of int compiler do so.
  //  const int temp = d ;
  //  const int r = temp;

    3. reference to const may refer to a non const object
    int x = 5;
    int &r1 = x;
    const &r2 = x;
    r1 = 15;
  //r2 = 20; it will produce error as it is reference to const

    4. pointer and const
    Like const reference we can have const pointer . We can't change value using pointer
    we can store address of const object only in const pointer
    const int x  = 10;
  //  int *p = &x; // Error as we should store const object in const  pointer only

    We stated earlier that type of pointer must match with the type it match.

    first exception is use we can const to point non const object.
    int x = 5;
    const *p = &x;
   // *p = 10; // error as we can't change it through const pointer.

    5. const pointer
    since pointers are object and hence like other objects we can have pointers which are itself
    const
    const pointers must be initialized when made and once made the value they hold ie the object
    they point will remain forever

    int x = 10;
    const int y = 20;
    int *const p = &x;// it is  const pointer
 //   p = &y; // error as p is const pointer
    const int *const p2 = &y; // const pointer to a const object;

    top level const - when pointer is const.
    low level const - when object to which pointer point is const.
    top and low level matters during copying
    when we copy top levels are ignored


    //const int j = -1;

    const int  &r = 14; // It is OK here because it is reference to const

    //  int  &r1 = 14;
    const int ci = 10;
    int c2 = 20;
    const int *p2 = &ci;
    int *const p3 = &ci;
    const int * const p4 = &ci;
    p3 = &c2; // error because p3 is const pointer
    *p2 = 20; // error because the value to which p2 points is const
    p4 = &c2; // Error because p4 is const pointer
    *p4 = 30; // error because the value to which p4 points is const
    int i = 0;
    int *const p1 = &i; // we can't change the value of p1; const is top-level
    const int ci = 42; // we cannot change ci; const is top-level
    const int *p2 = &ci; // we can change p2; const is low-level
    const int *const p3 = p2; // right-most const is top-level, left-most is not
    const int &r = ci;
    i = ci; // OK: copying the value of ci; top-level const in ci is ignored
    p2 = p3;
    we can convert non - const into const but not const into non const


    6. constexpr and constant expression
    constant expressions are those expression whose values can't be changed and evaluated at compile time
    a literal is a constant expression
    a const object that is initialized by const object are also const


    const int x = 20; // constant expression
    const int y = x+1; // constant expression
    int z = 13; // non constant expression
    const int size = get_size();

    we can ask compiler to check whether expression is const by writting constexpr .
    constexpr int z = 13; //  constant expression
    constexpr int size = get_size(); // constant expression

    7. pointers and constexpr


    both p and q are different because q imposes top level constness */
    const int x = 10;
    int y = 20;
    const int *p = nullptr; // p is a pointer to const object
    p = &y;
//    *p = 100; // error
    constexpr int *q = nullptr; //q is a const pointer to object.
//  q = &x; //error
    *q = 100;

    constexpr const int *p4 = &x;  // p4 is constant pointer pointing to const x









    return 0;
}
