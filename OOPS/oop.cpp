#include <iostream>
using namespace std;

class human{
    public:
    int age;
    char gender;

    public:
    human( int a, char g){
        this->age=a;
        this->gender=g;
    }

    void print(){
        cout<<"age is : "<<age<<endl;
        cout<<"gender is : "<<gender<<endl;
    }
};

class male : public human{
    public:
    int salary;

    male(int a, char g, int s) : human(a,g) {
        this->salary=s;
    }

    void print(){
        cout<<"age is : "<<age<<endl;
        cout<<"gender is : "<<gender<<endl;
        cout<<"salary is : $"<<salary<<endl;
    }
};

int main(){
    male srijan(25, 'M', 100000);

    srijan.print();
    return 0;
}