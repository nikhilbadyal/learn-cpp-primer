#include<iostream>
#include<vector>
#include<string>
using namespace std;

template<typename T,unsigned Size>
class Array{
public:
    Array() = default;
    Array(std::initializer_list<T> il) : ary(il){}
    Array(size_t size) : ary(size){}
    T showMax()
    {
        T Max = *(ary.begin());
        for(auto i : ary)
        {
            if(i>Max)
                Max = i;
        }
        return Max;

    }
    T sum()
    {
        T sum = 0.0;
        for(auto i : ary)
            sum += i;
        return sum;
    }
private:
    vector<T>ary;

};
int main()
{
    Array<double,4>array{1.2,2.4,3.9,4.7,5.9}; // It produce errror.
    cout<<array.showMax()<<endl;
    cout<<array.sum();
    return 0;
}
