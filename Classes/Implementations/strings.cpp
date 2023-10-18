#include <string.h>
#include <iostream>
class String{

    private:
      char* res;
      unsigned int len;

    public:
      String(): res(nullptr), len(0){
          
      }  

      /*
      initialized using initializer list which is used to initialize member variables of the class. 

      there are few cases where we have to use the initializer list and we cannot initialize the variables inside the body of the constructor. some examples are:

      const int a;
      int &mem;

      this is because references and const members can only be initialized once.

      other example is:

      A obj;

      if we want to use an object of class A and class A only has parameterized constructor and not default constuctor, we have to initialize it in the initializer list.
      */


     String(const char *ch){
        len = strlen(ch);
        res= new char[len+1];
        //len + 1 because of '\0'
        strcpy(res, ch);
     }

     String(const String& str){
        len=str.len;
        res=new char[len+1];

        strcpy(this->res, str.res);
     }

     /*
     const -> to ensure that we don't change the suppplied resource.

     reference-> if we don't make it reference, it will try to make a copy of the passed parameter, which again calls the copy constructor, so the program crashes
     */

    String& operator=(const String& str){
        if(this!=&str){
            //to prevent str3=str3 type assignment
            
           delete [] res;
           len=str.len;
           res=new char[len+1];

           strcpy(res,str.res);
        }
       return *this;
    }

    //above is the implementation of copy assignment operator, this is different from copy constructor as constructor is invoked to initialize and not to modify

    /*
    alternative for assignment operator, just incase the copying fails, so we don't lose resource

    if(this!=&str){
        char* temp=this->res;
        len=str.len;

        res=new char[len+1];
        strcpy(res, str.res);

        delete[] temp;
    }
    
    another alternative using CAS
      String &operator=(String str){
        Swap(this, str);
        return *this;
      }

      void Swap(String&str1, String &str2){
        swap(str1.res, str2.res);
        swap(str1.len,str2.len)l
      }

    */

    unsigned int length(){
        return this->len;
    }

    friend std::ostream& operator<<(std::ostream &out, const String& res);
    friend std::istream& operator>>(std::istream &in, const String& res);

    String(String&& str){
        //&& -> rvalue reference, temporary object

        len=str.len;
        res= str.res;

        str=nullptr;
        str.len=0;
    }

    //destructor

    ~String(){
       if(res){
          delete[] res;
          res=nullptr;
          len=0;
       }  
    }

};


/*
how to implement cout and cin?

we cannot go inside the implementation of cout and cin, as provided by stl..

so we have to make a overload the function having the stream and String we want to print.

Also, notice that res is private member of String so we have to make the print and input friend fuctions of String class

*/


std::ostream& operator<<(std::ostream &out, const String& str){
   out<<str.res;
   return out;
   //we are returning the out to handle chaining
}

std::istream& operator>>(std::istream &in, const String& str){
   in>>str.res;
   return in;
}

int main(){

    String str1; //default
    String str2="hello"; //parameterized
    String str3(str2); //copy

    str3=str1;//copy assignment

    int len=str2.length(); //length

    std::cin>>str1; //input overload
    std::cout<<str2; //output overlaod

    String str5=std::move(str2);
    //this transfers content from str2 to str5, and str2 is deleted
}