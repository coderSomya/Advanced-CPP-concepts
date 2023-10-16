#include <bits/stdc++.h>
using namespace std;
//const used with functions

class Dog{
    int age;
    string name;

    public:
    Dog(){
        age=3;
        name="dummy";
    }
    
    //const parameter
    void setAge(const int &a){
        age =a;
        a++;
        //throws error to prevent modification of foreign variables
    }

    //const return value
    const string& getName(){
        return name;
    }
    //caller cannot modify the attribute


    //const function
    void printDogName() const{
        cout<<name<<endl;
    }
    //doesn't change anything inside it
    //can be overloaded
};

int main(){
    Dog d;

    int i=9;

    d.setAge(i);
    std::cout<<i<<'\n';
}