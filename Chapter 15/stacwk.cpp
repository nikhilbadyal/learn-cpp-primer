#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> create2dVector(const size_t , const size_t , const int );
vector<vector<int>> create2dVector(const size_t size1, const size_t size2, const int value)
{
    vector<vector<int> > v( size1 , vector<int>(size2));
    for(auto i = v.begin() ; i != v.end() ;++i)
    {
        vector<int>p;
        for(int j=0;j<int(size2);++j)
        {
            p.push_back(value);
        }
        *i = p;
    }
    return v;
}
int main() {
    auto v = create2dVector(2, 5, 10);
    for(auto i : v)
    {
        for(auto j : i)
            cout<< j<<" ";
    }

    return 0;
}
