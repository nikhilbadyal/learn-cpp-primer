#include<iostream>
#include<string>
#include<cctype>
using std::string ; using std::cin ; using std::cout ; using std::cin ; using std::endl;
using std::wistream;
int main()
{
    /*
     istream (input stream) type, which provides input operations
    • ostream (output stream) type, which provides output operations
    • cin, an istream object that reads the standard input
    • cout, an ostream object that writes to the standard output
    • cerr, an ostream object, typically used for program error messages, that
    writes to the standard error
    • The >> operator, which is used to read input from an istream object
    • The << operator, which is used to write output to an ostream object
    • The getline function, which reads a line of input from a given
    istream into a given string

    A. IO class

    So we far we have used only istream and ostream to manipulate but it is not always required as we may need to write
    or read in a file.To do so library defines some other IO types .

    a. iostream for istream and ostream
    b. fstream defines the types used to read and write named files
    c. sstream  defines the files used to read and write in memory strings


    iostream - istream and wistream reads from stream
                ostream and wostream writes to the stream
                iostream and wiostream reads and writes to the stream

    fstream - ifstream wifstream reads from a file
              ofstream , wofstream writes to a file
              fstream , wfstream reads and writes to the file
    sstream - istringstream , wistringstream reads
              ostringstream , wostringstream writes
              stringstream , wstringstream reads and writes

    To support languages that use wide characters, the library defines a set of types
    and objects that manipulate wchar_t data . The names of the wide-
    character versions begin with a w. For example, wcin, wcout, and wcerr are the
    wide-character objects that correspond to cin, cout, and cerr, respectively. The
    wide-character types and objects are defined in the same header as the plain char
    types. For example, the fstream header defines both the ifstream and
    wifstream types.
    string c;
    cin>>c;
    cout<<c<<endl;


No copy or assign to IO class

as we have seen w cant assign or copy IO stream objects.

ofstream out1, out2;
out1 = out2; // error: cannot assign stream objects
ofstream print(ofstream); // error: can't initialize the ofstream parameter
out2 = print(out2); // error: cannot copy stream objects

since they cant be copied, we cant have function that return or has parameter of this type.
function that do IO operation accepts reference.

reading or writting changes state hence they must not be const.

1.
strm::iostate -  it is a machine dependent integral type that represent the condition of a state.
strm::badbit -- used to check corrupted stream.
strm::failbit -- used to detect that IO operation failed.
strm::eofbit -- stream hit end of file .
strm::goodbit -- stream is in good state.

s.eof() - true if eofbit in s is set.
s.fail() - true if badbit or failbit in s is set.
s.bad() -- true if badbit in s is set.
s.good() - if it is in good state.
s.clear() --- reset all and bring it to valid state.
s.clear(flag) ---- reset condition of s to flag  . type of flag is strm::iostate.
s.setstate(flag) --- add specified condition to the s its type is iostate.
s.rdstate(flag) -- return current situation of s in strm::iostate form.

iostate is the collection of bit like our quiz problem.it provide 4 type of constexpr expression.
they are used to check which kind of error had occurred.


badbit -- represent system level error which is unrecoverable.
failbit is set after a recoverable error occur like reading char in int object.it is not possible to correct them
and continue using stream.
eofbit i set when hit eof -- it set both eofbit and fail bit
goodbit if have zero then stream is in good condition.
if any of bad , fail , eof is set then the condition which check stream will fail.

The library also defines a set of functions to interrogate the state of these flags.
The good operation returns true if none of the error bits is set. The bad, fail, and
eof operations return true when the corresponding bit is on. In addition, fail
returns true if bad is set. By implication, the right way to determine the overall state
of a stream is to use either good or fail. Indeed, the code that is executed when
we use a stream as a condition is equivalent to calling !fail(). The eof and bad
operations reveal only whether those specific errors have occurred.

the rdstate returns the current state.
setstate turn on given condition bit to tell that error has occurred
clear is over one takes no parameter and other take parameter of iostate type.
clear of parameter type expect an iostate which it can set for stream.



// turns off failbit and badbit but all other bits unchanged
cin.clear(cin.rdstate() & ~cin.failbit & ~cin.badbit);

managing output buffer.

each output stream manges buffer with it which it use to read to write.

 auto old_state = cin.rdstate();
cin.clear();
// process(cin);
cin.setstate(old_state);

following are the reasons when buffer flush.

1. program complete and buffers are flushed as part of return from main.
2. at some time buffer gets full
3. we can flush it using endl.
4. we use unitbuf to set the stream internal stream to flush each time a output is done. by default
it is set for cerr , means every time we use cerr the buffer i flushed.
An output stream might be tied to another stream. In this case, the buffer of
the tied stream is flushed whenever the tied stream is read or written. By
default, cin and cerr are both tied to cout. Hence, reading cin or writing to
cerr flushes the buffer in cout

flushing the output data -

cout << "hi!" << endl; // writes hi and a newline, then flushes the buffer
cout << "hi!" << std::flush; // writes hi, then flushes the buffer; adds no data
cout << "hi!" << std::ends; // writes hi and a null, then flushes the buffer

cout<<std::unitbuf;

f we want to flush after every output, we can use the unitbuf manipulator. This
manipulator tells the stream to do a flush after every subsequent write. The
nounitbuf manipulator restores the stream to use normal, system-managed buffer
flushing

if a program crashes we must flush the buffer when debugging it.

When an input stream is tied to an output stream, any attempt to read the input
stream will first flush the buffer associated with the output stream. The library ties
cout to cin, so the statement
cin >> ival;
causes the buffer associated with cout to be flushed.

interactive users should tie their input with output.
1 one version take no argument and return a return pointer to output stream.
if not tied then null.
2. second version takes pointer to ostream and ties it self to that stream.
ie
x.tie(&o) ; // x ties with o.


cin.tie(&cout); // illustration only: the library ties cin and cout for us
// old_tie points to the stream (if any) currently tied to cin
ostream *old_tie = cin.tie(nullptr); // cin is no longer tied
// ties cin and cerr; not a good idea because cin should be tied to cout
cin.tie(&cerr); // reading cin flushes cerr, not cout
cin.tie(old_tie); // reestablish normal tie between cin and cout

To tie a given stream to a new output stream, we pass tie a pointer to the new
stream. To untie the stream completely, we pass a null pointer. Each stream can be
tied to at most one stream at a time. However, multiple streams can tie themselves to
the same ostream.



file handling and IO---

they can use previous all operation of iostream as it inherited from them but they also define
some o their own operations.

1. fstream fstrm -- creates and unbounded stream.
22. fstream fstrm(s) - created a fstream and open file names s . s can be string or pointer to c style
string.default mode depend on type of fstream.
3. fstream fstrm(s, mode) -- like the previous one but open it in mode .
4. fstrm.open(s) -- open file s and bind it to fstrm s ;
4. fstrm.open(s,mode ) -- open file s and bind it to fstrm s in given mode return void;
5. fstrm.close() -- closes the file to which fstrm is bounded.
6 . fstrm..is_open() -- return bool is the file bounded is opened.


std::ifstream in(infile); // defines in stream and associate it with file
file name can be c style array or  string
ofstream out; // output stream that is not linked with any file.

since we can use derived class object when original object are required hence we can use fstream object when
iostream are required.


when we define empty stream we can later associate it with some file.

like ofstream out;
out.open(infile + "copy");
if call fails fail bit is set so it is better to check.
    if(out);
calling a opened file , will fail and hence will set failbit an subsequent operations will fail.
to associate a different file we must close the opened file fist.
in.close();


file mode -- every stream ahs mode that decides how its files will be used.

in ---- open for input.
out -- open for output.
app -- seek to end before every write
ate - seek to end immediately after open.
trunc -- trunc the file.
binary - do IO operations in binary mode.


out - for ofstream or fstream
in -- ifstream or fstream
trunc - when out is specified..
 app mode may be specified so long as trunc is not. If app is specified, the file
is always opened in output mode, even if out was not explicitly specified.
By default, a file opened in out mode is truncated even if we do not specify
trunc. To preserve the contents of a file opened with out, either we must also
specify app, in which case we can write only at the end of the file, or we must
also specify in, in which case the file is open for both input and output (§
17.5.3 (p. 763) will cover using the same file for input and output).

The ate and binary modes may be specified on any file stream object type
and in combination with any other file modes



opening in out discard existing data -

ofstream out("file1"); // out and trunc are implicit
ofstream out2("file1", ofstream::out); // trunc is implicit
ofstream out3("file1", ofstream::out | ofstream::trunc);
// to preserve the file's contents, we must explicitly specify app mode
ofstream app("file2", ofstream::app); // out is implicit
ofstream app2("file2", ofstream::out | ofstream::app);


string stream

sstream define 2 type of header to support in memory IO.
istringstream used to read;
ostringstream used to read;
stringstream used to read;

like fstream they are inherited from iostream and hence can be used in place of them.


sstream strm -- unbound sstream type
sstream strm(s)  -- sstream type that hold copy of string s.
strm.str() - return string that strm hold.
strm.str(s) - copy s into stream . return void
    return 0;
}
