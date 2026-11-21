#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

void multiply_basic(const vector<vector<double>>& A,
                    const vector<vector<double>>& B,
                    vector<vector<double>>& C,
                    int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0.0;
            for (int k = 0; k < n; k++) {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }
}

void multiply_improved(const vector<vector<double>>& A,
                       const vector<vector<double>>& B,
                       vector<vector<double>>& C,
                       int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double sum = 0.0;
            for (int k = 0; k < n; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
}

void printMatrix(const vector<vector<double>>& M) {
    for (const auto& row : M) {
        for (double v : row) cout << v << " ";
        cout << endl;
    }
}

int main() {
    int n = 3;
    vector<vector<double>> A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<double>> B = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    vector<vector<double>> C1(n, vector<double>(n, 0.0));
    vector<vector<double>> C2(n, vector<double>(n, 0.0));

    auto t1 = chrono::high_resolution_clock::now();
    multiply_basic(A, B, C1, n);
    auto t2 = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> dt1 = t2 - t1;

    auto t3 = chrono::high_resolution_clock::now();
    multiply_improved(A, B, C2, n);
    auto t4 = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> dt2 = t4 - t3;

    cout << "Неулучшенный:" << endl;
    printMatrix(C1);
    cout << "Время: " << dt1.count() << " мс" << endl << endl;

    cout << "Улучшенный:" << endl;
    printMatrix(C2);
    cout << "Время: " << dt2.count() << " мс" << endl << endl;

    bool same = true;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (C1[i][j] != C2[i][j]) same = false;

    cout << "Результаты совпадают: " << (same ? "Да" : "Нет") << endl;
    return 0;
}