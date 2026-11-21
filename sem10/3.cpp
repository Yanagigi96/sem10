#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Deque {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(const T& d) : data(d), prev(nullptr), next(nullptr) {}
    };

    Node* head = nullptr;
    Node* tail = nullptr;
    size_t count = 0;

public:
    ~Deque() { clear(); }

    bool empty() const { return count == 0; }
    size_t size() const { return count; }

    void push_front(const T& value) {
        Node* n = new Node(value);
        if (empty()) { head = tail = n; }
        else {
            n->next = head;
            head->prev = n;
            head = n;
        }
        ++count;
    }

    void push_back(const T& value) {
        Node* n = new Node(value);
        if (empty()) { head = tail = n; }
        else {
            n->prev = tail;
            tail->next = n;
            tail = n;
        }
        ++count;
    }

    bool pop_front(T& out) {
        if (empty()) return false;
        out = head->data;
        Node* n = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete n;
        --count;
        return true;
    }

    bool pop_back(T& out) {
        if (empty()) return false;
        out = tail->data;
        Node* n = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete n;
        --count;
        return true;
    }

    bool front(T& out) const {
        if (empty()) return false;
        out = head->data;
        return true;
    }

    bool back(T& out) const {
        if (empty()) return false;
        out = tail->data;
        return true;
    }

    void clear() {
        while (head) {
            Node* n = head;
            head = head->next;
            delete n;
        }
        tail = nullptr;
        count = 0;
    }

    void print() const {
        if (empty()) {
            cout << "  (дек пуст)\n";
            return;
        }
        cout << "  Дек: ";
        Node* cur = head;
        while (cur) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << "\n";
    }
};

int readInt() {
    int x;
    while (!(cin >> x)) {
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return x;
}

int main() {
    Deque<int> dq;
    int choice;

    while (true) {
        cout << "\n============== МЕНЮ (ДЕК) ==============\n";
        cout << "1. Добавить в начало\n";
        cout << "2. Добавить в конец\n";
        cout << "3. Удалить из начала\n";
        cout << "4. Удалить с конца\n";
        cout << "5. Показать начало\n";
        cout << "6. Показать конец\n";
        cout << "7. Показать весь дек\n";
        cout << "8. Показать размер\n";
        cout << "0. Выход\n";
        cout << "========================================\n";
        cout << "Выберите действие: ";

        choice = readInt();

        switch (choice) {
            case 1: {
                cout << "  Значение: ";
                int x = readInt();
                dq.push_front(x);
                cout << "  ✔ Добавлено в начало: " << x << "\n";
                break;
            }
            case 2: {
                cout << "  Значение: ";
                int x = readInt();
                dq.push_back(x);
                cout << "  ✔ Добавлено в конец: " << x << "\n";
                break;
            }
            case 3: {
                int v;
                if (dq.pop_front(v)) cout << "  ✔ Удалён из начала: " << v << "\n";
                else cout << "  Дек пока пуст.\n";
                break;
            }
            case 4: {
                int v;
                if (dq.pop_back(v)) cout << "  ✔ Удалён с конца: " << v << "\n";
                else cout << "  Дек пока пуст.\n";
                break;
            }
            case 5: {
                int v;
                if (dq.front(v)) cout << "  Начало: " << v << "\n";
                else cout << "  Дек пока пуст.\n";
                break;
            }
            case 6: {
                int v;
                if (dq.back(v)) cout << "  Конец: " << v << "\n";
                else cout << "  Дек пока пуст.\n";
                break;
            }
            case 7: dq.print(); break;
            case 8: cout << "  Размер: " << dq.size() << "\n"; break;
            case 0: cout << "Выход.\n"; return 0;
            default: cout << "  Неверный пункт меню.\n";
        }
    }
}