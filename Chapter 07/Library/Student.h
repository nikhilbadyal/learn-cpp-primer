#include<iostream>
#include<string>
#include<vector>
#include<cctype>
#include<stdexcept>
//#include"Member.h"
using std::istream; using std::ostream;
using std::string ; using std::cin ; using std::cout ; using std::cin ; using std::endl; using std::vector; using std::runtime_error; using std::end; using std::begin;
class Student : public Member{
friend istream &operator>>(istream &in,Student &);
friend ostream &operator<<(ostream &out,Student &);
public:
    static int count;
    Status stat[2];
    void show();
    bool isAlreadyIssued(Book );
    bool canIssue() const {if(bookCount<2) return true; else return false;}

};
bool Student::isAlreadyIssued(Book b)
{
    for(int i = 0 ;i<Status::count;++i)
    {
        if(stat[i].returnid() == b.returnid() && stat[i].returnserial() == b.returnSerial())
            return true;
    }
    return false;
}
//void Member::show()
void Student::show()
{
    for(int i  = 0 ;i< Status::count;++i)
        stat[i].show();
}
int Student::count=0;
class StudentList{
public:

    Student s[10];
public:
    void addStudent();
    void showData();
    void issueBook(const Booklist &);
    void returnBook( Booklist &);
};
istream &operator>>(istream &in,Student &s)
{
    in>>s.name>>s.id;
    return in;
}
ostream &operator<<(ostream &out,Student &s)
{
    out<<s.name<<endl<<s.id<<endl;
    return out;
}
void StudentList::addStudent()
{
    char ch;
    while(ch != 'n'){
        try{
            cout<<"Enter Student "<<Student::count+1<<" details(name ,id) - "<<endl;
            cin>>s[Student::count];
            Student::count++;
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
void StudentList::showData()
{
    for(int i =0 ;i<Student::count ;++i){
            cout<<"Student "<<i+1<<" details are "<<endl;
        cout<<s[i]<<endl;}
}
void StudentList::issueBook(const Booklist &bl)
{
    cout<<"Issuing Book\n";
    unsigned  id,temp,flag=1,flagb=1,temp2;
    cout<<"Enter you student id -";
    cin>>id;
    for(int i=0;i<Student::count;++i){
        if(id == s[i].ID())
        {
            flag  = 0;
            Book b;
            cout<<"Enter book "<<" details(name ,id , no) - "<<endl;
            cin>>b;
            if(s[i].isAlreadyIssued(b)){ cout<<"Book already issued.\n";
                return;}
            for(int j=0;j<Book::count;++j)
            {
                if(b.id== bl.b[j].id && b.no == bl.b[j].no)
                {
                    flagb = 0;
                    if(bl.b[j].isAvailable()){
                        if(s[i].canIssue()){
                            bl.b[j].bookCount--;
                           s[i].bookCount;
                           b = bl.b[j];
                            s[i].stat[Status::count].update(false,b);
                            cout<<"Book Issued.\n";
                            return;}
                        else{
                            cout<<"You have exceeded the limit to issue books\n";
                            return;
                        }
                    }
                    else{
                        cout<<"Book unavailable :-(";
                        return ;
                    }
                }
            }

        }
    }
    if(flag){
        cout<<"Student not found.\n"; return ;}
    if(flagb)
        cout<<"Book not found\n";
}
void StudentList::returnBook( Booklist &bl) // wanna make const
{
    cout<<"Return Book\n";
    unsigned id,sn,flag=1,flagn=1;
    cout<<"Enter your student id -"<<endl;
    cin>>id;
    for(int i=0;i<Student::count;++i)
    {
        if(s[i].ID() == id )
        {
            flag = 0;
            Book b;
            cout<<"Enter serial no of book - "<<endl;
            cin>>b.no;
            cout<<Status::count<<endl;
            for(int j= 0;j<(Status::count);++j)
            {
                cout<<s[i].stat[j].returnserial()<<endl;
                cout<<b.no<<endl;
                if(s[i].stat[j].returnserial() == b.no)
                {
                    for(int k=0 ;k <Book::count;++k)
                    {
                        if(b.no==bl.b[k].no)
                        {
                            flagn = 1;
                            for(int l =0 ;i<(Status::count);++l)
                            {
                                if(s[i].stat[l].returnserial()==b.no)
                                {
                                    bl.findDetails(b);
                                    s[i].stat[l].update(true,b);
                                    bl.b[k].bookCount++;
                                    s[i].bookCount--;
                                    cout<<"Book returned";
                                    return;
                                }

                            }
                        }
                    }
                }
            }
        }
    }
    if(flag){
        cout<<"Student not found"<<endl; return; }
    if(flagn){
        cout<<"Book wasn't issued to you.\n";
    }

}
