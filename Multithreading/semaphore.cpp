#include <iostream>
#include <thread>
#include <semaphore.h>

std::counting_semaphore<3> sem(3); // Allows up to 3 threads to access

void task(int id) {
    sem.acquire();
    std::cout << "Thread " << id << " is working." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    sem.release();
}

int main() {
    std::thread threads[5];
    for (int i = 0; i < 5; i++) {
        threads[i] = std::thread(task, i);
    }
    for (int i = 0; i < 5; i++) {
        threads[i].join();
    }
    return 0;
}
