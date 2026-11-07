#include <iostream>
using namespace std;

int binary_count(int n) {
    int count = 1;
    while (n > 1) {
        count++;
        n = n / 2;
    }
    return count;
}

int main() {
    int n = 13; 
    cout << "Количество разрядов: " << binary_count(n) << endl;
    return 0;
}