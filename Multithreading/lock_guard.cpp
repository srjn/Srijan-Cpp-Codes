#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
using namespace std;
using namespace std::chrono;

mutex m;

void print(int a){
    lock_guard<mutex> lock(m);
    for(int i=0;i<5;i++){
    cout<<"Running thread : "<<a<<endl;
    }
}

int main(){
    thread t1(print, 1);
    thread t2(print, 2);

    t1.join();
    t2.join();

    return 0;
}