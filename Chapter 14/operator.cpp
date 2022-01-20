#include<iostream>
using std::cin ; using  std::cout;

#include<string>
using std::string;

class Small{
public:
    Small(int i = 0) :value(i)
    {
        if(i<0 || i>256)
        {
            throw std::out_of_range("Bad Value");
        }

    }
    operator int() const {return value;}
private:
    std::size_t value;
};
Small s = 3;
int main()
{
    /*
Overloaded operators are functions with special names: the keyword operator
followed by the symbol for the operator being defined. Like any other function, an
overloaded operator has a return type, a parameter list, and a body.
Except the call() operator these may not have default parameter.
If an operator function is a member function, the first (left-hand) operand is bound
to the implicit this pointer (§ 7.1.2, p. 257). Because the first operand is implicitly
bound to this, a member operator function has one less (explicit) parameter than
the operator has operands.

we call them normally but we can do so like,
data1 + data2; // normal call
operator+(data1 , data2);
Ordinarily, the comma, address-of, logical AND , and logical OR operators
should not be overloaded.

• The assignment (=), subscript ([]), call (()), and member access arrow (->)
operators must be defined as members.
• The compound-assignment operators ordinarily ought to be members. However,
unlike assignment, they are not required to be members.
• Operators that change the state of their object or that are closely tied to their given
type such as increment, decrement, and dereference usually should be
members.
• Symmetric operators those that might convert either operand, such as the
arithmetic, equality, relational, and bitwise operators usually should be defined
as ordinary nonmember functions.


<< overloading

Ordinarily, the first parameter of an output operator is a reference to a nonconst
ostream object. The ostream is nonconst because writing to the stream changes
its state. The parameter is a reference because we cannot copy an ostream object.
The second parameter ordinarily should be a reference to const of the class type
we want to print. The parameter is a reference to avoid copying the argument. It can
be const because (ordinarily) printing an object does not change that object.
To be consistent with other output operators, operator<< normally returns its
ostream parameter.


relational
Ordinarily, we define the arithmetic and relational operators as nonmember functions
in order to allow conversions for either the left- or right-hand operand. parameter should be
const2.


Ordinarily the relational operators should
1. Define an ordering relation that is consistent with the requirements for use as
a key to an associative container (§ 11.2.2, p. 424); and
2. Define a relation that is consistent with == if the class has both operators. In
particular, if two objects are !=, then one object should be < the other.



subscipt ---
Classes that represent containers from which elements can be retrieved by position
often define the subscript operator, operator[]. it mus be member.
To be compatible with the ordinary meaning of subscript, the subscript operator
usually returns a reference to the element that is fetched. By returning a reference,
subscript can be used on either side of an assignment. Consequently, it is also usually
a good idea to define both const and nonconst versions of this operator. When
applied to a const object, subscript should return a reference to const so that it is
not possible to assign to the returned object.

increment and decrement
The increment (++) and decrement (--) operators are most often implemented for
iterator classes. These operators let the class move between the elements of a
sequence. There is no language requirement that these operators be members of the
class. However, because these operators change the state of the object on which they
operate, our preference is to make them members.
it generally has type:

operator type() const;
Conversion operators can be defined for any type
(other than void) that can be a function return type (§ 6.1, p. 204). Conversions to
an array or a function type are not permitted. Conversions to pointer types—both data
and function pointers—and to reference types are allowed.

Although the compiler will apply only one user-defined conversion at a time (§
4.11.2, p. 162), an implicit user-defined conversion can be preceded or followed by a
standard (built-in) conversion (§ 4.11.1, p. 159). As a result, we can pass any
arithmetic type to the SmallInt constructor. Similarly, we can use the converion
operator to convert a SmallInt to an int and then convert the resulting int value
to another arithmetic type:

Although a conversion function does not specify a return type, each
conversion function must return a value of its corresponding type:

Conversion to bool is usually intended for use in conditions. As a result,
operator bool ordinarily should be defined as explicit.
*/
    return 0;
}
