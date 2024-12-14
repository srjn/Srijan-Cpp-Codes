#include <iostream>
using namespace std;
//1. compile - time polymorphism
class fun_overloading{
    public:
    void print(){
        cout<<"printing "<<endl;
    }

    void print(string name){
        cout<<"printing "<<name<<endl;
    }

    void print(int number){
        cout<<"printing "<<number<<endl;
    }
    void print(int a, int b, int c=0, int d=1){
        cout<<"printing "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    }
};
//operator_overloading
class complex{
    private :
    int real;
    int imaginary;

    public:
    complex(int a, int b){
        this->real= a;
        this->imaginary= b;
    }

    void print(){
        cout<<real<<" + "<<imaginary<<"i"<<endl;
    }

    complex operator+ (const complex &c){
        return complex(this->real + c.real, this->imaginary + c.imaginary);
    }
};
//2. Run - time polymorphism
//method overriding
class father{
    public:
    void identity(){
        cout<<"i am father"<<endl;
    }

};

class son : public father{
    public:
    void identity(){
        cout<<"i am son"<<endl;
    }
};

int main(){
    fun_overloading obj;
    // obj.print();
    // obj.print("srijan");
    // obj.print(1);
    // obj.print(1,2);
    // obj.print(1,2,3);
    // obj.print(1,2,3,4);

    // complex c1(1,2);
    // complex c2(2,3);

    // complex c = c1+c2;
    // c.print();


    son name;
    name.identity();

    return 0;
}