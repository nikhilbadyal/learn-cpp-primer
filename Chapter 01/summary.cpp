#include<iostream> // iostream is called header.
using std::cin;
int main()
{
    int x,y;
  //  cin>>x>>y; // (cin>>x)>>y;
    /* iostream provides standard input and output libraries.
    it mainly consist of 4 type IO objects.
    1. istream(cin) - standard input
    2. ostream(cout) - standard output
    3. cerr - used for standard error and warning messages.
    4. clog - used for general information about execution of program
    >> takes two inputs the left side must be an istream object and it returns left hand object
    We must always flush the buffer associated with the stream.
    ++i = i +1;*/
 /*   int sum = 0, value = 0;
    while(std::cin>>value) // It reads until EOF or non int vale encounters
        sum += value;
    std::cout<<"Sum of entered numbers is - "<<sum;*/
    int curValue = 0 , value = 0;
    if(std::cin>>curValue){
        int cnt = 1;
        while(std::cin>>value){
            if(value == curValue)
                ++cnt;
            else{
                std::cout<<curValue<<" occurs "<<cnt<<" times"<<std::endl;
                curValue = value;
                cnt = 1 ;
            }
        }
    }
    return 0;
}


