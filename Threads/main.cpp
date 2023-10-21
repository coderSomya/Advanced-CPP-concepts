#include <iostream>
#include <thread>


typedef unsigned long long ull;

using namespace std;
using namespace std::chrono;

ull oddsum=0;
ull evensum=0;

void findEven(ull start, ull end){
    for(ull i=start; i<=end; i++){
        if((i&1)==0) evensum+=i;
    }
}

void findOdd(ull start, ull end){
    for(ull i=start; i<=end; i++){
        if(i&1) oddsum+=i;
    }
}

ull starting=1;
ull ending=1900000000;

int main(){

    //single threading
    
    auto START=high_resolution_clock::now();

    findEven(starting,ending);
    findOdd(starting, ending);
    std::cout<<evensum<<" "<<oddsum<<"\n";

    auto END=high_resolution_clock::now();
    auto time=duration_cast<microseconds>(END-START);

    cout<<time.count()/1000000<<endl;

    //multi threading

    START=high_resolution_clock::now();

    std::thread t1(findOdd, starting, ending);
    std::thread t2(findEven, starting, ending);

    t1.join();
    t2.join();

    END=high_resolution_clock::now();
    time=duration_cast<microseconds>(END-START);

    cout<<time.count()/1000000<<endl;

    return 0;
}