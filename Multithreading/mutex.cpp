#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
using namespace std;
using namespace std::chrono;

mutex m;

void square(int &a){
    m.lock();
    a*=a;
    m.unlock();
}

void increament(int &a){
    m.lock();
    a++;
    m.unlock();
}

int main(){
    int a=5;

    auto start1=high_resolution_clock::now();
    thread t1(square, ref(a));
    auto start2=high_resolution_clock::now();
    thread t2(increament, ref(a));

    t1.join();
    t2.join();

    cout<<a<<endl;

    duration<double> diff=start2-start1;

    cout<<"diffrence is : "<<diff.count()*1000000<<" micro-seconds"<<endl;
    return 0;
}