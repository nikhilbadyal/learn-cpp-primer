#include<iostream>
#include<vector>
using namespace std;

template <typename T>
int compare(const T &obj1 , const T &obj2 ){
    if(obj1 > obj2 ) return 1;
    if(obj2 < obj1) return -1;
    return 0;
}

int main(){
    cout<< compare(2,3);
    vector<int> v1{1,2,3}, v2{2,3,4};
    cout<<compare(v1,v2);
    return 0;
}
