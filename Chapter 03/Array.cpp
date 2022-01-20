#include<iostream>
#include<vector>
#include<string.h>
#include<cstddef>
//using namespace std;
using std::cin ; using std::cout; using std::endl; using std::vector ; using std::string; using std::begin; using std::end;
int main()
{
    /* Arrays - arrays are another type of data structure which are used to store similar kind of objects]
     arrays are fixed in sized an can't be increased at run time.
     Array declarators are of type a[d] where d is dimension. hence d must be known and must be an constant expression

     unsigned size = 20;
     int arr[size];
     string cnt[size];

     1. Initializing an array -
     We can list initialize an array and when we do so . We may skip dimensions
     const int size = 5;
     int arr[] = {1,2,3};
     int arr[size] = {1,2,3};
     int arr[size] = {1,2,3} // {1,2,3,0,0}

     a. character arrays are special
     char a1[] = {'a','b'};// without null;
     char a2[] = {'a','c','\0'};// with null;
     char a3[] = "C++"; // add null automatically
     //we can't copy or assign array.
     char a[] = a1;
     char a[] = a1;
     a = a1;

     int arr1[2] = {1,2};
     int *arr[2]; //array of pointer
     int (*ptr)[2] = &arr1; //pointer to array of 10 ints
//     int (&refer)[10]; // error
     int (&refer)[2] = arr1; // error
     int *(&ref1)[2] = arr;

    // cout<<refer[1]<<endl;
     string s[10]; // Array of 10 string // empty initialized
     int arr4[19]; // uninitialized

     int arr[] = {1,2,3,4,5};
     for( auto &i : arr){
        i = i*i;
     }
     for(auto i : arr)
        cout<<i<<endl;

    2. Pointers and arrays

    compiler normally converts array to pointer

    we obtain pointer to an object by using & operator. address of operator can be applied to any object

    string s[] = {"nikhil ", "aikhil ", "tania"};
    string *p  = &s[0];
    // However arrays have property that name of array gives pointer to first element
    string *q = s ; //  string *q  = &s[0];
    cout<<*p<<endl;
    cout<<*q<<endl;

    auto ss = s;
   // ss = "n"; //error as ss is pointer to array
    ss = &q[0];

    // but thing thing doesn't happen with decltype
    decltype(s) s_ = {"nikhil ", "aikhil ", "tania"};

    3. Pointers are iterators

    except the properties mentioned pointers also behave like iterators for arrays ie we can increment or decrease them

     int arr[] = {1,2,3,4,5};
     int *p = arr;
     ++p ; // p point to arr[1]

     int *e = &arr[5];
     for(int *b = arr ;b != e; b++)
        cout<<*b<<endl;

     // although we can get begin and end with this but it is error prone so we have two function end and begin since
    arrays are not class type they are not member function
    int arr[] = {1,2,-3,4,5};
    int *beg = begin(arr);
    int *last = end(arr);  //pointer to one last of array

    cout<<(*beg)<<endl; //pointer to first element
    while(beg != last && *beg >= 0){
            auto  a = *beg;
            cout<<a<<endl;
            cout<<(*beg)<<endl;
        beg++;}

    const int size = 10;
    int arr[size] = {1,2,3,4,5,6};
    int *ip = arr;
    int *ip2 = ip+4;  // it point to arr[4

    auto n = end(arr) - begin(arr); // n is of type  ptrdiff_t
   // cout<<n;

    int *b = arr; int *e = arr+ size;
 //   cout<<*b<<endl;
    while(b<e){
        cout<<*b<<endl;
        b++; }
    cout<<*(arr+5)<<endl;
    cout<<*arr+500<<endl;

    int *p = &arr[2];
    int j = p[1]; // same as *(arr+1) = *(arr+3)
    cout<<j<<endl;
    int k = p[-2]; // arr[0]

    int *i = arr;
    cout<<*i<<endl;
    cout<<i[1]<<endl; // i[m] = *(i+m)

    3. Multi-dimensional arrays

    multi arrays are basically arrays of array . it means when elements of an array are in turn  array
    we make such array by  defining two dimensions

 //   int arr[3][4]; // arr is an array of 3 size in which each element is array if int of size 4
    int arr1 [10][20][30] = {} ;// arr is an array of size 10 in which each element is an array of size 20 in which each array is array of isze 30
    int arr[3] [4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,8,7,6}
                 };  // here nested braces are optional we can do something like this
    int arrr[2][2] ={1,2,3,4};

    int arr3[2][2] = {{1},{2}}; // explicitly initialize only 1st element
    int arr4[2][2]= {0,1}; //initialize only 1 row
    int arr5[3][3];
    arr5[1][2] = arr1[0][0][0]; // assign 1st element of arr1 to the last element  and in the last row
    int (&row)[4]= arr[1]; // row binds to second row of arr;

    int arr[3][3];
    for(size_t i=0 ; i!=3 ; i++){
        for(size_t j =0 ; j!=3;j++)
        {
            arr[i][j] = i*3 + j;
        }
    }

    for(auto &l : arr) // here l is int* and
        cout<<l<<endl;

    for (const auto &row : arr) // for every element in the outer array
        for (auto col : row) // for every element in the inner array
             cout << col << endl;
   for(size_t i =0;i !=3 ;i++){
        for(size_t j=0 ;j!=3;j++){
            cout<<arr[i][j]<<endl;
        }
    }

    //using range with MDA
    for(auto &i : arr)
        for(auto &j : i)
            cout<<j<<endl;

   5. Pointers and MDA


   int ia[3][4]= {1,2,3,4,5,6,7,8,9,8,7,6}; // array of size 3; each element is an array of ints of size 4
   int (*p)[4] = ia; // p points to an array of four ints
    p = &ia[2];
    cout<<p<<endl<<*p<<endl<<**p;


    int ia[3][4]= {1,2,3,4,5,6,7,8,9,8,7,6};
    using int_array = int[4];
    typedef int int_array[4]; // equivalent typedef declaration; § 2.5.1 (p. 67)
    // print the value of each element in ia, with each inner array on its own line
    for (int_array *p = ia; p != ia + 3; ++p) {
    for (int *q = *p; q != *p + 4; ++q)
    cout << *q << ' ';
    cout << endl;
    }
     */


    return 0;
}
