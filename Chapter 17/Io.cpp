#include<iostream>
#include<string>
#include<vector>
#include<cctype>
#include<stdexcept>
using std::string ; using std::cin ; using std::cout ; using std::cin ; using std::endl; using std::vector; using std::runtime_error;
int main()
{
    /*
Library defines a set of manipulators that modifies the format stream of a stream.it is a type of object
which change the state of the stream and can be used for input or output operator.like input and output operator
they return object hence we can cascade them.
we have already used one manipulator called endl which flushes the buffer and print new line.

Manipulators are used for two broad categories of output control: controlling the
presentation of numeric values and controlling the amount and placement of padding.

one example of many manipulator is bool alpha -
a true is represnted by 1 while false with 0 we can over ride it with bool alpha.
cout << "default bool values: " << true << " " << false
<< "\nalpha bool values: " << boolalpha
<< true << " " << false << endl;

cout << "default bool values: " << true << " " << false
<< "\nalpha bool values: " << std::boolalpha
<< true << " " << false << endl;
// Now after this true will print true . to undo this we need to do.
//cout<<true;

bool bool_val = true;
cout << std::boolalpha // sets the internal state of cout
<< bool_val
<< std::noboolalpha; // resets the internal state to default formatting
cout<<true;

By default, integral values are written and read in decimal notation. We can change
the notational base to octal or hexadecimal or back to decimal by using the
manipulators hex, oct, and dec:

showbase -

By default, when we print numbers, there is no visual cue as to what notational base
was used. Is 20, for example, really 20, or an octal representation of 16? When we
print numbers in decimal mode, the number is printed as we expect. If we need to
print octal or hexadecimal values, it is likely that we should also use the showbase
manipulator.


uppercase-
By default, hexadecimal values are printed in lowercase with a lowercase x. We can
display the X and the hex digits a–f as uppercase by applying the uppercase
manipulator

step precision to manipulate precision -
We can change the precision by calling the precision member of an IO object or
by using the setprecision manipulator.
One version takes an int value and sets the precision to that new value.
It returns the previous precision value. The other version takes no arguments and
returns the current precision value. The setprecision manipulator takes an
argument, which it uses to set the precision. in iomapin header.

no skip is used to no skip the space.

unformatted input output -

is.get(ch) - put from istream into ch . return is .
os.put(ch) - put from ostream into ch . return os.
is.get()- return next byte from is as int.
is.putback(ch )- put character from is in ch . return is
is.unget() - move is back one byte. return is .
is.peek() - return the next byte as int but doesnt remove it .

to buffer cin -
cin.ignore(std::numeric_limits<std::streamsize>::max())

// Ignore to the end of line
cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n')



random access to string--

one most streams bound to cin cout cerr clog are not bound to random access

to support random access, IO manages two markers seek and tell . they are used to locate the current position and
seek to a particular position.
one is used by input other by output distinguished by p and g p = put and g = get.

1. tellg() - return the current position in  current input stream(tellg()) or from output stream (tellp());
.
2. tellp() -- return current output stream position.

3. seekp(pos) and seekg(pos ) --- reposition in input or output stream.it is usually position returned by tellp or tellg

4. seekp(off ,from )  -- reposition the marker in input output stream integral number off character
ahead or behind from.from can be beg ,end.



pos  and off has machine dependent type.they are defined in both istream and ostream.they are
pos_type and off_type.pos_type represent a file position and off_type represent represent off.
it can be positive or negative.


*/
}
