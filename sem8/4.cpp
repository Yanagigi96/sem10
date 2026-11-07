#include <iostream>
#include <vector>
using namespace std;

void multiply_improved(const vector<vector<double>>& A,
                       const vector<vector<double>>& B,
                       vector<vector<double>>& C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double sum = 0.0; // Аккумулятор
            for (int k = 0; k < n; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum; // Одна запись в память вместо n
        }
    }
}

int main() {
    int n = 3;
    vector<vector<double>> A = {{1, 2}, {3, 4}};
    vector<vector<double>> B = {{5, 6}, {7, 8}};
    vector<vector<double>> C(n, vector<double>(n, 0.0));
    multiply_improved(A, B, C, 2);
    for (auto row : C) {
        for (auto val : row) cout << val << " ";
        cout << endl;
    }
    return 0;
}