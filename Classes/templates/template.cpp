#include <bits/stdc++.h>
using namespace std;

template<class T>

class Test{
  
  T obj;
  public:
   Test(T obj){
    this->obj= obj;
   }

   void print(){
    cout<<obj<<endl;
   }
};

int main(){

  Test<string> test1("hello");
  Test<int> test2(1);

  test1.print();
  test2.print();
  return 0;
}