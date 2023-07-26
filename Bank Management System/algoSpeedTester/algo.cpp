#include <iostream>
#include <chrono>

int main(){
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 1000000; ++i) {
      
    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();

    std::cout <<"Time Taken by the line of code: "<<duration<<" microsecond." << std::endl;

    return 0;
}