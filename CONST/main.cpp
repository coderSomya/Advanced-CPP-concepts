/*
const ->
A "compile time" constraint that an object can not be modified
*/

int main(){

    const int i=9;
    i=8;// bad
    

   const int *p1=&i; //data is const, pointer is not
   *p1=5; //bad
    p1++;//good

    int* const p2; //pointer is const, data is not

    const int* const p3 //data and pointer both are constant

    const_cast<int&> (i)=6;
    //good
    
    int j;
    //some code
    static_cast<const int&> (j)=7;
    //j is const from now on

}