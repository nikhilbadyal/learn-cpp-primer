#include<iostream>
#include<string>
#include<vector>
#include<cctype>
using std::string ; using std::cin ; using std::cout ; using std::cin ; using std::endl; using std::vector;
int main()
{
    /* Fundamental
    There are many operators many are urinary and many are ternary like * , & are urinary while + , - are binary
    some like * are binary as well as ternary operators
    lvalues and rvalues
    lvalues are those which can be on the left side of assignment operator where as rvalues can't
    lvalues yield function or object but lvalues like const may not be on the left of assignment
    Moreover, some expressions yield objects but return
    them as rvalues, not lvalues. Roughly speaking, when we use an object as an rvalue,
    we use the object  value (its contents). When we use an object as an lvalue, we use
    the object  identity (its location in memory).
    WE CAN USE lvalue when r is required but not vice versa
    a. assignment operator usually takes a lvalue returns a reference too the lvalue
    b. & operator takes a lvalue and return a pointer to operand as  rvalue
    c. The built in increment decrement require lvalue and prefix version also yield l value
    d. pre increment and post increment both returns rvalue in C".
     decltype gives reference if the expression gives lvalue
    When we apply decltype to an expression (other than a variable), the result is a reference
    type if the expression yields an lvalue.
    as if we assume p is int* then decltype(*p)  is int& as dereference yield an lvalue.
    on the other hand decltype(&p) is int** as & operator gives rvalue as return

    lvalues yields an object or function. However some lvalues like const may not be on left side of assignment



    1. expression with more than operand are compound expressions
    The arithmetic operators are left associative, which means operators
     at the same precedence group left to right:
     parenthesis overrides both of above


     IO operators are left associative this means we can do cascading
     cin>> x>>y>>z;

    int x = 8;
    int *p = &x;
    //cout<<&(*p);

    int i = 0;
cout << i << " " << ++i << endl; // undefined

    order of evaluation
    precedence defines how operands are grouped it defines nothing how they are evaluated
    for operators that don't define order it is error to refer and change the same object
    as a result ex << defines no order hence the following statement is undefined
    int i = 0;
     cout << i << " " << ++i << endl;


     There are 4 operators that guarantee order
     1. and && left hand will be operated first and right will be operated only if left is ture


     int n=0, s ;
     if(n>1 && cin>>s)
          cout<<"Hello"; // it will not ask s input from me as n is false
     2. OR ||
     3. conditional
     4. comma
     order precedence and associativity
      f() + g() * h() + K() // it is guaranteed here that g and h will be multiplied then
      added to  f and in last added to k*
     . rule of thumb
     a. if you don't know exact use parenthesis
     b. if you change value of an operand then don't use that operand anywhere else .
     well it has some exception that  *++iter. Here ++ will change the vale of iter


     2. arithmetic operators

     they are left associative and urinary(++ ,--) has most precedence , then multi division
    reminder and binary addition subtraction
     There result are rvalue
     small integral type can be converted into larger type like short into int.

     urinary can be applied to pointers

     / - used to find quotient
     % - used to find reminder . its operand must be of int type
    int x = 10;
    float c = 2.14l;
   // c % 12; error as operands are not int
    (m/n)*n + m%n is m

    if m%n is non zero then is has sign of m
    in m/n
    a. (-m/n) = -(m/n)
    b (m/(-n)) = -(m/n)

    c. (-m)%n = -(m%n)
    d. m%(-n) = m%n

       int i = 1024;
    int k = -i; // i is -1024
    bool b = true; //bool  are converted into int hence b into 1 . then negated it ie
   -1 which is not zero and hence b2 is 1 true
    bool b2 = -b; // b2 is true! //-ve numbers is converted to large positive number and then
    1 into bool



    3. lOGICAL AND RATIONAL OPERATORS


    relational - THERE operands are arithmetic or pointer types
    logical - they take any type that can be converted into bool type

    except logical not all have left associativity


    in "and" and "or" left hand operand are evaluated first
    this is known as short circuit evaluation
    and - right will be evaluated only if left is true
    or - right is evaluated only left is false

    int x, c=1;
    if(c || cin>>x)
        cout<<"Hoo"; // here cin won't work

    sometimes when object are too long and we don't want to copy them we use reference for them
    eg in iostream we use it's reference


    vector<string>v1;
    v1.push_back("nikhil is a good boy.");
    v1.push_back("nikhil is a good boy.");
    v1.push_back("nikhil is a good boy.");

    for( auto &s : v1){
        cout<<s;

        if(s.empty()|| s[s.size()-1]== '.')
        cout<<endl;
        else{
            cout<<" ";
        }
    }
    5. logical not
    it negates the truth

    relational have their ordinary meaning and return bool
    they are left associative in nature

    int i = 10 , j = 20, k = 30 ;
    cout<<(i>j>k);

    int x = -100;
    if(x)
        cout<<x;
    if(x == true )
        cout<<"hello";

    6. Assignment operator

    left hand side of this must be an modifiable lvalue
    //literals are rvalues
    arithmetic expressions are rvalue
    result is its left hand operand which is lvalue.. type of result is type of operand
    if type of left and right are different then right is  converted into left
    we can brace internalization on right hand side



     int  i;
     i = {2.9}; // error narrowing conversion if left is built in then brace can have at-most one
     //value and must not have narrowing conversion


     assignment is right associative and returns left side operand


     assignment has lower precedence so we must use parenthesize it to work properly

     int i , j=0;
     if(i=j)
        cout<<"hello";// it will check value of  i by converting it into bool


     compound operators
     a = a op b;


     increment and decrement operators

     they are the short hand way to operation when we only increase or decrease object by 1
     they are of 2 types-
     a. postfix
     b. prefix


     prefix - this form increment its operator and yield it as result
     postfix - this form increment its operator but yield original value as result


     int i = 0 , j = 0;
     cout<<++i;
     cout<<j++;
     // both of them require l value prefix return the object itself as lvalue
     //postfix return copy of original as rvalue
     vector<int>v1;
     v1 = {1,2,3,4,5};
     auto b = v1.begin();
     while(b != v1.end() )
        cout<<*b++<<endl;  // it will increment b ie b+1 but it will return b so we get 1 result

     int x = 10;
     int i = 0;
     i = i++;


     member access operator

     since dereference has less precedence than dot hence we must parenthesize
     it requires a pointer operand and yields an lvalue


     The dot operator yields an lvalue if the object from which the member is fetched is
     an lvalue otherwise the result is an rvalue.


     7. conditional operator

     it helps us in simply implementing if else condition. it has form cond ? expr1 : expr2

     if condition is true then expr1 is evaluated otherwise expr2 is evaluated

    int grade = 100;
    (grade <60) ? cout<<"pass" : cout<<"fail";
    result is lvalue if both are lvalue or can be converted otherwise rvalue

    nesting of operators


    int grade = 100;
    (grade <60) ? cout<<"fail" :
                (grade>90)? cout<<"Good marks": cout<<"Not that good";

    // it is right associative
    int grade = 100;
   // cout << ((grade < 60) ? "fail" : "pass");
   cout << (grade < 60) ? "fail" : "pass";  // because conditional has low precedence
    cout<<(grade<60);
    cout ? "0" : "1"; //execution of above statement

   // cout << grade < 60 ? "fail" : "pass"; //error as it compared cout and 60


   Bitwise operator

   they take operands of integral type and use them as collection of bits

   left associative

   ~ bitwise not
   << left shift
   >> right shift
   & bitwise and
   ^ bitwise XOR
   | bitwise or
   operands can be signed or unsigned
   if we use signed bit for these and `number is negative then the way in which they will yield
    results are machine dependent
    s better use unsigned for these operations


  we have already seen << and >> operators that IO library use. But the built in operation of these
  operators are shifting of bits
  they yield as copy of left hand by shift the bits as directed by right hand
  the rhs must not be a negative value and must be strictly less than the no. of bits in  the
  overall result.
  bits that are shifted off the end are discarded

  left shift of c and y ie x<<y is equal to x multiplied by 2^y
  it adds zeros to the right
  behavior of right shift depends on left operand. if operand is  unsigned then zeros are added to
  left . if it is signed then its implementation dependent either copies of sign bit or zeros are added.


  bitwise not - it inverts all bits of the operand ie 1 to 0 and  0 to 1

  bitwise and or xor -- performs these operation with each bit

  using bitwise operators
  unsigned long quiz = 0; // since we have 30 students and long has min of 32 bit so we can use it
//  cout<<quiz<<endl;
  1UL<<27; //indicating that 27th  students passed
 // cout<<(1UL<<27)<<endl;
  quiz  |= 1UL<<27; // to set that 27th passed
  //cout<<quiz;
  bool status = quiz & (1UL << 27);
  cout<<status<<endl;
  quiz &= ~(1UL<<27);
  status = quiz & (1UL << 27);
  cout<<status<<endl;

  shift operators are left associative

  hence statement like
  cout<<""hi"<<"I'm"; works like
  (cout<<"Hii")<<"I'm";

  The shift operators have mid level precedence: lower than the arithmetic operators
  but higher than the relational, assignment, and conditional operators


  size of operator

  it gives size of object in bytes.It is right associative
  It's result is const object hence we can use it to initialize array


  it is of two types
  sizeof type;
  sizeof (exp)
   in second case it uses the return type of expression to evaluate expression

   string s = ("nikhil");
   cout<<sizeof(s);

   comma operator -- it operates from left to right
   left hand value is evaluated an discarded and then right is evaluated and assigned then(right one)
   it can be used in for loops



   vector<int>v(10);
   vector<int>::size_type cn = v.size();

   10 Types conversions

   in c++ some types are related to each other so we can expect from them that they can be converted into type
   of one another




   int x = 88 + 3.68; // compiler might warn about loss of precision
   implicit conversion are done to preserve precision if possible. if operands are int and float , int is
   converted to float and result is float.
   auto i= 3 + 4.6;
   cout<<i<<endl;


   next comes initialization . the type of object to which we are initializing dominates.

   when implicit conversion occurs

   1. if operand are smaller than ints, they are converted to int type
   2. in conditions non bools are converted to bool.
   3. in initialization , type of object to which we are initializing dominates.
   4. in assignment the lhs is converted to rhs
   4. In arithmetic and relational expressions with operands of mixed types, the types
    are converted to a common type.

    a. Arithmetic conversions -
    the rule of hierarchy says that operators are converted to widest type.
    if one type is long int no matter what other is they will be converted into long

    a.1 - integral conversions
     converts the small into large ints
      bool, char, signed char, unsigned char, short, and unsigned short all are converted to ints
      otherwise value is  converted to unsigned int.

      The larger char types (wchar_t, char16_t, and char32_t) are promoted to the
    smallest type of int, unsigned int, long, unsigned long, long long, or
    unsigned long long in which all possible values of that character type fit.



    a.2 - operands of unsigned type

    integral promotions happen first. If the resulting type(s) match, no further
   conversion is needed. If both (possibly promoted) operands have the same
    signedness, then the operand with the smaller type is converted to the larger type.


    same sign - different type-- smaller into larger
    unsigned  type same or larger than signed - different sign ---- signed is converted into unsigned

    unsigned int and int -- int will go to unsigned int
    int x = -5;
    unsigned int y ;
    y = x;
    cout<<y;
    char c = 'a';
    short s = 1;
    cout<<c+s;
    int x = c+s;
    cout<<x;


    b . other implicit conversions

    array to pointer - most of the  time when we use array they are converted into array pointer
    well they are not converted if used with decltype , & , sizeof , typeid
    The conversion is also omitted when we initialize a reference to an array

   pointer conversion - a constant integral value 0 or nullptr can be converted into any type
   any non const pointer can be converted void* and pointer to any object can be converted into
   const void *


   conversion to bool - there is conversion from arithmetic to pointer type

   char *cp = get_string();
  if (cp) // true if the pointer cp is not zero
  while (*cp)  // true if *cp is not the null character


    conversion to const

    we can convert pointer to a non const type to a pointer to const type and same for reference


    int i;
    const int &j = i; // convert a nonconst to a reference to const int
    const int *p = &i;
    i++;
    // reverse is not allowed.

    class conversions -
    class can define its own conversion for its class. compiler will apply only one conversion at a time

    string s = "nikhil" // string literal converted to type string
    while(cin>>s) // here class define conversion from iostream to bool



    explicit conversions -


    sometimes we need to forcefully convert one type to another then we take use of cast

    cast-name<type>expression;
    if type is reference then result is lvalue
    cast name can be any of these-  static_cast, dynamic_cast, const_cast, and reinterpret_cast
    we also have dynamic_cast which is used at run time.

    1. static_cast - well know defined conversion other than low level const can be used for it
    eg we can force to use floating point division to by casting one of them to double;
    int x = 19 , y = 29;
    double slope = static_cast<double>(j) / i;
    it is also useful when a large arithmetic is assigned to smaller type. it informs both the reader and compiler that we know
    about the precision loss and are worried about it .  it can turn off warning during assignment to large types to smaller types

    it can also do conversions that compiler will not do .
    double d ;
    void *p = &d;
    double *dp = static_cast<double *>(p);


    2. const_cast -
    it changes only low level const in its operand
    const char *pc;
   char *p = const_cast<char*>(pc); // ok: but writing through p is undefined
 int x1 = 10;
   const int *x = &x1;
//   int *q = x; invalid
//   *x =10;
    int *p = const_cast<int*>(x);//ok but writting by p is undefined
    *p = 100;
    cout<<x1;


    we can only use const cast to take away constness no any other


   const  char *p ;
 //   char *q = static_cast<char*>(p); //error
  //  char *q = const_cast<char *>(p);
 //   char *r = const_cast<string >(p); // it only change constness not type
    string s = static_cast<string>(p);
    s[0] = 's';

    reinterpret_cast

    A reinterpret_cast generally performs a low-level reinterpretation of the bit pattern of its operands

    int *i =
    \*/

 //   *x = 10;
  // cout<<


    return 0;
}
