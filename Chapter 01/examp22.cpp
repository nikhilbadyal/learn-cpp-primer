#include <iostream>
#include <string>
#include"Sales_item.h"
using std::cin;
using std::cout;
using std::endl;
int main()
{

    Sales_item book;
    Sales_item bookSum;
    while(cin>>book)
        bookSum += book;
    cout<<bookSum<<endl;
    return 0;
}
