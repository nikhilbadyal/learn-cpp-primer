#include<iostream>
#include<string>
#include<vector>
#include<cctype>
#include<stdexcept>
using std::istream; using std::ostream;
using std::string ; using std::cin ; using std::cout ; using std::cin ; using std::endl; using std::vector; using std::runtime_error; using std::end; using std::begin;
class Book{
public:
    Book(): id(0), no(0), name(" ") {}
    static int count;
friend istream &operator>>(istream &in,Book &b);
friend ostream &operator<<(ostream &out,Book &b);
friend class StudentList;
friend class FacultyList;
bool isAvailable()const {if(bookCount>0)return true; else false;}
unsigned int returnSerial(){return no;}
unsigned int returnid(){return id;}

private:
    string name;
    unsigned int id;
    unsigned int no;
    mutable unsigned int bookCount=10;

};
int Book::count = 0;
class Booklist{
    friend class StudentList;
    friend class FacultyList;
    Book b[10];
    void giveDetails(Book &book)
    {
        for(int i = 0 ;i<Book::count;++i){
        if(book.returnSerial() == b[i].returnSerial())
        {
            book = b[i];
        }}
    }

public:
    void addBook();
    void showData();
    void findDetails(Book &book){
      giveDetails(book);
    }
};
istream &operator>>(istream &in,Book &b)
{
    in>>b.name>>b.id>>b.no;
  //  cout<<"Enter count of book -"<<endl;
  //  in>>b.bookCount;
    return in;
}
ostream &operator<<(ostream &out,Book &b)
{
    out<<b.name<<endl<<b.id<<endl<<b.no;
    return out;
}
void Booklist::addBook()
{
    Book bo;
    char ch;
    while(ch != 'n'){
        try{
            cout<<"Enter book "<<Book::count+1<<" details(name ,id , no) - "<<endl;
            cin>>b[Book::count];
            Book::count++;
            cout<<"Wanna enter more. Enter y or n -"<<endl;
            cin>>ch;
            if(!cin){
                throw runtime_error("Input failed.\n");}
        }
        catch(runtime_error error){
            cout<<error.what()
                <<"Try again? Enter y or n.\n";
                char c;
                cin>>c;
                if(!cin || c=='n'){
                    break;
                }
        }
    }
}
void Booklist::showData()
{
    for(int i =0 ;i<Book::count ;++i){
            cout<<"Book "<<i+1<<" details are "<<endl;
        cout<<b[i]<<endl;}
}
