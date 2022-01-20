#include<iostream>
#include<string>
#include<vector>
#include<cctype>
#include<stdexcept>
using std::string ; using std::cin ; using std::cout ; using std::cin ; using std::endl; using std::vector; using std::runtime_error;
int main()
{
    /* Statements

    a. statement becomes an expression statement when it is followed by an semicolon
    expression statement cause expression to be evaluated and result discarded.
    hence
    i+7; // useless
    cout<<i+7; // useful

    b. Null statement - the simplest statement in c++ is null .it is just semicolon (;).
    it can be useful sometime. it is required where compiler ask for statement but our logic dont

    Beware of missing or extraneous semicolon
    int x = 4;; // it is ok as second is just null statement

    compound statements

    also known as block . a block is a scope . names inside a block are only accessible inside the block

    b. statement scope -
    we can define variables inside an if else for while but their life only within those statements


    c. conditional statements

    c++ provides two conditional statements
    1. if
    2. switch (evaluate an integral and choose one of available option

    if statement -  condition can be expression or initialized variable

    switch statements -
    these are use when we have on of many alternatives
    it starts by evaluating parenthesis expression



    int ac,ec,ic,uc,oc;
    ac=ec=ic=oc=uc = 0;
    char c;

    while(cin>>c)
    {
        switch(c){
            case 'a':
                ac++;
                break;
            case 'e':
                ec++;
                break;
            case 'i':
                ic++;
                break;
            case 'o':
                oc++;
                break;
            case 'u':
                uc++;
                break;
        }
    }
    cout<<ac<<endl<<ec<<endl<<ic<<endl<<oc<<endl<<uc<<endl;
    case keyword must be associated with an integral value
    execution of case works like - one case is matched and picked, then it is executed and then it completes and it goes
   until end of program hence we use break statement but sometime default behavior is required.
   example we may want to count number of variables then.
   char c('a');
   int count=0;
   switch(c)
   {
       case 'a':
       case 'e':
       case 'i':
       case 'o':
       case 'u':
       ++count;
       break;
   }
   cout<<count<<endl;

   we have default label where it is selected when no case matches then it is executed.

   if any case has variables then language dont allow to jump over those cases


    iterative statements

    variables declared in condition or body are destroyed after each execution

    for(int i = 0, z = 10;  i<19;i++) //type must be same for both  declaration
   {
       i++;
   }
   for(init ; condition ; statement)
    omitting condition means making it true;


    range for loop
    for (declaration : expression)
          statement

    expression must represent an sequence such as list array vector string

    if we want to write then it must be an reference
    they may not be used where we want to add


    4. JUMP statements

    c++ provides 4 jump statements

    a. break

    it breaks the nearest working do while, while , for, switch statement
    it can appear only in iteration or switch statement

    b. A continue statement terminates the current iteration of the nearest enclosing loop
    and immediately begins the next iteration
    A continue can appear only inside a for, while, or do while loop, including inside
    statements or blocks nested inside such loops.
    in simpler terms when continue executes all the statements after it are skipped.


   string buf;
while (cin >> buf && !buf.empty()) {
if (buf[0] != '_')
continue; // get another input
// still here? the input starts with an underscore; process buf . . .
}
cout<<buf;

   c. goto statements - they helps us to make unconditional jumps
    goto label;
    where label is a statement

    A labeled statement is any statement that is preceded by an identifier followed by a colon

    labels are independent of the named hence they can have any name
    goto and label must be in same function


    As with a switch statement, a goto cannot transfer control from a point where an initialized
    variable is out of scope to a point where that variable is in scope:

    goto end;
    int x = 10;
    end:
     x = 23; //error

     jumping back destroys a variable and makes it again



     exception handling

     exception can be run time anomalies. and handling these is important thing
     it is generally used when program detects that  the error or abnormality cant be handled .

     it involves

     1. throw expressions
     2. try blocks  - also known as exception handlers as after thrown they come here
     3. set of exception class which defines what happens between throw and catch


     throw -

     The type runtime_error is one of the standard library exception types and is
     defined in the stdexcept header.We must initialize a runtime_error by giving it a string or a C-
     style character string (§ 3.5.4, p. 122). That string provides additional information
     about the problem.

     try block

     general form of this is -
     try {
    program-statements
    } catch (exception-declaration) {
    handler-statements
    } catch (exception-declaration) {
    handler-statements
    } //

    it begins with a keyword try and then some catch statements
    variables of try available to catch


     int x , y;
     while(cin>>x>>y){
            try{
                if(x>10){
                    throw runtime_error("Data must be less than 10");}
            }
            catch(runtime_error err){
                cout<<err.what()
                    <<"\nTry again? Enter y or n."<<endl;
                char c;
                cin>>c;
                if(!cin || c == 'n'){
                    break;}
            }
     }

     in real practice a execution may go through various functions. one function calls another
     function that contain try it may call another that  has try.

     the search for handler reverses the chain. it firstly look for handler in that function if not found then
     that function exits and command goes to the called if not found then one more step back and till end nothing
     found then it goes to terminate(a library function)it guarantee that program will terminate



     standard error--
     c++ provides many exception or error handling classes. some of these are here-

     1. The exception header defines the most general kind of exception class named exception. It
     communicates only that an exception occurred but provides no additional information
     2. The stdexcept header defines several general-purpose exception classes,
     3. The new header defines the bad_alloc exception type,
     5.  The type_info header defines the bad_cast exception type

     */



    return 0;
}
