#include<iostream>
using namespace std;
int f()
{
    return 3;
}
int main()
{
    /* dealing with types
    1. type alias - it means the synonymous of the name

    a. using typedef

    typedef int inta; // inta  means int
    typedef inta intaa , *intp; //intaa means inta which in turn means int and intp means int *
    inta x = 2;
    intaa y = 10;
    intp z = &x;

    b. using "using"
    using inta =  int ; // inta  means int
    using intaa = inta  ;
    inta x = 2;
    intaa y = 10;

    2. pointers and const
    typedef char name;
    typedef name *namep;
    const namep stringa = 0;
//    stringa = 12; // error as stringa  is a constant pointer to char
  //  const namep *const str ; // error as i didn't initialized constant string
    const namep *sp ;// pointer to constant  pointer to char

    3. auto keyword

    compiler automatically decides what should be the type for the variable
    int i =8 , j =9;
    auto x =  i+j; // here x is int type;
    double a = 3.6 , b = 9.6;
    auto y = a+b; // here y is double type

   // auto s = 0 , p = 3.14; //error
    auto k = 3 , *p = &k;

    //int i = 0 , &r = i;
   // auto a = r  ;// a is of type int as r is alias of type int
    // auto ignores top level consts
    const int i = 10 , &c = i;
    int d  = 0;
    auto b =  i; // b is int as i was has top level const
    auto c1 = c; // c1 is top level const
    auto d1 = &d // d1 is int*
    auto e = &i // e is const int* ( & of i is of low level const)

   // when we ask for reference top level const are not ignored.
   const int i = 10 , &c = i;
   auto &g  = i; // g is const int &
 //  auto &h = 42 // error cant bin plain int .
   const auto &j = 42; // OK we can bind const literal


   4. decltype when we want a type which a function return but don't want to initialize it
   then we use decltype

 //   decltype(f()) sum ;// sum is of int type
     const int y = 10;
     const int x = 5 , &r = x;
     decltype(x) a = 5; // a is const int
     decltype(r) b  = y; // b is int&
  //   decltype(x) c ; //error

    5. decltype and references

    int i = 42, *p = &i, &r = i;
    decltype(r + 0) b; // ok: addition yields an int; b is an (uninitialized) int
    decltype(*p) c;

    decltype((variable)) is reference but decltype(variable) is reference only if variable is reference
    */






    return 0;
}
