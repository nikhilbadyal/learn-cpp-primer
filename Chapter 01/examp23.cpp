#include<iostream>
#include"Sales_item.h"
using std::cin;
using std::cout;
using std::endl;
int main()
{
    Sales_item curItem , Item;
    if(cin>>curItem){
        int cnt = 1;
        while(cin>>Item){
            if(curItem.isbn()== Item.isbn())
               ++cnt;
            else{
                std::cerr<<"ISBN Changed.\n";
                cout<<curItem.isbn()<<" "<<cnt<<endl;
                curItem = Item;
                cnt = 1;
            }
        }
      std::cout << curItem.isbn() << " " << cnt << std::endl;
    }
    return 0;
}
