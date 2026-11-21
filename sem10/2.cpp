#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
class PriorityQueue {
private:
    struct Item {
        T value;
        int key;
    };
    vector<Item> heap;
    bool isMax;

    bool better(int a, int b) const { return isMax ? (a > b) : (a < b); }

    void siftUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (better(heap[i].key, heap[parent].key)) {
                swap(heap[i], heap[parent]);
                i = parent;
            } else break;
        }
    }

    void siftDown(int i) {
        int n = (int)heap.size();
        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int best = i;
            if (left < n && better(heap[left].key, heap[best].key)) best = left;
            if (right < n && better(heap[right].key, heap[best].key)) best = right;
            if (best == i) break;
            swap(heap[i], heap[best]);
            i = best;
        }
    }

public:
    explicit PriorityQueue(bool maxMode = true) : isMax(maxMode) {}

    bool empty() const { return heap.empty(); }
    size_t size() const { return heap.size(); }

    void push(const T& value, int key) {
        heap.push_back({value, key});
        siftUp((int)heap.size() - 1);
    }

    bool pop(T& outValue, int& outKey) {
        if (empty()) return false;
        outValue = heap[0].value;
        outKey   = heap[0].key;
        heap[0] = heap.back();
        heap.pop_back();
        if (!empty()) siftDown(0);
        return true;
    }

    bool top(T& outValue, int& outKey) const {
        if (empty()) return false;
        outValue = heap[0].value;
        outKey   = heap[0].key;
        return true;
    }

    void print() const {
        if (empty()) {
            cout << "  (очередь пуста)\n";
            return;
        }

        vector<Item> sorted = heap;
        for (size_t i = 0; i < sorted.size(); ++i)
            for (size_t j = i + 1; j < sorted.size(); ++j)
                if (better(sorted[j].key, sorted[i].key))
                    swap(sorted[i], sorted[j]);

        cout << "  Содержимое (порядок извлечения, "
             << (isMax ? "max" : "min") << "-ключ):\n";
        for (auto& it : sorted)
            cout << "    ключ = " << it.key << "  ->  значение = " << it.value << "\n";
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

string readString() {
    string s;
    cin >> s;
    return s;
}

int main() {
    cout << "Выберите режим извлечения по ключу:\n";
    cout << "  1. По НАИБОЛЬШЕМУ ключу (max-heap)\n";
    cout << "  2. По НАИМЕНЬШЕМУ ключу (min-heap)\n";
    cout << "Ваш выбор: ";
    int mode = readInt();
    bool isMax = (mode != 2);

    PriorityQueue<string> pq(isMax);
    cout << "Режим: извлечение по "
         << (isMax ? "НАИБОЛЬШЕМУ" : "НАИМЕНЬШЕМУ") << " числовому ключу\n";

    int choice;
    while (true) {
        cout << "\n================ МЕНЮ ================\n";
        cout << "1. Добавить элемент (значение + числовой ключ)\n";
        cout << "2. Извлечь элемент с "
             << (isMax ? "наибольшим" : "наименьшим") << " ключом\n";
        cout << "3. Посмотреть элемент с "
             << (isMax ? "наибольшим" : "наименьшим") << " ключом\n";
        cout << "4. Показать всё содержимое\n";
        cout << "5. Показать размер\n";
        cout << "0. Выход\n";
        cout << "======================================\n";
        cout << "Выберите действие: ";
        
        choice = readInt();

        switch (choice) {
            case 1: {
                cout << "  Значение: ";
                string val = readString();
                cout << "  Числовой ключ: ";
                int key = readInt();
                pq.push(val, key);
                cout << "  ✔ Добавлено: [" << val << "] с ключом " << key << "\n";
                break;
            }
            case 2: {
                string v; int k;
                if (pq.pop(v, k))
                    cout << "  ✔ Извлечён [" << v << "] (ключ = " << k << ")\n";
                else
                    cout << "  В очереди пока нет элементов.\n";
                break;
            }
            case 3: {
                string v; int k;
                if (pq.top(v, k))
                    cout << "  Вершина: [" << v << "] (ключ = " << k << ")\n";
                else
                    cout << "  В очереди пока нет элементов.\n";
                break;
            }
            case 4: pq.print(); break;
            case 5: cout << "  Размер: " << pq.size() << "\n"; break;
            case 0: cout << "Выход.\n"; return 0;
            default: cout << "  Неверный пункт меню.\n";
        }
    }
}