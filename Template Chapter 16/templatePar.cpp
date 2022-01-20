#include<iostream>
using std::cin; using std::cout;
using std::istream ; using std::ostream;

#include<vector>
using std::vector; using std::endl;

#include<algorithm>
using std::find_if; using std::max_element;

#include<string>
using std::string;

#include<utility>
using std::pair;

#include<tuple>
using std::tuple;

using namespace std;

template<typename T>
T* foo(T* arr)
{
    arr[0] = arr[1];
    return arr;
}
int * accept()
{
    int r,c;
    cout<<"Enter the size of the array .\n";
    cin>>c;
    int *temp = (int *)malloc(sizeof(int)*c);
    for(int i = 0 ; i < c;++i)
    {
        cin>>temp[i];
    }
    return temp;
}
void print(int *arr)
{
    for(int i = 0 ; i< 3 ;++i)
    {
        cout<<arr[i]<<"  ";
    }
}

int * PtoA()
{
    int r,c;
    cout<<"Enter number of rows and columns.\n";
    cin>>r>>c;
    int **arr;
    for(int i = 0 ; i < r ; ++i)
    {
        arr[i] =  (int*)
    }
}
int *AtoP()
{
    int r,c;
    cout<<"Enter number of rows and columns.\n";
    cin>>r>>c;

}
int main()
{
  /*  int var ;
    int *varPtr = &var;
    int **varptrPtr = &varPtr;
    cin>>var;
    cout<<*varPtr<<**varptrPtr;
    int * arr = accept();
    print(arr);*/

    return 0;
}
