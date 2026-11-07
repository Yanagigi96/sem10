#include <iostream>
#include <vector>
using namespace std;

double secret(const vector<double>& A) {
    if (A.empty()) return 0.0;
    double minval = A[0];
    double maxval = A[0];
    for (size_t i = 1; i < A.size(); i++) {
        if (A[i] < minval) minval = A[i];
        if (A[i] > maxval) maxval = A[i];
    }
    return maxval - minval;
}

int main() {
    vector<double> arr = {3.5, 1.2, 7.8, -2.0, 5.5};
    cout << "Размах: " << secret(arr) << endl;
    return 0;
}