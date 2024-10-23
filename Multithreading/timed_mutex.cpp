#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
using namespace std;
using namespace std::chrono;

timed_mutex m;

void print(int a){
    if(m.try_lock_for(seconds(2))){
        cout<<"thread "<<a<<" is locked"<<endl;
        this_thread::sleep_for(seconds(3));
        m.unlock();
    }
    else{
        cout<<"thread "<<a<<" is not able to lock"<<endl;
    }
}

void print2(int a){
    auto now=steady_clock::now();
    if(m.try_lock_until(now + seconds(2))){
        cout<<"thread "<<a<<" is locked"<<endl;
        //this_thread::sleep_for(seconds(3));
        m.unlock();
    }
    else{
        cout<<"thread "<<a<<" is not able to lock"<<endl;
    }
}

int main(){
    // thread t1(print, 1);
    // thread t2(print, 2);

    thread t1(print2, 1);
    thread t2(print2, 2);

    t1.join();
    t2.join();

    return 0;
}