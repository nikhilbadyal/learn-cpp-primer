#include<iostream>
using std::cin; using std::cout;

#include<vector>
using std::vector;


#include<string>
using std::string;

int main()
{
    /*  CLASS
    data abstraction , dynamic binding , inheritance
In C++, a base class distinguishes functions that are type dependent from those that
it expects its derived classes to inherit without change. The base class defines as
virtual those functions it expects its derived classes to define for themselves.


the new standard lets a derived class explicitly note that it intends a
member function to override a virtual that it inherits.

Dynamic binding
Through dynamic binding, we can use the same code to process objects of either
type Quote or Bulk_quote interchangeably.
In C++, dynamic binding happens when a virtual function is called through a
reference (or a pointer) to a base class.

classes used as the root of an
inheritance hierarchy almost always define a virtual destructor.

Any nonstatic member
function (§7.6, p. 300), other than a constructor, may be virtual.

the new
standard lets a derived class explicitly note that it intends a member function to
override a virtual that it inherits. It does so by specifying override after the
parameter list, or after the const or reference qualifier(s) if the member is a const
(§7.1.2, p. 258) or reference (§13.6.3, p. 546) function.

Because a derived object contains subparts corresponding to its base class(es), we
can use an object of a derived type as if it were an object of its base type(s). In
particular, we can bind a base-class reference or pointer to the base-class part of a
derived object.

Although a derived object contains members that it inherits from its base, it cannot
directly initialize those members.

If a base class defines a static member (§7.6, p. 300), there is only one such
member defined for the entire hierarchy. Regardless of the number of classes derived
from a base class, there exists a single instance of each static member.


A derived class is declared like any other class (§7.3.3, p. 278). The declaration
contains the class name but does not include its derivation list

Sometimes we define a class that we don’t want others to inherit from. Or we might
define a class for which we don’t want to think about whether it is appropriate as a
base class. Under the new standard, we can prevent a class from being used as a
base by following the class name with final:

There Is No Implicit Conversion from Base to Derived ...
Bulk_quote bulk;
Quote *itemP = &bulk; // ok: dynamic type is Bulk_quote
Bulk_quote *bulkP = itemP; // error: can't convert base to derived
The compiler has no way to know (at compile time) that a specific conversion will be
safe at run time. The compiler looks only at the static types of the pointer or
reference to determine whether a conversion is legal. If the base class has one or
more virtual functions, we can use a dynamic_cast (which we’ll cover in §19.2.1 (p.
825)) to request a conversion that is checked at run time. Alternatively, in those cases
when we know that the conversion from base to derived is safe, we can use a
static_cast (§4.11.3, p. 162) to override the compiler.

When we initialize or assign an object of a base type from an object of a
derived type, only the base-class part of the derived object is copied, moved,
or assigned.S The derived part of the object is ignored.


VIRTUAL



As we've seen, in C++ dynamic binding happens when a virtual member function is
called through a reference or a pointer to a base-class type (§15.1, p. 593). Because
we don't know which version of a function is called until run time, virtual functions
must always be defined. Ordinarily, if we do not use a function, we don't need to
supply a definition for that function (§6.1.2, p. 206). However, we must define every
virtual function, regardless of whether it is used, because the compiler has no way to
determine whether a virtual function is used.

final and override

Virtual are resolved at run time only if the call is made through a
reference or pointer. Only in these cases is it possible for an object's
dynamic type to differ from its static type.

it is legal for a derived class to define a function with
the same name as a virtual in its base class but with a different parameter list. The
compiler considers such a function to be independent from the base-class function. In
such cases, the derived version does not override the version in the base class. In
practice, such declarations often are a mistake-the class author intended to override
a virtual from the base class but made a mistake in specifying the parameter list.
Finding such bugs can be surprisingly hard. Under the new standard we can specify
override on a virtual function in a derived class

Finding such bugs can be surprisingly hard. Under the new standard we can specify
override on a virtual function in a derived class. Doing so makes our intention clear
and (more importantly) enlists the compiler in finding such problems for us. The
compiler will reject a program if a function marked override does not override an
existing virtual function

We can also designate a function as final. Any attempt to override a function that
has been defined as final will be flagged as an error:

inal and override specifiers appear after the parameter list (including any const
or reference qualifiers) and after a trailing return (§ 6.3.3, p. 229).

Virtual Functions and Default Arguments
Like any other function, a virtual function can have default arguments (§ 6.5.1, p.
236). If a call uses a default argument, the value that is used is the one defined by
the static type through which the function is called.

Virtual functions that have default arguments should use the same argument
values in the base and derived classes.

That is, when a call is made through a reference or pointer to base, the default
argument(s) will be those defined in the base class. The base-class arguments will be
used even when the derived version of the function is run. In this case, the derived
function will be passed the default arguments defined for the base-class version of the
function. If the derived function relies on being passed different arguments, the
program will not execute as expected.

Why might we wish to circumvent the virtual mechanism? The most common reason
is when a derived-class virtual function calls the version from the base class. In such
cases, the base-class version might do work common to all types in the hierarchy. The
versions defined in the derived classes would do whatever additional work is particular
to their own type.

If a derived virtual function that intended to call its base-class version omits
the scope operator, the call will be resolved at run time as a call to the
derived version itself, resulting in an infinite recursion.

we’d like to prevent users from
creating Disc_quote objects at all. This class represents the general concept of a
discounted book, not a concrete discount strategy.
We can enforce this design intent—and make it clear that there is no meaning for
net_price—by defining net_price as a pure virtual function. Unlike ordinary
virtuals, a pure virtual function does not have to be defined. We specify that a virtual
function is a pure virtual by writing = 0 in place of a function body (i.e., just before
the semicolon that ends the declaration). The = 0 may appear only on the declaration
of a virtual function in the class body:


It is worth noting that we can provide a definition for a pure virtual. However, the
function body must be defined outside the class. That is, we cannot provide a function
body inside the class for a function that is = 0.

Classes with Pure Virtuals Are Abstract Base Classes
A class containing (or inheriting without overridding) a pure virtual function is an
abstract base class.

it defines an interface for derived classes to override.We cant create object of abstract class.

a derives class constructor can call it base class constructor only

For any given point in your code, if a public member of the base class
would be accessible, then the derived-to-base conversion is also accessible,
and not otherwise.

friendship is not inherited.

A derived class may provide a using declaration only for names it is
permitted to access.



class scope under inheritance

If a name is unresolved within the scope of the derived
class, the enclosing base-class scopes are searched for a definition of that name.

A derived-class member with the same name as a member of the base class
hides direct use of the base-class member


As we’ve seen, functions declared in an inner scope do not overload functions
declared in an outer scope (§6.4.1, p. 234). As a result, functions defined in a derived
class do not overload members defined in its base class(es). As in any other scope, if
a member in a derived class (i.e., in an inner scope) has the same name as a base-
class member (i.e., a name defined in an outer scope), then the derived member
hides the base-class member within the scope of the derived class.




    */
    return 0;
}
