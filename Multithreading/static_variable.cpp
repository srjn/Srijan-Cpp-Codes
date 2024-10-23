#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void unsafeIncrement() {
    static int count = 0;
    count++;
    std::cout << "Count: " << count << std::endl;
}

void safeIncrement() {
    static int count = 0;
    mtx.lock();
    count++;
    std::cout << "Safe Count: " << count << std::endl;
    mtx.unlock();
}

int main() {
    std::thread threads[10];
    
    // Unsafe example
    std::cout << "Unsafe Increment:\n";
    for (int i = 0; i < 10; i++) {
        threads[i] = std::thread(unsafeIncrement);
    }
    for (int i = 0; i < 10; i++) {
        threads[i].join();
    }
    
    // Safe example
    std::cout << "Safe Increment:\n";
    for (int i = 0; i < 10; i++) {
        threads[i] = std::thread(safeIncrement);
    }
    for (int i = 0; i < 10; i++) {
        threads[i].join();
    }
    
    return 0;
}
