#include<iostream>
using namespace std;
int main()
{
    bool a = 41 ; // true . It converts 41 into 1; int to bool
    int i = a ;  //i = 1
    i = 3.14;// float to int ;
    double pi = 3 ; // int to float stored as 3.0
    unsigned char c = -1 ; // c has 255 ( 8 bit system)
    signed char c2 = 256; // undefiened system ( 8 bit system) as maximum can be 255 hence overflow occurs.
    unsigned int x = 10;
    int ii = -42;
  //  cout<<ii+ii<<endl;
  //  cout<<x+ii<<endl; // Here ii first get convert to unsigned and then addition is done. int to unsigned conversion
  //  cout<<sizeof(unsigned int)<<endl;
    unsigned int s = -5; // if we assign out of range value result is reminder of value mod max value.
   // cout<<s;  // -5 is converted into its 2 compliment form.
   for(unsigned int i = 10 ; i>=0 ;--i){
    cout<<i<<endl;
   }  // It wont terminate ever because as it u reaches -1 due to unsigned int it will wrap around to some other value. ex in 32 bit it will
   // give 4294967295 ( as -1 mod 4294967296 = 4294967295).




    return 0;
}
