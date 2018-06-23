#include <iostream>

using namespace std;

int killKthBit(int n, int k) {
    n = (n & ~(1<<(k-1))) | (0<<(k-1));
    return n;
}

int main() {
    cout << killKthBit(37,3); // 33
    cout << endl << killKthBit(37,4); // 37
    cout << endl << killKthBit(37,2); // 37
}



