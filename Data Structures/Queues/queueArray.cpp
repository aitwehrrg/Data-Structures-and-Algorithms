#include <bits/stdc++.h>
using namespace std;

#define MAX 5
class Queue {
    int front,rear;
    unsigned int sizeVar;
    int queue[MAX];
    inline unsigned int inc(int, int = 1);

    public:
    Queue(): front(0), rear(-1), sizeVar(0) {};
    bool enqueue(int);
    int dequeue();
    int peek();
    inline unsigned int size();
    inline bool isEmpty();
    inline bool isFull();
    bool contains(int);
    void display();
};

inline unsigned int Queue::inc(int x, int increment) { return (x + increment) % MAX; }

bool Queue::enqueue(int data) {
    if (isFull()) {
        cerr << "Queue Overflow." << endl;
        return false;
    }
    rear = inc(rear); sizeVar++;
    queue[rear] = data;
    return true;
}

int Queue::dequeue() {
    if (!isEmpty()) {
        front = inc(front); sizeVar--;
        return queue[inc(front, -1)];
    }

    cerr << "Queue Underflow." << endl;
    return 0;
}

int Queue::peek() {
    if (!isEmpty())
        return queue[inc(front)];
    cerr << "Queue Underflow." << endl;
    return 0;
}

inline unsigned int Queue::size() { return sizeVar; }

inline bool Queue::isEmpty() { return !size(); }

inline bool Queue::isFull() { return size() == MAX; }

bool Queue::contains(int data) {
    for (int i = 0; i < size(); i++)
        if (queue[inc(front, i)] == data)
            return true;
    return false;
}

void Queue::display() {
    if (isEmpty()) {
        cerr << "Queue Underflow." << endl;
        return;
    }

    cout << "[";
    for (int i = 0; i < size(); i++)
        cout << queue[inc(front, i)] << ", ";
    cout << "\b\b]" << endl;
}