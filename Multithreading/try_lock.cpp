#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
using namespace std;
using namespace std::chrono;

mutex m;
mutex m1, m2;

void print(int a){
    for(int i=0;i<5;i++){
        if(m.try_lock()){
            if(a==1)
            cout<<"Printing for thread 1"<<endl;
            else
            cout<<"Printing for thread 2"<<endl;
        }
        else{
            if(a==1)
            cout<<"Not able to lock for thread 1"<<endl;
            else
            cout<<"Not able to lock for thread 2"<<endl;
        }
    }
}

void print2(int a){
    if(a==1){
       this_thread::sleep_for(seconds(3)); 
    }
if(try_lock(m1, m2)==-1){
    cout<<"both threads are locked"<<endl;
    //m1.unlock();
    this_thread::sleep_for(seconds(5));
}
else{
    cout<<"Index of mutex which was locked and now unlocked : "<<try_lock(m1,m2)<<endl;
}
    //unlocking
    m1.unlock();
    m2.unlock();
}

int main(){
    // thread t1(print, 1);
    // thread t2(print, 2);

    thread t1(print2,0);
    thread t2(print2,1);

    t1.join();
    t2.join();

    return 0;
}