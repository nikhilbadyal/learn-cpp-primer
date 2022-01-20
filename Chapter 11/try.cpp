#include<iostream>
#include <string>

using namespace std;
template<class T>
class sArr
{
private:
    int Size;
    int nrOfEl;
    T *arr;

public:
    sArr(int size = 5);
    ~sArr();
    int size()const;
    void add(const T &obj);
    T& get(int index);

};
template<class T>
sArr<T>::sArr(int size)
{
    this->Size = size;
    this->nrOfEl = 0;
    this->arr = new T[this->Size];

}
template<class T>
sArr<T>::~sArr()
{
    delete[] this->arr;
}

template<class T>
int sArr<T>::size()const
{
    return this->nrOfEl;
}
template<class T>
void sArr<T>::add(const T &obj)
{
    if (this->nrOfEl < this->Size)
         this->arr[this->nrOfEl++] = obj;
    else
         cout << "Array is full :(" << endl;

}
template<class T>
T& sArr<T>::get(int index)
{
    if (index < 0 || index >= this->nrOfEl)
           throw"Bad index!";
    return this->arr[index];

}
int main()
{
    sArr<int> mia(10);
    sArr<string> msa(10);
    for (size_t i = 0; i < 10; i++)
    {
        mia.add(10);
        msa.add("HELLO!");
    }
    for (size_t i = 0; i < 10; i++)
    {
        cout << mia.get(i) << endl;
        cout << msa.get(i) << endl;
    }
    return 0;
}
