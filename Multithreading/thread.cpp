#include <bits/stdc++.h>
#include<thread>
#include<chrono>
using namespace std;
using namespace std::chrono;

void print(){
    cout<<"thread"<<endl;
    this_thread::sleep_for(seconds(2));
    cout<<"thread t1 executed successfully"<<endl;
}

void sum(int a, int b){
    cout<<a + b<<endl;
    this_thread::sleep_for(seconds(4));
    cout<<"thread t2 executed successfully"<<endl;
}

void sub(int a, int b){
    cout<<b - a<<endl;
    this_thread::sleep_for(seconds(2));
    cout<<"thread t3 executed successfully"<<endl;
}
//main is also a thread
int main(){
    auto start1=high_resolution_clock::now();

    print();//first this will execute
    sum(1000, 10);//2nd this will execute
    sub(10, 1000);//3rd this will execute

    auto end1=high_resolution_clock::now();

    duration<double> diff1=end1-start1;

    auto start2=high_resolution_clock::now();

    thread t1(print);
    t1.join();//wait(main thread) for thread t1 to finish
    thread t2(sum, 1000, 10);
    thread t3(sub, 10, 1000);

    if(t1.joinable())//check if joinable
    t1.join();//wait(main thread) for thread t1 to finish

    t2.detach();//will detach thread t2 from main thread

    if(t2.joinable())
    t2.detach();

    t3.join();//wait(main thread) for thread t3 to finish

    auto end2=high_resolution_clock::now();

    duration<double> diff2=end2-start2;

    cout<<"time taken 1 :"<<diff1.count()*1000<<" milli-seconds"<<endl;
    cout<<"time taken 2 :"<<diff2.count()*1000<<" milli-seconds"<<endl;

    cout<<"main thread is completed"<<endl;
    return 0;
}
/*In this example:

t1, t2, and t3 are all separate threads.

Each thread starts its task when created.

t1.join() makes the main thread wait until t1 finishes.

t2.join() makes the main thread wait until t2 finishes.

t3.join() makes the main thread wait until t3 finishes.

Without these join() calls, the main thread might finish and terminate the program before the threads complete their tasks.
It’s like telling the main thread, "Hold on, wait until these threads are done before you move on."*/