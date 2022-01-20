#include<iostream>
#include<string>
#include<vector>
#include<cctype>
#include<stdexcept>
#include<array>
#include<deque>
#include<forward_list>
#include<list>
using std::string ; using std::cin ; using std::cout ; using std::cin ; using std::endl; using std::vector; using std::runtime_error;
using std::array;
int main()
{
    /*
library defines some sequential container which we can use for accessing data sequentially.
some of these are -
1. vector - supports fast random access.insertion or deleting elements except at back may be slow.
2. double - double ended queue. supports random access. fast insertion deletion at back.
3. list - doubly list
4. forward list - singly list
5. array - fixed size
6. string - special container that contain character fast add/delete at end.


Unless you have a reason to use another container, use a vector.
• If your program has lots of small elements and space overhead matters, don't
use list or forward_list.
• If the program requires random access to elements, use a vector or a deque.
• If the program needs to insert or delete elements in the middle of the container,
use a list or forward_list.
• If the program needs to insert or delete elements at the front and the back, but
not in the middle, use a deque.
• If the program needs to insert elements in the middle of the container only
while reading input, and subsequently needs random access to the elements:
-  First, decide whether you actually need to add elements in the middle of a
container. It is often easier to append to a vector and then call the library
sort function (which we shall cover in  10.2.3 (p. 384)) to reorder the
container when you're done with input.
     array<int,10>s;
     vector::ends
//     s.iterator;


Operations-

some operations are provided by all containers which are -

1. iterator - type of iterator for this container.
2. const_iterator - iterator that can read but not write.
3. size_type -  unsgined integral type sufficient to hold any any possible size of container.
4. difference_type - large enough to hold difference of two iterators.
5. value_type - element value
6. reference - lvalue_type , equivalent to value_type&.
7. const_reference - const value_type&.

construction -
C c; default constructor.
C c(c1) ; construct c copy of c1; // copy
C c(b,e) ; copy elements from iterators range but not for array.
C c{a,b,c,v,} - list initialization.

assignment -
c1 =c2 ;// replace c2 with c1
c1 = {a,v,f,f,b} ; replace elements in c1 with those in list not for array..




    std::list<int>l{1,2,3,4,5,6};
    std::list<int>c(l);
    c.swap(l);
    cout<<c.size()<<endl;
    cout<<c.max_size()<<endl;
    cout<<c.empty()<<endl;
    auto  d = c.cbegin();
    c.insert(d,2);;
    c.erase(d++);

    std::list<int>ss(10);
    for(const auto i: ss)
        cout<<i<<endl;
    std::list<int>ss1(10,10);
    for(const auto i: ss1)
        cout<<i<<endl;

    iterators-


as with containers, iterators has common interface.with exception of forward_list.
iterators support basic operations.like ++ , == .exception is with forward_list as it doesnt support --
operator.
iterator range is the pair of iterators in which iterators are valid. ie point to object or past end off an object.
this range is called left inclusive range.
if begin = end ...container empty.
if begin not equal to end then there is at-least one element and begin points to first.
we can increment begin until begin == end.


container type members-

std::list<string>::iterator iter;
std::vector<int>::difference_type count;


std::list<string>a = {"nikhil","aikhil","tania"};
auto i1 = a.begin();
auto i2 = a.end();
auto  i3 = a.rbegin();
auto i4 = a.rend();
i2-- ;
i4--;
cout<<*i1<<endl;
cout<<*(i2)<<endl;
cout<<*(i3)<<endl;
cout<<*i4<<endl;

defining and initializing container--

every container type defines default constructor except array.
so we can make empty container of that type.

there are two ways to create container we can copy on to the another or we can specify the range
denoted by iterators.
during copy the type and size of both iterators must be same.
but in other case it is good as long as casting is ok.



std::list<string>a = {"nikhil","aikhil","tania"};
std::vector<const char *>ch = {"an","the","is"};
std::list<string>a2(a);
//std::deque<string>d(a); error container mismatch.
//vector<string> words(ch); // error: element types must match // type mismatch.
std::forward_list<string> words(ch.begin(), ch.end());

if addition to size , sequentail container except array can be initialized with a particular
 value like.
vector<int> v(10,10);
for(auto i : v)
    cout<<i;

we can use this only with built in type or class type that has default constructor.


library arrays have fixed size.
It is worth noting that although we cannot copy or assign objects of built-in array
types (§ 3.5.1, p. 114), there is no such restriction on array


swap(c1,c2) - swap is usuaaly faster than copy.

seq.assign(beg,end) - replace element elements in seq as defined by beg and end..
seq.assign(il) - replace element of seq with initializer list il.

After the first assignment, the left- and right-hand containers are equal. If the
containers had been of unequal size, after the assignment both containers would have
the size of the right-hand operand. After the second assignment, the size of c1 is 3,
which is the number of values provided in the braced list.


Using assign (Sequential Containers Only)

the assign require that left and right must have same type.
it copies all elements from right hand to the left hand.there also exist a assign member which let us
assign us from a different but compatible type or assign from subsequence of a container.
the assign operation replaces all the elements in the
left-hand container with (copies of) the elements specified by its arguments.

std::list<string>names;
vector<const char*> oldstyle;
//names = oldstyle; //type mismatch
names.assign(oldstyle.begin(), oldstyle.end()); // ok const char * converted to string/
unsigned int i = -1;
cout<<i;


another version of assign take 2 parameter. one the size and another the parameter you want to copy.
like.

list<string> slist1(1); // one element, which is the empty string
slist1.assign(10, "Hiya!"); // ten elements; each one is Hiya !

swap --
it changes the content of two object and after swap the content is interchanged.
vector<string> svec1(10); // vector with ten elements
vector<string> svec2(24); // vector with 24 elements
swap(svec1, svec2);
After the swap, svec1 contains 24 string elements and svec2 contains ten. With
the exception of arrays, swapping two containers is guaranteed to be fast—the
elements themselves are not swapped; internal data structures are swapped
The fact that elements are not moved means that, with the exception of string,
iterators, references, and pointers into the containers are not invalidated. They refer
to the same elements as they did before the swap

vector<int>v1{1,2,3,4,5,6,7};
vector<int>v2{11,12,13,14,15};
vector<int>::iterator iter ;
auto b = v1.begin();
b = b+2;
cout<<*b<<endl;
v1.swap(v2);
cout<<*b<<endl;
//vector::iterator iter ;

container size --

With one exception, the container types have three size-related operations. The size
member (§ 3.2.2, p. 87) returns the number of elements in the container; empty
returns a bool that is true if size is zero and false otherwise; and max_size
returns a number that is greater than or equal to the number of elements a container
of that type can contain


relational --

The right- and left-hand operands must be the same kind of container
and must hold elements of the same type.



sequential container operations ---

adding elements --

except all container provide flexible in size.
some of the operations are --


1.  c.push_back(t)-- create an elements  with value t at the end and return void.
2, c.emplace_back(t) -- same as 1st.
3. c.push_front(n) --
4. c.emplace_front(n)--- insert at front.
5. c.insert(itr,p)
6. c.emplace(itr,p) -- above both insert p at position pointed by itr.
7. c.insert(p,n,t) --- insert n elements with value t before the elements denoted by
iterator p.
8 c.insert(p,b,e) --- insert elements denoted by range b and e before the element denoted by iterator p
both above return iterator to the first element inserted.
9. c,insert(p,il) - il is initializer list , it insert elements before the element pointed by iterator.


using pus_back --
like sequential we can we push_back() here too --
string s;
while(cin>>s)
    container.push_back();
value of that element is a copy of word.
type can be list , deque , vector.
since string is also a container we can use push_back to add in the end of it.


using push_front() ---
in addition to push_back they also support pus_front.
both list and deque.
Note that deque, which like vector offers fast random access to its elements,
provides the push_front member even though vector does not

adding at specific point---
The insert members are supported for vector, deque, list, and string.
forward_list
it insert at front . so even though some container dont define push_front, we can use it for that task like in
vector but in vector it is costly operation.

inserting a rang of elements ----

using return for insert---

list<string> 1st;
auto iter = 1st.begin();
while (cin >> word)
iter = 1st.insert(iter, word); // same as calling push_front

using emplace --

the new standard introduce new emplace which create element rather copying them.
When we call a push or insert member, we pass objects of the element type and
those objects are copied into the container. When we call an emplace member, we
pass arguments to a constructor for the element type. The emplace members use
those arguments to construct an element directly in space managed by the container.

The call to emplace_back and the second call to push_back both create new
Sales_data objects. In the call to emplace_back, that object is created directly in
space managed by the container. The call to push_back creates a local temporary
object that is pushed onto the container.

The emplace functions construct elements in the container. The arguments to
these functions must match a constructor for the element type


accessing  elements-

c.front() --- return reference to first element in c.
c.back() --- return reference to second element in c..
c[n] -- return reference to element indexed by unsigned value n . if n>c.size() it is undefined.


each container has front member except forward_list every has back too.

// check that there are elements before dereferencing an iterator or calling front or
back
if (!c.empty()) {
// val and val2 are copies of the value of the first element in c
auto val = *c.begin(), val2 = c.front();
// val3 and val4 are copies of the of the last element in c
auto last = c.end();
auto val3 = *(--last); // can't decrement forward_list iterators
auto val4 = c.back(); // not supported by forward_list
}

The end iterator refers to the
(nonexistent) element one past the end of the container. To fetch the last element we
must first decrement that iterator

the access member return reference --


if (!c.empty()) {
c.front() = 42; // assigns 42 to the first element in c
auto &v = c.back(); // get a reference to the last element
v = 1024; // changes the element in c
auto v2 = c.back(); // v2 is not a reference; it's a copy of c.back()
v2 = 0; // no change to the element in c
}

subscripting and safe random access ---

If we want to ensure that our index is valid, we can use the at member instead.
vector<string> svec; // empty vector
cout << svec[0]; // run-time error: there are no elements in svec!
cout << svec.at(0); // throws an out_of_range exception

erasing element --

just as there are many methods to add there are many method to remove----

c.pop_back () - removes last element from the container.
c.pop_front() -- removes first . both are undefined is c is empty.return void.
c.erase(p) - removes the element denoted by iterator p and return itr to next element.
c.erase(b,e)  -- removes element in the range return itr to the element after the last deleted one.
c.clear() --- removes all elements .



pop front and back ---

The pop_front and pop_back functions remove the first and last elements,
respectively. Just as there is no push_front for vector and string, there is also
no pop_front for those types. Similarly, forward_list does not have pop_back.


operation by forward_list ---

lst.before_begin() -- iterator denoting the non existing element.it may  not be dereferenced.
lst.cbefore_begin() --  just const version.


lst.insert_after(p,x) - insert x after the iterator denoted by p.
lst.insert_after(p,n,t)
lst.insert_after(p,b,e)
lst.insert_after(p,il)


emplace_after(p,args) --- use args to construct an element and insert after p.
return iterator to new element.


lst.erase_after(p) --  removes after p return denoted by p.
lst.erase-after(b,e) removes from b but not including e.
return itr to the after the last one deleted.


resizing container .
with exception of array container can be resized.


If the current size is greater than the requested
size, elements are deleted from the back of the container; if the current size is less
than the new size, elements are added to the back of the container


list<int> ilist(10, 42); // ten ints: each has value 42
ilist.resize(15); // adds five elements of value 0 to the back of ilist
ilist.resize(25, -1); // adds ten elements of value -1 to the back of ilist
ilist.resize(5); // erases 20 elements from the back of ilist




vector<int> vi = {0,1,2,3,4,5,6,7,8,9};
auto iter = vi.begin(); // call begin, not cbegin because we're changing
for(auto i: vi)
    cout<<i<<endl;
while (iter != vi.end()) {
if (*iter % 2) {
iter = vi.insert(iter, *iter); // duplicate the current
//element
iter += 2; // advance past this element and the one inserted before it
} else
iter = vi.erase(iter); // remove even elements
// don't advance the iterator; iter denotes the element after the one we
//erased
}
for(auto i: vi)
    cout<<i<<endl;



vector --
c.capacity() -- no of elements c can have before re allocation is necessary.

c.shrink_to_fit() -- request to reduce capacity to equal size().its just request to free.
c.reserve() -- allocate space for at least n elements.
  vector<int>v1;
  cout<<v1.capacity();

It is important to understand the difference between capacity and size. The size
of a container is the number of elements it already holds; its capacity is how many
elements it can hold before more space must be allocated.
vector<int> ivec;
// size should be zero; capacity is implementation defined
cout << "ivec: size: " << ivec.size()
<< " capacity: " << ivec.capacity() << endl;
// give ivec 24 elements
for (vector<int>::size_type ix = 0; ix != 24; ++ix)
ivec.push_back(ix);
// size should be 24; capacity will be >= 24 and is implementation defined
cout << "ivec: size: " << ivec.size()
<< " capacity: " << ivec.capacity() << endl;
ivec.reserve(50); // sets capacity to at least 50; might be more
// size should be 24; capacity will be >= 50 and is implementation defined
while (ivec.size() != ivec.capacity())
ivec.push_back(0);
cout << "ivec: size: " << ivec.size()
<< " capacity: " << ivec.capacity() << endl;
ivec.push_back(42); // add one more element
cout << "ivec: size: " << ivec.size()
<< " capacity: " << ivec.capacity() << endl;
ivec.shrink_to_fit(); // ask for the memory to be returned
// size should be unchanged; capacity is implementation defined
cout << "ivec: size: " << ivec.size()
<< " capacity: " << ivec.capacity() << endl;

additional string operation ---

other ways to create strings --

char na[] = {'a','b'};
string a("nikhil");
string b = "nikhil";
string c;
string d = a;
string e(b);
string f(10,'c');
auto beg = b.begin();
auto end = b.end();
string g(beg,end);
string h{a};
const char *cp ="nikhil";
string i(cp,3);
string m(cp+3,3);
string l(cp);
string j(b,2);
string k(b,2,3);
string n(na);
cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<e<<endl<<f<<endl<<g<<endl<<h<<endl<<i<<endl<<j<<endl<<k<<endl<<l<<endl<<m<<endl;
cout<<n<<endl;
Ordinarily when we create a string from a const char*, the array to which the
pointer points must be null terminated; characters are copied up to the null. If we also
pass a count, the array does not have to be null terminated. If we do not pass a
count and there is no null, or if the given count is greater than the size of the array,
the operation is undefined.


substr operation ---

The substr operation (described in Table 9.12) returns a string that is a copy of
part or all of the original string. We can pass substr an optional starting position
and count:
string s("nikhil badyal");
string a = s.substr(6,10);  // where to start if count is greater then it is adjusted
cout<<a<<a<<endl;
// string support all insert assign erase but is also define some other operations.
s.insert(s.size(),5,'!');
cout<<s<<endl;
s.erase(s.size() -5 ,5);
cout<<s<<endl;
//The string library also provides versions of insert and assign that take C-style
//character arrays.
const char *cp = "nikhil, shut the fuck up.";
s.assign(cp,7);
cout<<s<<endl;
s.insert(s.size(),cp+7);
cout<<s<<endl;


string s = "some string", s2 = "some other string";
s.insert(0, s2); // insert a copy of s2 before position 0 in s
// insert s2.size() characters from s2 starting at s2[0] before s[0]
cout<<s<<endl<<s2<<endl;
s.insert(0, s2, 0, s2.size());
cout<<s<<endl<<s2<<endl;
// insert s2.size() characters from s2 starting at s2[0] before s[0]


append and replace --
library also defines two member function named append and replace  that change the content of string.
string s("C++ Primer"), s2 = s; // initialize s and s2 to "C++
Primer"
s.insert(s.size(), " 4th Ed."); // s == "C++ Primer 4th Ed."
s2.append(" 4th Ed."); // equivalent: appends " 4th Ed." to s2; s == s2

s.insert(pos,args) -- insert before pos . pos can be iterator or string. version taking index return reference to s
and taking iterator return iter to first inserted char
s.erase(pos,len) -- erase len from char . if len is omitted then it goes to end.]
s.assign(args) -- replace char in s acc to args. return reference to s.
s.append(args) --- append args to s.  return reference to s.
s.replace(range, char) --remove range of char from s and replace with char.
range is length or pair of itr or index.

 */






    return 0;
}
