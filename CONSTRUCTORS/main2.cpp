#include <bits/stdc++.h>
using namespace std;

class Openfile{
  public:
    Openfile(string filename){
        cout<<"opened\n";
    }

   private:
   ~Openfile(){
    cout<<"destroyed\n";
   }

   /*
   we may want to keep destructor of class
   private, but then we'll have to mechanically destroy objects
   */
  public:
   void destroyMe(){
    delete this;
   }
   
};

int main(){
    Openfile* f= new Openfile(string("new.txt"));
    //some code
    f->destroyMe();


    /*
    class type object having a private destructor can only be stored in heap, not a stack
    */
   
}
