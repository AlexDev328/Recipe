#include "dynamicarray.h"
#include <iostream>
using namespace std;

template<class T>
DynamicArray<T>::DynamicArray(const DynamicArray& arr) {
   size = arr.size;
   count = arr.count;
   p = new T[size];
   for(int i = 0; i<count; ++i)
      p[i] = arr.p[i];
}

template<class T>
DynamicArray<T>&
DynamicArray<T>::operator=(const DynamicArray& arr) {
   if(this != &arr) {                  //если присваивается смому себе
      size = arr.size;
      count = arr.count;
      if(p) delete[] p;
      p = new T[size];
      for(int i = 0; i<count; ++i)
         p[i] = arr.p[i];
   }
   return *this;
}

template<class T>
T DynamicArray<T>::operator[](long i) const {
   if(i < size && i)
      return p[i-1];
   else
      return 0;
}

template<class T>
DynamicArray<T>&
DynamicArray<T>::operator+(const DynamicArray& arr) {
   DynamicArray temp(*this);
   if(p) delete[] p;
   size += arr.size;
   count += arr.count;
   p = new T[size];
   for(int i = 0; i<temp.count; ++i)
      p[i] = temp.p[i];
   for(int i = 0; i<arr.count; ++i)
      p[temp.count + i] = arr.p[i];
   return *this;
}

template<class T>
void DynamicArray<T>::print() const {
   for(int i = 0; i<count; ++i)
      cout<<p[i]<<endl;
}


template<class T>
void DynamicArray<T>::add(T x) {
   if(count >= size) {
      DynamicArray temp(*this);
      if(p) delete[] p;
      size += 10;
      p = new T[size];
      for(int i = 0; i<temp.count; ++i)
      p[i] = temp.p[i];
   }
   p[count++] = x;
}

template<class T>
void DynamicArray<T>::add(T x, int index) {
    if(index > 0 && index < count)
    {
        if(count >= size)
        {
           DynamicArray temp(*this);
           if(p) delete[] p;
           size *= 2;
           p = new T[size];
           for(int i = 0; i<temp.count; ++i)
           p[i] = temp.p[i];
        }
        for(int i=size;i> index;i--) p[i]=p[i-1];
        p[index]=x ;
     }
}

template<class T>
void DynamicArray<T>::addwithsort(T x) {
   if(count >= size) {
      DynamicArray temp(*this);
      if(p) delete[] p;
      size *= 2;
      p = new T[size];
      for(int i = 0; i<temp.count; ++i)
      p[i] = temp.p[i];
      temp.remove();
   }

    if( count==0)
    {
        p[count++]=x;
    }
    else{
   int i=0;
   while ((p[i]<x && i<count)) //ищем место, куда поставить случайное число
       i++;
   for (int j=count; j>i; j--) //сдвигаем все элементы массива на 1 в конец, чтобы вставить случайный элемент
       p[j]=p[j-1];

   p[i]=x;
   count++;
//вставляем на найденное место случайный элемент
   //p[count++] = x;
    }
}


/*
template<class T>
void DynamicArray<T>::remove() {
   if(count)
      p[--count] = 0;
}
*/
