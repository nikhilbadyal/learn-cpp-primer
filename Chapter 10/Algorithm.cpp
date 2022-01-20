#include<iostream>
#include<string>
#include<vector>
#include<cctype>
#include<stdexcept>
#include<array>
#include<deque>
#include<forward_list>
#include<list>
#include<algorithm>
#include<numeric>
using std::string ; using std::cin ; using std::cout ; using std::cin ; using std::endl;
using std::vector; using std::runtime_error; using std::list;
using std::array; using std::end; using std::begin;
string make_plural(size_t ctr, const string &word,
const string &ending)
{
return (ctr > 1) ? word + ending : word;
}
void elimDups(vector<string>&s)
{
    std::sort(s.begin(),s.end());
    auto end_uniq = std::unique(s.begin(),s.end());
    s.erase(end_uniq , s.end());
}
bool isShorter(const string &s1, const string &s2)
{
return s1.size() < s2.size();
}
void biggies(vector<string> &words,
vector<string>::size_type sz)
{
    for(auto i : words)
       cout<<i<<" ";
    cout<<endl;

elimDups(words); // put words in alphabetical order and remove
for(auto i : words)
       cout<<i<<" ";
    cout<<endl;
//duplicates
// sort words by size, but maintain alphabetical order for words of the same size
stable_sort(words.begin(), words.end(),
[](const string &a, const string &b)
{ return a.size() < b.size();});
for(auto i : words)
       cout<<i<<" ";
    cout<<endl;
// get an iterator to the first element whose size() is >= sz
auto wc = find_if(words.begin(), words.end(),
[sz](const string &a)
{ return a.size() >= sz; });
    cout<<*wc<<endl;
// compute the number of elements with size >= sz
auto count = words.end() - wc;
cout << count << " " << make_plural(count, "word", "s")
<< " of length " << sz << " or longer" << endl;
// print words of the given size or longer, each one followed by a space
for_each(wc, words.end(),
[](const string &s){cout << s << " ";});
cout << endl;
}
auto f= [] { return 42;};
void fcn2()
{
size_t v1 = 42;
//cout<<v1<<endl;
auto f2 = [&v1] { v1 += 10 ; return v1; };
//cout<<v1<<endl;
auto j = f2(); // j is 0; f2 refers to v1; it doesn't store it
cout<<v1<<endl;
}
void fcn3()
{
size_t v1 = 42;
//cout<<v1<<endl;
auto f2 = [v1] ()mutable { v1 += 10 ; return v1; };
//cout<<v1<<endl;
auto j = f2(); // j is 0; f2 refers to v1; it doesn't store it
cout<<v1<<endl;
}
int main()
{

    /*
    Algorithms ---

    vector<int>v{1,2,3,4,5,6,7,7,8,10};
    int val = 23;
    auto result = find(v.begin(),v.end(),val);
    cout<<"The value "
        <<(result == v.end()
           ?"is not present" : "is present.\n")<<endl;

    1. find --- it takes 3 arguments, first 2 denotes the range , 3rd denotes the value
    we want to search.
    vector<string>s;
    string a = "nikhil";
    s.push_back("aikhil");
    s.push_back(a);
    s.push_back(a);

    cout<< *(std::find(s.begin(),s.end(),a));
    it return iterator to first element and if not found then itr to seond parameter.
    2nd parameter is excluded from searching.

    read only algorithm -

    2. accumulate --
    it takes 3 parameters , first 2 defines the range of input to the sum and 3rd defines the initial value to the sum.

    vector<int>v{1,2,3,4,5,6,7,8,9};
    auto sum = std::accumulate(v.begin(), v.end(), 20);
    cout<<sum;
    vector<string>s;
    string a = "nikhil";
    s.push_back("aikhil");
    s.push_back(a);
    s.push_back(a);
    string sum = accumulate(s.cbegin(), ds.cend(), string("#"));
    // we cant pass string as its type is const char* which cant be converted into string

    cout<<sum;

    that feed on 2 sequences --

    3. equal --
     The algorithm takes three iterators: The first
    two (as usual) denote the range of elements in the first sequence; the third denotes
    the first element in the second sequence

    algorithms that write --

    4 fill ----
    As one example, the fill algorithm takes a pair of iterators that denote a range
     and a third argument that is a value.

    algorithm dont check write

    5. fill_n --  the fill_n function takes a single
    iterator, a count, and a value. It assigns the given value to the specified number of
    elements starting at the element denoted to by the iterator.

    introducing back_inserter ---

    6. back_inserter---

    back_inserter takes a reference to a container and returns an insert iterator
bound to that container


    7. insert_iterator --
    it is an iterator that add elements to the container. Ordinarily, when we assign to a container element through an iterator, we
   assign to the element that iterator denotes. When we assign through an insert iterator,
    a new element equal to the right-hand value is added to the container

    vector<int> vec; // empty vector
// ok: back_inserter creates an insert iterator that adds elements to vec
fill_n(back_inserter(vec), 10, 98); // appends ten elements to vec
    for(auto i : vec)
        cout<<i<<endl;


    copy algorithms ---


    8.
    It takes 3 arguments. First two defines copy range 3rd denoted the beginning of sequence.


    int a1[] = {1000,1,2,3,4,5,6,7,8,9};
   int a2[sizeof(a1)/sizeof(*a1)]; // a2 has the same size as a1
// ret points just past the last element copied into a
   // int a2 = 3;
   auto ret = std::copy(std::begin(a1), std::end(a1), a2); // copy a1 into a2
  // cout<<*ret<<endl;

 //  9. replace -- it takes 4 inputs 2 denotes the range and 3rd denotes the value to be replaced 4th by which
 //  we need to replace.
     for(auto i : a2)
        cout<<i<<" ";
    list<int>a2{1,2,3,4,5,6,7,8,9};
    for(auto i : a2)
        cout<<i<<" ";

     std::replace(a2.begin(),a2.end(),9,42);
     for(auto i : a2)
        cout<<i<<" ";

    10. replace_copy() - it takes 5 arguments 4 as before 3rd it takes the destination to where we need to copy.

    list<int>a2{1,2,3,4,5,6,7,8,9};
    vector<int>v;
    replace_copy(a2.begin(),a2.end(),back_inserter(v),9,42);
    for(auto i : v)
        cout<<i<<" ";


    algorithms that reorder

    11. a call to sort arranges the elements as per < operator.


    vector<string>s{"the","an","the","the","an"};
    elemdup(s);
    for(auto i : s)
        cout<<i<<" ";


    customize operators---


    library let us pass function our own operators.

    another version of sort takes 3 parameter and give result as per 3rd argument.


vector<string>words{"the","aman","fox","run","over","the","field","an","the","the","an"};
    elemdup(words);
 //   for(auto i : words)
   //     cout<<i<<" ";

// sort on word length, shortest to longest
sort(words.begin(), words.end(), isShorter);
for(auto i : words)
    cout<<i<<" ";
cout<<endl;
stable_sort(words.begin(), words.end(), isShorter);
for (const auto &s : words) // no need to copy the strings
cout << s << " "; // print each element separated by a space
cout << endl;


stable_sort- it is used to maintain alphabetical order in same size words.

The capture list is used for local nonstatic variables only; lambdas can use
local statics and variables declared outside the function directly.
  vector<string>words{"the","aman","fox","run","over","the","field","an","the","the","an"};
  biggies(words,3);

lambda expressions ----
it represent callable unit of code. it can be thought of unnamed inline function.
Like any function, a lambda has a return type, a parameter
list, and a function body. they can be defined inside a body.
it has form --

[captureList] (parameter list) -> returnType {functionBody}
where capture list is list of parameter defines in local enclosing function.

we can omit parameter list and return type but always include capture list and function bofy.
    cout<<f();
    Lambdas with function bodies that contain anything other than a single
return statement that do not specify a return type return void.

passing arguments to lambda --

lambda may nit have  default parameters.

although a lambda may appear inside a function, it can use variables local to that
function only if it specifies which variables it intends to use.

lambda capture and return --
we when create lambda compiler generate new class type corresponding to that lambda.

capture by value --
we can also capture by value or reference.
Unlike parameters, the value of a captured variable is
copied when the lambda is created, not when it is called.


void fcn1()
{
size_t v1 = 42; // local variable
// copies v1 into the callable object named f
auto f = [v1] { return v1; };
v1 = 0;
auto j = f(); // j is 42; f stored a copy of v1 when we created it
}
We can also return a lambda from a function. The function might directly return a
callable object or the function might return an object of a class that has a callable
object as a data member. If the function returns a lambda, then for the same
reasons that a function must not return a reference to a local variable that lambda
must not contain reference captures


implicit capture ---
[=] -- explicit value capture
[&] -- explicit reference capture

When we mix implicit and explicit captures, the first item in the capture list must be
an & or =.

When we mix implicit and explicit captures, the explicitly captured variables must
use the alternate form. That is, if the implicit capture is by reference (using &), then
the explicitly named variables must be captured by value; hence their names may not
be preceded by an &. Alternatively, if the implicit capture is by value (using =), then
the explicitly named variables must be preceded by an & to indicate that they are to
be captured by reference.


mutable lambdas ---

By default, a lambda may not change the value of a variable that it copies by value. If
we want to be able to change the value of a captured variable, we must follow the
parameter list with the keyword mutable

  fcn3();


specifying the lambda return --

we might use the library transform algorithm and a lambda
to replace each negative value in a sequence with its absolute value:
transform(vi.begin(), vi.end(), vi.begin(),
[](int i) { return i < 0 ? -i : i; });



The lambda body is a single return statement

binding arguments---

Lambda expressions are most useful for simple operations that we do not need to use
in more than one or two places. If we need to do the same operation in many places,
we should usually define a function rather than writing the same lambda expression
multiple times.

    return 0;
}
