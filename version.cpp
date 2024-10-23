#include <iostream>

#if __cplusplus >= 201703L
int main() {
    std::cout << "Your compiler supports C++17 or above!" << std::endl;
    return 0;
}
#else
#error "This program requires a C++17 compatible compiler."
#endif

//To Check it supports C++ 20 or above
// #include <iostream>

// #if __cplusplus >= 202002L
// int main() {
//     std::cout << "Your compiler supports C++20 or above!" << std::endl;
//     return 0;
// }
// #else
// #error "This program requires a C++20 compatible compiler."
// #endif
