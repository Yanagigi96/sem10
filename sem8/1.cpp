#include <iostream>
using namespace std;

// Исходный алгоритм (O(n))
long long mystery_slow(int n) {
    long long S = 0;
    for (int i = 1; i <= n; i++) {
        S = S + (long long)i * i;
    }
    return S;
}

// Улучшенный алгоритм (O(1))
long long mystery_fast(int n) {
    return (long long)n * (n + 1) * (2LL * n + 1) / 6;
}

int main() {
    int n = 100;
    cout << "Медленный: " << mystery_slow(n) << endl;
    cout << "Быстрый:  " << mystery_fast(n) << endl;
    return 0;
}