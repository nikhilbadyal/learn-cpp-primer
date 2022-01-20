#include<iostream>
#include<fstream>

using namespace std;
struct Try{
    int a = 10;
    friend istream &operator >>(istream & , Try &);
};
istream &operator >>(istream &in, Try &t)
{
    in>>t.a;
    return in;
}
int main()
{
 /*   int c ;
  //  auto old_state = cin.rdstate();
    while(cin>>c)
    {
        cout<<c<<endl;
    }
    if(cin.failbit)
        cout<<"FailBit.\n";
    if(cin.badbit)
        cout<<"BadBit.\n";
    if(cin.eofbit)
        cout<<"eofBit.\n";
    if(cin.goodbit)
        cout<<"GoodBit.\n";
    cin.clear();
    cin.clear(iostream::goodbit);
    if(!cin){
            cout<<"fault";
        cin.clear();
        cin>>c;
       // cin.setstate(old_state);
    }*/
  //  cin>>c;
    Try t;
    ifstream read;
    ofstream write;
    string s;
    cin>>s;
    read.open(s+".txt");
    if(read)w
        cout<<"opened\n";
    read>>t;
    string s = "nikhil.txt";
    ofstream write;
    write.open(s);
    //ifstream read;
    //read.open(s);
    //if(read.is_open())
     //   cout<<"yup";

    char ch='x';
    write.put(ch);
   // read.get(ch);
    //cout<<s;
  //  cout<<ch;

    return 0;

}
