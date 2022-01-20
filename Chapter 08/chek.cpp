#include<iostream>
using std::cin; using std::cout;
using std::istream ; using std::ostream;


#include<fstream>
using std::ifstream ; using std::ofstream;

#include<fstream>
using std::fstream; using std::wfstream;

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

#include<ios>
using std::ios;




int main()
{
    ifstream read;
    read.open("check.txt",ios::binary);
    int n;
    auto old = read.tellg();
    auto pos = old;
    while(read>>n)
    {
        cout<<"gere";
        if(n == 3)
        {
            cout<<"gere";
            pos = old;
            break;
        }
        old = read.tellg();
    }
    cout<<pos<<endl;
    ofstream write;
    write.open("check.txt");
        if(write.is_open()){ cout<<"nikhil";
    write.seekp(1);
    write<<90;}


}
