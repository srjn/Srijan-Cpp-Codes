#include <iostream>
#include <chrono>
using namespace std;

int main() {
    auto start = chrono::high_resolution_clock::now();
    
    // Some operations
    for (int i = 0; i < 1000; ++i) {
        // dummy operation
    }
    
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    
    cout << "Duration: " << duration.count() << " seconds" << endl;
    return 0;
}
