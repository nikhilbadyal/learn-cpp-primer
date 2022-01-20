#include<iostream>
#include<vector>
#include<string.h>
//using namespace std;
using std::cin ; using std::cout; using std::endl; using std::vector ; using std::string;
int main()
{
    /*  Vectors - also known as containers are use to contain other objects.

    every containing object is associated with an index which helps in accessing object
    we have hold any object in the vector since references are not objects we can't have vector
    of references.

    vector<int> v1; // v1 will hold int objects
    vector<vector<string>>name; // vector will hold vector which in turn contain strings

    1. Initialization of vector
    when we use copy initialize form we must use only 1 initializer
    and when we use in class initializer we must use copy initialization or curly braces
    we can't use list initialization with parenthesis
    vector<int>v1;
    vector<int>v2(v1);
    vector<int>v3 = v1;
    vector<int>v4(10,15);
    vector<int>v5(10);
    vector<int>v6{1,2,3,4};
    vector<int>v7 = {1,2,3,4,5,6};
    vector<string> names = {"Nikhil ", "Aikhil"};
    cout<<names[1];

    we can omit value and can provide only size but this form of initialization has two restriction
    1. since they are value initialized hence if type doesn't support default initialization then we can't use it
    2. if supplying we must use direct initialization
    vector<int>v1 =10 //error
    vector<int> v1(10); // v1 has ten elements with value 0
    vector<int> v2{10}; // v2 has one element with value 10
    vector<int> v3(10, 1); // v3 has ten elements with value 1
    vector<int> v4{10, 1};
    vector<string> svec(10, "null");
    vector<int> v2{10}; v2 contains  element//
    vector<string> v2{10}; v2 contain 10 element

    2. Adding elements to the vector

    vector<int>v2;
    for(int i =0;i!=100;i++)
        v2.push_back(i);
    cout<<v2[99];
    vector<int>v1{1,2,3,4,5,6,7,9,10};
    for(auto &i : v1)
        i *= i;
    for(auto i : v1)
        cout<<i<<endl;


    //to use size type we need indicate for what type we are using it.
    vector<int>::size_type x;
//    vector::size_type;
    vector<unsigned >v1(11,0);
    unsigned grade;
    while(cin>>grade)
        if(grade<=100)
            ++v1[grade/1];
    for(auto i : v1)
    cout<<i<<endl;
    vector<int>num;
    int temp;
    while(cin>>temp)
        num.push_back(temp);
    if(num.size()>0)
    {
        if(num.size()>1)
        {
            int i=0;
            while( i<(num.size()-1)){
            cout<<num[i]+num[i+1]<<" ";
            i++;}
            cout<<endl;
            i =0;
            int k = num.size()-1; //11
            while(k>=i)
            {
                if(k>i)
                {
                    cout<<num[i] + num[k] <<" ";
                    i++;
                    k--;
                }
                else{
                    cout<<num[i];
                    break;
                }
            }
            cout<<endl;
        }
        else{
            cout<<num[0];
        }
    }
    else{
        cout<<"No element.\n";
    }*/

    return 0;
}
