#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cctype>
#include<stdexcept>
using std::string ; using std::cin ; using std::cout ; using std::cin ; using std::endl; using std::vector; using std::runtime_error;
using std::fstream; using std::ofstream; using std::ifstream;
int main()
{
 /* //  ifstream are opened in in mode(not truncated) , ofstream are opened in out mode.(truncated)
    string f1;
    cin>>f1;;//= "nikhil.txt";
    fstream stream1; // unbounded stream used for writting and reading
    stream1.open(f1+ ".txt");  // opens the file and bound the stream with that file

    string f2("data.txt");
    fstream stream2(f2);// f2 stream bounded with f2 file.

   ifstream stream3; // it created file if doesnt exist.
   stream3.open(f1+".txt");


  //  fstream stream3(f2,);// f2 stream bounded with f2 file but opened in read mode

   stream2.close();

    if(stream1)
        cout<<"Hello"<<endl;
    if(stream2.is_open())
        cout<<"Yup"<<endl;


    ofstream out; //unbounded output stream // used for writting // by default open is truncated.
  //  out.open(f1+".txt");  // truncated the data.
  //  out.open(f1+".txt",ofstream::app); // no truncation.
    out.open(f1+".txt",ofstream::in); // only one stream with one file other set to fail bit.
    //The only way to preserve the existing data in a file opened by an ofstream
//is to specify app or in mode explicitly

    char ch;
    int count=0;
   // cin>>std::noskipws;
    while(cin>>ch){
            count++;
        cout<<ch;
        cout<<count;}
    char ch;
    while(cin.get(ch))
        cout.put(ch);

    cin.get(ch); // read from is and put in char.
    cin.get(); // read next from is as int
    cin.putback(ch) - put back ch in stream
    cin.unget()-- move one byte back
    cin.peek() -- get the next byte as int but doesnt remove it
    char c = cin.get(); // read from is  and return int
   // cout<<c;
    char ch = 's';
    cin.putback(ch);
    cin.get(c);
    cin.unget();
    cout<<c;
    char ch;
    cin.get(ch);
    cout<<ch<<endl;;
 //   cin.unget();
    cin.get(ch);
    cout<<ch;
    cin.unget();
    cin.get(ch);
    cout<<ch;
    ch= cin.get();
    cout<<ch;


multi byte handling


sometime we need to handle chunk of bytes instead of single byte then we use these -

1. cin.get(sink,size,delim)- read upto size of size bytes and stores in the character array pointed by
sink. or it ends if it reaches end of file. or delim is reached.

2. cin.getline() - same as above but reads and discard delim.

3. cin.read(sink,,byte) -- read upot n bytes from sink

4. cingcount() -- return no of bytes read from string

5. cout.wrie(source,size);
*/


char arr[10];
cin.getline(arr,100,'@');
cout<<arr;
char c ;
cin.get(c);
cout<<c;





  //  cout<<cin;

    return 0;
}
