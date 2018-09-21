#include "recipe.cpp"
#include "dynamicarray.cpp"
using namespace std;


//test  DynamicArray class
int main() {
   DynamicArray <Recipe> da(1);
   Recipe book;
   book.mainingr="aaaaaaaaaa";
   book.name="cook";
   book.time=12;
   da.addwithsort(book);
   book.mainingr="abbbbbbbb";
   book.name="cook";
   book.time=12;
   da.addwithsort(book);
   book.mainingr="abcccc";
   book.name="cook";
   book.time=12;
   da.addwithsort(book);
   da.print();

   cout<<da.getCount()<<endl;
   cout<<da.length()<<endl;
   DynamicArray <Recipe> da1(3);
   da1=da+da;
   da1.print();
   cout<<"Press any key..."<<endl;
   getch();
   return 0;
}
