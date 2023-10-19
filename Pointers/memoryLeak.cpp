#include <bits/stdc++.h>
using namespace std;

class Wrapper{

    private:
     int a;

    public:
     Wrapper(int x): a(x){

     }

     ~Wrapper(){
        delete a;
     }

     //RAII - Resource acquisition in initialization
}

int main(){

    int a=10;
    //this creates a memory on the stack

    int *b = new int(10);
    //this creates a memory on the heap, and the address is stored in b in the stack
   
    //if we don't delete b, it will stay in the memory

    delete b;

    //to let the user not have to implement this manually everytime,
   
    Wrapper wrapper(10);

    //memory is not leaked
}