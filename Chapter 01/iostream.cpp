#include<iostream> // iostream is called header.
using std::cin;
int main()
{
    int x,y;
   (cin>>x)>>y;
  //  cin>>x>>y; //
    /* iostream provides standard input and output libraries.
    it mainly consist of 4 type IO objects.
    1. istream(cin) - standard input
    2. ostream(cout) - standard output
    3. cerr - used for standard error and warning messages.
    4. clog - used for general information about execution of program
    >> takes two inputs the left side must be an istream object and it returns left hand object*/
    return 0;
}


