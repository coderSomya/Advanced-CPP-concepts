#include <bits/stdc++.h>
using namespace std;

//unique pointer - exclusive ownership

template <typename T>

class uniqueptr{
    private:
      T* res;

    public:
      uniqueptr(T* a=nullptr): res(a){
        cout<<"constructor\n";
      }

      uniqueptr(const uniqueptr<T>& a) = delete;
      //restricting the copy constructor

      uniqueptr& operator= (const uniqueptr<T>& a) = delete;
      //restricting the copy assignment operator
      
      uniqueptr(uniqueptr<T>&& a){
        res=a.res;
        a.res=nullptr;
      }
      //move copy constructor

      uniqueptr& operator= (uniqueptr<T> &&a){
          if(this!=&a){
            if(res) delete res;
            res=a.res;
            a.res=nullptr;
          }

          return *this;
      }
      //move assignment

      T* operator->(){
         return res;
      }

      T& operator*(){
        return *res;
      }

      T* get(){
        return res;
      }

      void reset(T* newres=nullptr){
        if(res) delete res;

        res=newres;
      }

      ~uniqueptr(){
        if(res){
            delete res;
            res=nullptr;
        }
      }
};


int main(){

    uniqueptr<int> ptr1(new int(2));
    uniqueptr<int> ptr2(ptr2);//should give compilation error

    //rather

    uniqueptr<int> ptr3=std::move(ptr1);

    //use cases:
    // ptr1->func();
    cout<<*ptr1;
    ptr1.get();
    ptr1.reset(new int(30));

    //destructor

    return 0;
}