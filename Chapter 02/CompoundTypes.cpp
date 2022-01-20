#include<iostream>
using namespace std;
int main()
{
    /* Type defined in terms of other type
    1. Reference( lvalue reference)
    alternative name for an object. it must refers to another object. begins with & and then name i.e. &j
    int i = 5;
    int &j = i;
  //  int &k ; // It must be binded with some object. once binded there is no way to change it blindness So reference must be initialized.
   int &k = j;
   k = k+1;
   cout<<k;
    cout<<j;
    int i = 5 , j= 10;
    int &k = i , l = j; // k is reference but l is int;
    int &k =10; // Error reference must bound to object.
    double a = 3.5;
    int &i = a; // error both types must be same.

    2. Pointers( they points to other type. They are itself an object. So we can have pointer to pointer unlike references.
    a. Pointers can be assigned and re- assigned to other types in his life;
    b. They don't need to be initialized while creating.
    c. Like inbuilt types they have undefiened value  in block scope if  not initialized.
     we use * to denotes pointer then it's name like *d .
     it stores the address of the type to which it points and we get address by using & operator
     since references are not object so they don't don't have address so we can't have pointer to reference
     type of value to which it points and type of pointer must match.

    int i  = 5;
    int *k = &i;
    int *j = k;
    Pointer can store following things
    a. it can point to object.
    b.  It can point to the location just immediately past the end of an object.
    c. it can be null pointer indicating that it is not bounded by an object.
    d. it can be invalid , values other three above three are invalid.

    when the object points to an object we use * to access that object.


    int i = 5;
    int *j = &i;
    *j = 10;
    cout<<i;

    a. NULLPTR
    nullptr doesn't point to any object.


    int *p = nullptr; // equals to int* p =0 ;
    int *p1   =0 ;
    int *p2 = NULL;
    cout<<p2<<p<<p1;
    int zero =0;
   // int *p2 = zero; // it gives error

    // it is advised to initialize all pointers while creating them
    int i = 42;
    int *pi = 0; // pi is initialized but addresses no object
    int *pi2 = &i; // pi2 initialized to hold the address of i
    int *pi3; // if pi3 is defined inside a block, pi3 is uninitialized
    pi3 = pi2; // pi3 and pi2 address the same object, e.g., i
    pi2 = 0; //pi2 doesn't point to any object
    p = &x // p changes
    *p = 0 // value of p changes


    int p = 0;
    int *ptr =&p;
    int *ptr2 = 0;
    if(ptr)
        cout<<"Hello";
    // we can use pointer in conditional statements

    // we can use pointer with == and != operators . two pointers are equal if there addresses are same
    b. void pointer
    int i = 5 , *ip = &i;
    void *v = &i; // i can be of any type
    v = ip; // v can hold pointer to any type

    int i = 5 , *ip = &i , &ri = i;
    *ip += *ip;
    cout<<*ip<<ri;
    ri += ri;
    cout<<*ip<<ri;

    c. Pointer to pointer

    int p = 7 , *p1 = &p , **p2 = &p1;
    cout<<"Value of p is \n"
        <<"Direct Value "<<p<<"\n"
        <<"Through pointer "<<*p1<<"\n"
        <<"Through pointer to pointer "<<**p2<<endl;

    d. Reference to pointers
    // reference is not a object hence we can't have pointer to reference but we can have reference to pointers
    int i = 10;
    int &r = i; // reference to int
    int *p;
    int *&rp = p; // reference to pointer
    rp = &i; // rp is reference to pointer and assigning i to to makes p point to i;
    cout<<*p<<*rp; // dereferencing i rp will give i as rp is another name of p.
    *rp = 0;  // dereferencing it, makes i =0;
    // read from right to left

    cout<<*p; */
    const int &j =0;
//    int &x = 0;









    return 0;
}
