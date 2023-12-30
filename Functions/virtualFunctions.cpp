/*
dynamic polymorphism.

virtual functions cannot be static and also cannot be friend function of another class

a class can have virtual destructor but cannot have virtual constructor

a class having pure virtual function is called an abstract class

if u want derived classes to compuslsorily have a particular function, declare it as a pure virtual function in base class, then it cannot be inherited untill the pure virtual function is inherited

*/


#include <iostream>
using namespace std;

class Base {
    public:
     void fun(){
        cout<<"inside base class"<<endl;
    }
    virtual void gun(){
        cout<<"inside gun class in base"<<endl;
     }

    //virtual void pure()=0;

     //pure virtual function 
};

class Derived : public Base{
 public:
    void fun(){
        cout<<"inside derived class"<<endl;
    }
    void gun(){
        cout<<"inside gun class in derived"<<endl;
    }
};

int main(){
    Base *b = new Derived();
    b->fun();
    b->gun();

    return 0;
}

