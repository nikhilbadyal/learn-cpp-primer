#include<iostream>
#include<string>
#include<vector>
#include<cctype>
#include<stdexcept>
using std::istream; using std::ostream;
using std::string ; using std::cin ; using std::cout ; using std::cin ; using std::endl; using std::vector; using std::runtime_error; using std::end; using std::begin;

class Status {
public:
    static int count;
    unsigned returnserial(){return book.returnSerial();}
    unsigned returnid(){return book.returnid();}
    void update(bool,Book  );
    Status() {count = 0;}
    void show()
    {
        cout<<endl<<book;
    }
private:
    Book book;
    bool status ;
};
void Status::update( bool t,Book b)
{
    book = b;
    status = t;
    if(t)
        Status::count--;
    else
        Status::count++;
}
int Status::count= 0;
