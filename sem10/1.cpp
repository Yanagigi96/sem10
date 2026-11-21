#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <limits>
using namespace std;

void insertAtBottom(stack<int>& s, int item) {
    if (s.empty()) {
        s.push(item);
        return;
    }
    int top = s.top();
    s.pop();
    insertAtBottom(s, item);
    s.push(top);
}

void reverseStack(stack<int>& s) {
    if (s.empty()) return;
    int top = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s, top);
}

void printStack(stack<int> s, const string& label) {
    cout << label;
    if (s.empty()) {
        cout << "(пусто)";
    }
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;
    int n;

    cout << "Сколько элементов в стеке? ";
    while (!(cin >> n) || n < 0) {
        cout << "Ошибка! Введите неотрицательное целое число: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

  
    if (n > 0) {
        cout << "Введите " << n << " целых чисел через пробел: ";
        for (int i = 0; i < n; ++i) {
            int x;
            while (!(cin >> x)) {
                cout << "Ошибка! Введите целое число: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            s.push(x);  
        }
    }

    printStack(s, "Исходный стек (сверху вниз): ");
    reverseStack(s);
    printStack(s, "Перевёрнутый стек:          ");

    return 0;
}