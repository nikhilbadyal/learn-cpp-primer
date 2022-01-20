#include<iostream>
#include<string>
#include<cctype>
using std::string ; using std::cin ; using std::cout ; using std::cin ; using std::endl;
int main()
{
    /*  STrings - strings are variable sized  sequence of characters.

    1. INITIALIZING strings
    Every class defines how its object will be initialized. Some of the ways string class defines are

    string s1 ; // default initialization
    string s2 = s1; // s2 is copy of s1 // copy initialize
    string s21(s2);
    string s3("Riya"); // s3 is copy of string literal  // null is not included
    string s31 = "Riya"; // null not include // copy initialize
    string s4(10, 'n'); // s4 is nnnnnnnnnn.
    // other than = means direct initialization

    2. Operations on strings


    string s;
    string s1;
   // cin>>s;  // reads until white space
    getline(cin,s1); // read line of input
    cout<<s1<<endl;
    cout<<s<<endl;
    if(s.empty())
        cout<<"Empty";
    cout<<s1.size()<<endl;
    cout<<s.size()<<endl;
    cout<<s1[3]<<endl;
    cout<<s[3]<<endl;
    string s3 = s1  +s;
    cout<<s3<<endl;
    if(s3==s1)
        cout<<"Equal"<<endl;
    s = s1;
    cout<<s<<endl;
    if(s1>s3)
        cout<<"Greater"<<endl;
   // reading unknown number of strings
    string line;
    while(cin>>line)
        cout<<line; // read until end of file

    // Reading line using getline;
    string line;
    while(getline(cin,line)){
            if(line.size()>10)
        cout<<line<<endl;}

    3. std::size_t
    it is logical to expect that size return int or thinking an unsigned int but in actual
    size returns size_t
    hence we must use size_t but as size_t is cumbersome we can use auto or decltype
    auto a = s.size()
    string s = "Hello";
    string t = "Hello nikhil";
    string u = "Hii";
   // s is shorter than t but u is greater than both s and t.
   if(t>s){
    cout<<"Crap"<<endl;}
   if(u>t && u>s){
    cout<<"Double crap"<<endl; }
    // whenever we mix strings , string or  char literals one type must be string
    string s1{"nikhil"};
    string s4 = s1 + ", "; // ok: adding a string and a literal
 //   string s5 = "hello" + ", "; // error: no string operand
    string s6 = s1 + ", " + "world"; // ok: each + has a string operand
    string s7 = "hello" + ", " + s2; //error can't add literals

    4. Dealing with character of a string

    They can be processed mainly with cctype header
    string s = "Nikhil@4";
    int i =0,count=0;
    while(s[i]!= '\0'){
            if(isalnum(s[i])){
               count++; i++; }
            else
                i++;
    }
    cout<<"No, of alphanumerics are "<<count<<endl;
    i =0,count=0;
    while(s[i]!= '\0'){
            if(isdigit(s[i])){
               count++; i++; }
            else
                i++;
    }
    cout<<"No, of digits are "<<count<<endl;
    i =0,count=0;
    while(s[i]!= '\0'){
            if(isalpha(s[i])){
               count++; i++; }
            else
                i++;
    }
    cout<<"No, of alphabets are "<<count<<endl;
    i =0,count=0;
    while(s[i]!= '\0'){
            if(isprint(s[i])){
               count++; i++; }
            else
                i++;
    }
    cout<<"No, of printable are "<<count<<endl;
    i =0,count=0;
    while(s[i]!= '\0'){
            if(ispunct(s[i])){
               count++; i++; }
            else
                i++;
    }
    cout<<"No, of punctuations are "<<count<<endl;
    i =0,count=0;
    while(s[i]!= '\0'){
            if(isupper(s[i])){
               count++; i++; }
            else
                i++;
    }
    cout<<"No, of Upper case are "<<count<<endl;
    return 0;

    4. We can use range statement if we want to perform action with every character.

    for(declaration : expression)
        statement
    string s("Nikhil Badyal");
    int i =0;
    for(auto &c : s )
        c = toupper(c);
    cout<<s<<endl;

    string ss("Nikhil");

    ss[3] = 's';
    cout<<ss<<endl;

    if(!s.empty())
       s[0] = tolower(s[0]);
    cout<<s<<endl;

    for(decltype(s.size()) i = 0; i != s.size() && !isspace(s[i]); i++)
        s[i] = tolower(s[i]);
    cout<<s<<endl;

    //string literals are arrays of const char have /0 in end

    char literals are just char

    5. We can also do random access using subscript operator  */
    string s1("nikhil");

    char s[4] ="nik";
    s[1]= 'g';
//    char *s = s1;  //error as we can't use c++ string to initialize c char pointer
//    char *s = s1.c_str();  // type of returning pointer is const

}
