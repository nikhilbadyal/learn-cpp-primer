#include<iostream>
#include<string>
#include<vector>
#include<cctype>
#include<stdexcept>
#include"Member.h"
#include"Student.h"
#include"Faculty.h"
using std::istream; using std::ostream;
using std::string ; using std::cin ; using std::cout ; using std::cin ; using std::endl; using std::vector; using std::runtime_error; using std::end; using std::begin;
class MemberList{
public:
    StudentList sl;
    FacultyList fl;
    int verifyMember();
    void issueRequest(const Booklist &);
    MemberList() {}
};
int MemberList::verifyMember()
{
    unsigned int id,flag=1,check;
    cout<<"Enter 0 for student . 1 for faculty.\n";
    cin>>check;
    if(check){
        cout<<"Enter faculty id -";
        cin>>id;
        flag = 0;
        for(int i = 0;i<Faculty::count;++i)
        {

            if(id == fl.f[i].ID())
                return 1;
        }
        return -1;
    }
    if(!check){
        cout<<"Enter Student id -";
        cin>>id;
        flag = 0;
        for(int i = 0;i<Student::count;++i)
        {
            if(id == sl.s[i].ID())
                return 0;
        }
        return -1;
    }
    if(flag){
        cout<<"Error verifying details.\n"; exit(0);}
}
void MemberList::issueRequest(const Booklist &bl)
{

    switch((verifyMember()))
    {
        case 0: sl.issueBook(bl);
                break;
        case 1 : fl.issueBook(bl);
                 break;
        case -1 : cout<<"No member exist.\n";
                  break;
        default : "Can't verify member.\n";
    }
}
