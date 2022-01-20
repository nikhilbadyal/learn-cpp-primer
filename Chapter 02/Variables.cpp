#include<iostream>
using namespace std;
int main()
{
    /* Variables or Objects
    1.
    Initializers
    Initialization is not assignment. Initialization happens when a variable is given
     a value when it is created. Assignment obliterates an object's current value
    and replaces that value with a new one
    int a = 0;
    int b = {0};
    int c{0};
    int d(0); // This type is known as list initialization.
    long double e = 3.123553456;
 //   int f{e}; it gives warning as data loss is there
    int g(e); // it doesn't give warning even data loss is there too.

    2. Default initialization.
    variables which are not initialized are default initialized.

    a. Variables outside any function are initialized by zero.variables of built in type
    inside a function are uninitialized and the uninitialized are undefiened.


    3. declaration and definition
    extern int j ; // I just declares and doesn't define has no space allocated.
    int k; // declared and defined.
    cout<<j;
    extern int j =0; // It will give me error as it has extern and initialize.
    cout<<j;

    int _ is valid;
    4. Scopes
    int i;
    int main()
    {
    int i ;
    cout<< i<<endl; // it uses new defined i ;
    cout<< ::i<<endl; // Explicitly asking for global i;
    }

     */


    return 0;
}
