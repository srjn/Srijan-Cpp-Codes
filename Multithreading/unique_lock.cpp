#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
using namespace std;
using namespace std::chrono;

mutex m1, m2;

void print_with_lock_guard(int a){
    lock_guard<mutex> lock(m1);
    for(int i=0;i<5;i++){
    cout<<"Running thread : "<<a<<endl;
    }
}
void print_with_unique_lock(int a){
    unique_lock <mutex> lock(m2);
    for(int i=0;i<5;i++){
    cout<<"Running thread : "<<a<<endl;
    }
}

int main(){
    // thread t1(print_with_lock_guard, 1);
    // thread t2(print_with_lock_guard, 2);

    thread t1(print_with_unique_lock, 1);
    thread t2(print_with_unique_lock, 2);

    t1.join();
    t2.join();

    return 0;
}

/*A unique_lock in C++ is a more versatile locking mechanism compared to lock_guard. Both are part of the C++ Standard Library and help manage mutexes, ensuring that only one thread can access a resource at a time. Here are the key differences:

Flexibility: unique_lock allows more control. You can lock, unlock, and even try to lock a mutex manually using its member functions. lock_guard, on the other hand, locks the mutex upon creation and automatically releases it when the lock_guard goes out of scope.

Defer Locking: unique_lock can defer locking until you decide to lock it. This is useful in scenarios where you need to perform operations before acquiring the lock.

Condition Variables: unique_lock works seamlessly with condition variables. In fact, the std::condition_variable requires a unique_lock.*/