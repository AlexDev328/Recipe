
#include <iostream>
#include <conio.h>

template<class T>
class DynamicArray {
    long size;        //size of the array
    long count;       //count of elements
    T* p;             //pointer to the beginning of the array

  public:
    //constructors
    DynamicArray(long s = 10): size(s), count(0) {
       p = new T[size];
    }
    DynamicArray(const DynamicArray& arr);

    //destructor
    ~DynamicArray() {
       if(p) delete[] p;
    }

    //member functions
    void add(T x);
    void add(T x,int index);
    void addwithsort(T x);
    void remove();
    long length() const {return size;}
    long getCount() const {return count;}
    void print() const;

    //operators
    DynamicArray& operator=(const DynamicArray& arr);
    T operator [] (long i) const;
    DynamicArray& operator+(const DynamicArray& arr);
};
