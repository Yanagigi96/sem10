#include <iostream>
#include <vector>
using namespace std;

bool enigma(const vector<vector<double>>& A) {
    int n = A.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i][j] != A[j][i]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n = 3;
    vector<vector<double>> mat = {{1, 2, 3}, {2, 4, 5}, {3, 5, 6}};
    cout << "Симметрична? " << (enigma(mat) ? "Да" : "Нет") << endl;
    return 0;
}