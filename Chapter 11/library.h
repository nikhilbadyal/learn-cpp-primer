class Book{
public:
    // Constructor
    Book() {}

    static int bookCount;

    //Friends
    friend ostream & operator<<(ostream & , Book& );
    friend istream & operator>>(istream & , Book& );


    //Functions
    void get_data();
    const long int& returnBookId() {return bookId;}
    int& returnCount() {return count;}
    const string& returnSerial() {return serial;}

protected:
    long int bookId = 0 ;
    string serial = " ";
  /*  string title = " ";
    string author = " ";
    string publisher = " ";
    int price = 0;*/
    int count = 20;
};
int Book::bookCount = 0;


class BookList{
public:

    // Static Member
    Book book[10];

    // Functions
    void enterBooks();
    int find_details(string  );
    void checkAvailability();
};

class Member {
public:

    //Constructor
    Member() {}

    //Friends
    friend ostream & operator<<(ostream & , Member& );
    friend istream & operator>>(istream & , Member& );

    //Functions
    const long int& returnMemberId() {return memberId;}

protected:

    long int memberId = 0 ;
    string name = " ";
  /*  string email = " ";
    string address = " ";*/
};

class Transaction{

public:

    //Constructor
    Transaction() : b() {}

    //Functions
    static int transactionCount;
    void update_transaction(Book& , bool);
    void showTransaction();
    int returnTransactionCount() {return transactionCount;}
    bool returnReturned() {return returned;}
    Book& returnBook() {return b;}

protected:

    Book b;
    bool returned = true;
};
int Transaction::transactionCount = 0;

class Student : public Member{
public:

    //Constructors
    Student() : Member() , t() {}

    // Static members
    static int studentCount;

    //Functions
    void get_data();
    bool check_issued(string );
    void showStudentTransaction();
    int& returnCount(){return count;}

    //Friendship

    Transaction t[10] ;
private:
    int count = 0;
};
int Student::studentCount = 0;

class StudentList{
public:

   // friend class MemberList;
    Student student[10];
    void issueBook(long int, int ,BookList &);
    void returnBook(long int, int , BookList & );
public:
    StudentList() {}
    void enterStudents();
    void showStudent(int );
};

class Faculty : public Member{
public:

    //Constructors
    Faculty() : Member() , t() {}

    // Static members
    static int facultyCount;

    //Functions
    void get_data();
    bool check_issued(string );
    void showFacultyTransactio();
    //Friendship

    Transaction t[10] ;
    int& returnCount() {return count;}
private:
    int count = 0;
};

class FacultyList{
public:

    FacultyList()  {}
    void enterFaculty();
    void showFaculty(int );
    void issueBook(long int,int,BookList &);
    void returnBook(long int ,int,BookList &  );
public:
    Faculty faculty[10];

};
class MemberList{
public:
    MemberList() : f() , s(){}
    FacultyList f;
    StudentList s;
    tuple<long int,int,int> verifyMember();
    void issueRequest(BookList &);
    void returnRequest(BookList &);
    void enterMember();
    void showMemberDetails();
};


