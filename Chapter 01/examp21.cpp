#include <iostream>
#include <string>
#include"Sales_item.h"
using std::cin;
using std::cout;
using std::endl;
int main()
{
    Sales_item book1 , book2;
    cout<<"Enter two books data.\n"<<endl;
    cin>>book1>>book2;
    if(book1.isbn() == book2.isbn() )
        cout<<book1+book2<<endl;
    else{
        std::cerr<<"Data must refer to same ISBN."<<endl;
        return -1;
    }
    return 0;

}
