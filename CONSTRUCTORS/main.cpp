#include <bits/stdc++.h>
using namespace std;

class collar{
    public:
     collar(string color){std::cout<<"collar is born\n";}
};

class dog{
    collar m_collar;
};

class cat{
    string &name;

    //prevents creation of a copy constructor,
    //as reference cannot be copied

    //also, reference cannot be left uninitialized


};

int main(){
    //dog dog1;

    /*
    error because dog doesn't have a default constructor, so compiler tries to initialize the data members of dog by default, which is m_collar. Now collar cannot be initialized by default as it has a parameterized constructor
    */
}