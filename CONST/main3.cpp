#include <bits/stdc++.h>
using namespace std;

//solutions to remove conflict between logical and bitwise constness

//1
class BigArray{

    vector<int> v;
    mutable int counter;
    // to ensure logical constness at line 13

    public:
     int getItem(int index) const{
        counter++;
        return v[index];
     }
};


//2
class AnotherBigArray{
    vector<int> v;
    int counter;
    // counter not a mutable

    public:
     int getItem(int index) const{
        const_cast<AnotherBigArray*> (this)->counter++;

        //casts out the constness of counter
        return v[index];
     }
};

