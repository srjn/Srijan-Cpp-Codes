#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
using namespace std;
using namespace std::chrono;

recursive_mutex m;

void recursive_print(int i, int a){
    if(a==5)
    return;

    m.lock();
    cout<<"thread "<<i<<" is locked"<<endl;
    recursive_print(i, a+1);
    cout<<"thread "<<i<<" is unlocking"<<endl;
    m.unlock();
}

void iterative_print(int i, int a){
    for(int j=a;j<5;j++){
        m.lock();
        cout<<"thread "<<i<<" is locked"<<endl;
    }

    for(int j=a;j<5;j++){
        cout<<"thread "<<i<<" is unlocking"<<endl;
        m.unlock();
    }
}

int main(){
    // thread t1(recursive_print, 1, 1);
    // thread t2(recursive_print, 2, 3);

    thread t1(iterative_print, 1, 1);
    thread t2(iterative_print, 2, 3);

    t1.join();
    t2.join();

    return 0;
}