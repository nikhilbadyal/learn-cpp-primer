#include<iostream>
#include<fstream>
#include<ios>
//std::ios_base seekdir::beg;

using namespace std;
struct Try{
    int a = 10;
    friend istream &operator >>(istream & , Try &);
    friend ostream &operator <<(ostream & , Try &);
};
istream &operator >>(istream &in, Try &t)
{
    in>>t.a;
    return in;
}
ostream &operator <<(ostream &out, Try &t)
{
    //out<<"hex : "<<hex<<t.a;
    out<<t.a;
    return out;
}
int main()
{


 /*
 It is a common programming error to assign the return, from get or peek
to a char rather than an int.
   int c ;
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
    }
    cin>>c;*/
 /*   Try t;
    ifstream read;
    ofstream write;
    string s = "nikhil.txt";
   // cin>>s;
    if(read)
        cout<<"Opened\n";
   // read.close();
  //  read.close();

    write.open(s);

    while(cin>>t){
    write<<t<<endl;}

    write.close();

    read.open(s);
    if(read.is_open())
        cout<<"opened\n";

    while(read>>t)
        cout<<t<<endl; */
    ifstream read;
    ofstream write;

    string s = "nikhil.txt";
    string s1 = "aikhil.txt";
    read.open(s);
    write.open(s1);
    cout<<read.tellg()<<endl;


    read.seekg(read.tellg(),ios_base::beg);
    cout<<read.tellg()<<endl;
    read.seekg(3,ios_base::cur);
    cout<<read.tellg()<<endl;
    read.seekg(3,ios_base::end);
    cout<<read.tellg()<<endl;

  //  cout<<write.tellp();
  //   char ch ;
  /*  read.get(ch); // read and move to next
     cout<<read.tellg()<<endl; //2
     read.putback(ch); // one step back
     cout<<read.tellg()<<endl; //1
     read.get(); // read and move next
    cout<<read.tellg()<<endl; //3
    read.unget(); // back one step
    cout<<read.tellg()<<endl; //2
    read.peek(); // read and dont move
     cout<<read.tellg()<<endl;
     read.putback(ch);
     cout<<read.tellg()<<endl; //2*/

    // read.seekg(90);
     //cout<<read.tellg()<<endl;

 //   write.open(s,ofstream::app);
   // char ch = 'x';
  //  cin.get(ch);
  //  cout<<ch;
  //   read.get(ch);
  //   read.putback(ch);
//    write.put(ch);
     //cout<<ch;
    // cout<<read.get();
  //  while(read.get(ch))
  //  {
  //      cout<<ch;
       // read.unget();
      // read.putback(ch);
   //    cout<<read.peek()<<endl;
    //}
   //  char name[30];
    // char name1[30];
//     read.get(name,89,'@');
    // read.getline(name1,89,'@');
   //  cout<<name;
   //  cout<<name1;
 //   for(int i = 0 ; i < 7 ;++i)
     //   cout<<name1[i]<<endl;
  // read.read(name,9);
 //  read.ignore(8);
  //  for(int i = 0 ; i < 9 ;++i)
     //   cout<<name[i]<<"myspace";
 //   cout<<read.gcount();

  /*  ofstream append;
    append.open(s+".txt",ofstream::app);
    append<<t;
    append.close();
    ofstream appendAgain(s+".txt", ofstream::out | ofstream::app);
    while(read>>t)
        cout<<t<<endl;
  //  ofstream writeAgain(s+".txt");
   // char ch;

  cin >> noskipws; // set cin so that it reads whitespace
while (cin >> ch){
cout << ch;
cin >> skipws;
}*/


   string s("nikhil");
   fstream inOut(s, fstream::app);
   auto


}
