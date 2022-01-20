#include<iostream>
using std::cin; using std::cout;

#include<string>
using std::string;

#include<vector>
using std::vector;
class Foo{
        Foo(); // default constructor.
        Foo(const &Foo); // Copy constructor. Mostly it is reference to const
        Foo& operator=(const Foo&) ; // assignment operator. they should ordinary return reference to left operand.


    };
string dot(10,'.'); // d
//string s(dot); // d
string s2 = dot; // copy
string name = "nikhil"; // copy
string last = string(10,','); // copy

struct NoCopy{
    NoCopy() = default;
    NoCopy(const NoCopy&) = delete; // no copy
    NoCopy &operator= (const NoCopy&) = delete; // no assignment
  // ~NoCopy() = default; // synthesized destructor.
    //~NoCopy() = delete; // synthesized destructor.
private:
    int a = 10;
};
NoCopy *m = new NoCopy();
//delete m;
//NoCopy n( m); // error use of deleted.
//NoCopy n=  m; // error use of deleted.
class Trya{
   // const int a; // error as it has uninitialized const so no default constrctor.
   //int &c ; // error as this is deleted due to absence of in class for reference.
   NoCopy d; // error cuz Nocopy dest is deleted.
};
//Trya a;

//Trya b = a; // error as use of deleted.
//Trya c(a); // error as use of deleted.

class PrivateCopy {
// no access specifier; following members are private by default;
// copy control is private and so is inaccessible to ordinary user code
PrivateCopy(const PrivateCopy&);
PrivateCopy &operator=(const PrivateCopy&);
// other members
public:
PrivateCopy() = default; // use the synthesized default constructor
~PrivateCopy(); // users can define objects of this type but not copy them
};

class Hasptr{
public:
    Hasptr(const Hasptr& given):s(new string(*given.s)), i(given.i){}
    Hasptr(const string & given = string()): s(new string(given)), i(0){}
    Hasptr& operator = (const Hasptr &);
    ~Hasptr(){delete s;};
private:
    string *s;
    int i ;
};
Hasptr& Hasptr::operator=(const Hasptr &rhs)
{
    auto newp = new string(*rhs.s);
    delete s;
    s = newp;
    i = rhs.i;
    return *this;
}
class Hasptr1{
    Hasptr1(const Hasptr1& given): name(given.name), roll(given.roll), use(given.use){++*use;}
    Hasptr1(const string &s =  string()) : name(new string(s)),roll(0),use(new std::size_t(1)) {}
    Hasptr1& operator = (const Hasptr1 &);
    Hasptr1& operator = (Hasptr1 );
    ~Hasptr1()
    {
        if(--*use == 0)
        {
            delete name;
            delete use;
        }
    }
    friend void swap(Hasptr1& , Hasptr1&);
private:
    string *name;
    int roll;
    std::size_t *use;
};
inline
void swap(Hasptr1 &lhs , Hasptr1 &rhs)
{
    using std::swap;
    swap(lhs.name,rhs.name);
    swap(lhs.roll,rhs.roll);

}
Hasptr1& Hasptr1::operator=(const Hasptr1 &rhs)
{
    ++*rhs.use;
    if(--*use==0)
    {
        delete name;
        delete use;
    }
    name = rhs.name;
    roll = rhs.roll;
    use = rhs.use;
    return *this;
}
Hasptr1& Hasptr1::operator=(Hasptr1 rhs)
{
// swap the contents of the left-hand operand with the local variable rhs
swap(*this, rhs); // rhs now points to the memory this object had used
return *this; // rhs is destroyed, which deletes the pointer in rhs
}
int main()
{
    /* Copy control
    As we have seen that each class defines new types and operations
    which can be performed on that type.Now we will know how class will define how type will
    behave when we copy or move.

    5 operation which class defines.

    a. copy constructor.
    b. copy assignment operator.
    c. move assignment operator
    d. move constructor
    e. destructor.

    copy and move constructor defines  what will happen when we initialize a object from same type.
    copy and move operator  defines  what will happen when we assign a object from same type.
    destructor tells what will happen when object destroys.


    COPY
    a.
    A constructor is copy constructor if its first parameter is of reference type and rest are defualt.
    Since it is used in many implicit conversion so it should not be explicit.
    when we dont define copy compiler do that for us but unlike compiler do this even when we dont
    define our own constructor. it is known as synthesized constructor.
    the synthesized copy constructor for some classes prevents us from copying objects of that class type
    otherwise it copies member wise from one class to other class.

    compiler copies each nON Static member.
    It copies elements of array element by element.


    COPY Initialization and direct initialization.
    when we use direct initializtion we ask compiler to use ordinary function matching rule and look for it.
     but in copy we ask compiler to copy the right into left.

    copy Int. mostly use copy constructor but if move is present then it sometimes use move for it.

    copy intialization happens only when we use = but also when
    a. pass an object to non reference type argument.
    b. return from a non reference type.
    c. brace initialize the element of thet array or the member of aggregate class.
    some classes also do this like when we do insert or push but emplace use direct.

    parameters and return value -

    The fact that the copy constructor is used to initialize non reference parameters of
    class type explains why the copy constructor's own parameter must be a reference. If
    that parameter were not a reference, then the call would never succeed to call the
    copy constructor, we'd need to use the copy constructor to copy the argument, but to
    copy the argument, we'd need to call the copy constructor, and so on indefinitely.

    constrain on copy

    vector<int> v1(10); // ok: direct initialization
    vector<int> v2 = 10; // error: constructor that takes a size is explicit
    void f(vector<int>); // f's parameter is copy initialized
    f(10); // error: can't use an explicit constructor to copy an argument
    f(vector<int>(10)); // ok: directly construct a temporary vector from an int
    explicit cant be used for copy initialization.It can be used only with direct initialization.

    during copy initialization compiler can skip copy constructor if he wants to do so.
    ie it can do such thing.

    string s = "aaaaq";
    to
    string s("aaaaq");
    however even if he do so. copy const. must be accessible ie it must not be private.


    COPY aSSIGNMENT


    class Try t1 , t2;
    t1 = t2 ; // copy assignment.


    COPY assignement operator
    class defines this for us if we dont
    sometimes synthesize operator disallow assignement otherwise.
    Otherwise, it assigns each nonstatic
    member of the right-hand object to the corresponding member of the left-hand object
    using the copy-assignment operator for the type of that member.
    they return reference to left operator.



    DESTRUCTOR --
    it works oppositely to the constructor which create non static member it destroy them.
    it has no return and no parameter.
     In a constructor, members are
    initialized before the function body is executed, and members are initialized in the
    same order as they appear in the class.
    in destructor function body is executed first and are destroyed in the reverse order they were created.
    The destructor is not run when a reference or a pointer to an object goes out
   of scope.

   synthesized destructor is defines by class for us. if we dont do. but it is also allowed to disallow some
   destruction.



   we must  always remember rule of 3 and 5
   3.

   copy constructor
   copy assignment operator
   destructor

   5.
   move constructor
   move assignment

   if we allocated memory by ourself and rely on systhesized copy and assignemnt then its wrong as they
   do shallow copy not deep one.

   If a class needs a copy
constructor, it almost surely needs a copy-assignment operator.

   using = default

   we can ask compiler to generate default construct by writing = default.
   it is implicitly inline.

   We can use = default only on member functions that have a synthesized
   version (i.e., the default constructor or a copy-control member).

   preventing copies -- like iostream we can define our own function to prevent copies. if we dont want
   we can prevent such copies by writting deleted functions.
   it is a function which is declared but may not be used in any other way.
   we do so by writting = deletd.


   destructor should not be deleted.
   compiler also sometimes make deleted copy controls for us.

   a. synthesized destructor is  deleted if class has a member whose destructor is inaccessible.
   b. synthesized constrctor is  deleted if class has a member whose cosntrcutor  is inaccessible or itself delted.
   c. same as above for copy assignment and if member is const or reference.
   d. The synthesized default constructor is defined as deleted if the class has a
    member with a deleted or inaccessible destructor; or has a reference member
    that does not have an in-class initializer (§ 2.6.1, p. 73); or has a const
    member whose type does not explicitly define a default constructor and that
    member does not have an in-class initializer.


    In essence, these rules mean that if a class has a data member that cannot be default
constructed, copied, assigned, or destroyed, then the corresponding member will be a
deleted function.
It should not be surprising that the compiler will not synthesize a default constructor
for a class with a reference member or a const member that cannot be default
constructed. Nor should it be surprising that a class with a const member cannot use
the synthesized copy-assignment operator: After all, that operator attempts to assign
to every member. It is not possible to assign a new value to a const object



In essence, the copy-control members are synthesized as deleted when it is
impossible to copy, assign, or destroy a member of the class.


private copy control

since copy and copy assignment are private user will not be able to copy by object.
however friend and member can still uuse them hence we declare but not define them.


copy control and resource management

class that behave as copy value --

to implement such behaviour --
we need copy such that is copies the string not pointer.
a destructor has to free the string.
a copy assignment 1to free obhects existing string and copy from the rhs's string.

There are two points to keep in mind when you write an assignment
operator:
• Assignment operators must work correctly if an object is assigned to itself.
• Most assignment operators share work with the destructor and copy
constructor.
A good pattern to use when you write an assignment operator is to first copy
the right-hand operand into a local temporary. After the copy is done, it is
safe to destroy the existing members of the left-hand operand. Once the left-
hand operand is destroyed, copy the data from the temporary into the
members of the left-hand operand.


DEFIning that behave like pointer

the easies way to do this is to use shared pointer.
however if we want to manage resource directly then we need to use reference count.

now to thing is where to store it. To store it we use dynamic counter.
When we
create an object, we’ll also allocate a new counter. When we copy or assign an object,
we’ll copy the pointer to the counter. That way the copy and the original will point to
the same counter.



SWAP--

writing own swap function --
using swap in assignement --
Classes that define swap often use swap to define their assignment operator. These
operators use a technique known as copy and swap. This technique swaps the left-
hand operand with a copy of the right-hand operand.


A COPY CONTROL EXAMPLE --




    */
    return 0;
}
