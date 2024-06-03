#include <bits/stdc++.h>
using namespace std;

template <typename T, unsigned int MAX> class PriorityQueue {
    unsigned int front, rear;
    unsigned int sizeVar;
    T queue[MAX];
    inline unsigned int inc(int, int = 1) const;
    bool reverse;
    void insert(T data, unsigned int index);

    public:
    PriorityQueue(bool reverse = false): front(0), rear(MAX - 1), sizeVar(0), reverse(reverse) {};
    bool enqueue(T);
    T dequeue();
    T peek() const;
    inline unsigned int size() const;
    inline bool isEmpty() const;
    inline bool isFull() const;
    void display() const;
};

template <typename T, unsigned int MAX> void PriorityQueue<T, MAX>::insert(T data, unsigned int index) {
    for (int i = sizeVar - 1; i > index; i--)
        queue[inc(front, i)] = queue[inc(front, i - 1)];
    queue[inc(front, index)] = data;
}

template <typename T, unsigned int MAX> inline unsigned int PriorityQueue<T, MAX>::inc(int x, int increment) const { return (x + increment) % MAX; }

template <typename T, unsigned int MAX> bool PriorityQueue<T, MAX>::enqueue(T data) {
    if (isFull()) {
        cerr << "Queue Overflow." << endl;
        return false;
    }
    rear = inc(rear); sizeVar++;

    int i = 0;
    while (i < sizeVar - 1 && ((!reverse && queue[inc(front, i)] > data) || (reverse && queue[inc(front, i)] < data)))
        i = inc(i);
    insert(data, i);
    return false;
}

template <typename T, unsigned int MAX> T PriorityQueue<T, MAX>::dequeue() {
    if (!isEmpty()) {
        front = inc(front); sizeVar--;
        return queue[inc(front, -1)];
    }

    cerr << "Queue Underflow." << endl;
    return T{};
}

template <typename T, unsigned int MAX> T PriorityQueue<T, MAX>::peek() const {
    if (!isEmpty())
        return queue[inc(front)];
    cerr << "Queue Underflow." << endl;
    return T{};
}

template <typename T, unsigned int MAX> inline unsigned int PriorityQueue<T, MAX>::size() const { return sizeVar; }

template <typename T, unsigned int MAX> inline bool PriorityQueue<T, MAX>::isEmpty() const { return !size(); }

template <typename T, unsigned int MAX> inline bool PriorityQueue<T, MAX>::isFull() const { return size() == MAX; }

template <typename T, unsigned int MAX> void PriorityQueue<T, MAX>::display() const {
    if (isEmpty()) {
        cerr << "Queue Underflow." << endl;
        return;
    }

    cout << "[";
    for (int i = 0; i < size(); i++)
        cout << queue[inc(front, i)] << ", ";
    cout << "\b\b]" << endl;
}