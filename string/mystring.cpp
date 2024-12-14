#include <iostream>
#include<vector> 
using namespace std;

class mystring{
    private:
    vector<char> str;

    public:
    mystring(const char *c){
        while(*c){
            str.push_back(*c++);
        }
    }
    mystring operator+ (const mystring &b){

        for(auto i : b.str){
            this->str.push_back(i);
        }
        return *(this);
    }

    void print(){
        for(auto i : str){
            cout<<i;
        }
    }
};

int main(){
    mystring s("srijan");
    s=s+" singh";
  //  s.push_back('a'); -->because we have not inherited the vector behviour

    s.print();
    return 0;
}