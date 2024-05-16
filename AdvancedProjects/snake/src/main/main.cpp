#include <iostream>
using namespace std;

int read() {
    bool dataIsRead = true;
    int result = 0;
    while (dataIsRead) {
        char c = cin.get();
        if (c == '\n') {
            dataIsRead = false;
        } else {
            result = result * 10 + c - '0';
        }
    }
}
