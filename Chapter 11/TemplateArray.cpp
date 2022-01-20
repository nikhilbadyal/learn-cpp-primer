#include<iostream>
using std::cin; using std::cout;
using std::istream ; using std::ostream;

#include<vector>
using std::vector; using std::endl;

#include<set>
using std::set;

#include<string>
using std::string;

template<typename T> //,unsigned Size
class Array{
public:

    //Constructor
    Array() = default;
    Array(std::initializer_list<T> il)
    {
        Array(vector<T>(il));
    }
    Array(size_t size)
    {
        Array(vector<T>(Size));
    }


    //Functions
    T showMax()
    {
        T Max = *(Array.begin());
        for(auto i : Array)
        {
            if(i>Max)
                Max = i;
        }
        return Max;

    }
    T sum()
    {
        T sum = 0.0;
        for(auto i : Array)
            sum += *i;
        return sum;
    }
private:
    size_t Size = 5;
    vector<int>Array;

};
int main()
{
    Array<int>a1{1,2,3,4,5};

    return 0;
}
