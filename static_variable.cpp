#include <iostream>
using namespace std;

void counter() {
    static int count = 0; // static variable initialization
    count++;
    cout << "Count: " << count << endl;
}

int main() {
    for (int i = 0; i < 5; i++) {
        counter();
    }
    for (int i = 5; i < 10; i++) {
        counter();
    }
    return 0;
}
