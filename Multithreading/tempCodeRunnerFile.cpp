#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

void square(int a){
    cout<<a*a<<endl;
}

void increament(int a){
    a++;
    cout<<a<<endl;
}

int main(){
    int a=5;

    thread t1(square, a);
    thread t2(increament, a);

    t1.join();
    t2.join();
    return 0;
}