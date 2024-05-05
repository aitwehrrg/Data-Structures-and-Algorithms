#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int data;
    ListNode *next;

    ListNode(int data = 0, ListNode* next = nullptr): data(data), next(next) {}
};

class Queue {
    ListNode* front;
    ListNode* rear;

    public:
    Queue(): front(nullptr), rear(nullptr) {}
    void enqueue(int);
    int dequeue();
    int peek();
    unsigned int size();
    inline bool isEmpty();
    bool contains(int);
    void display();
};

void Queue::enqueue(int data) {
    ListNode* newNode = new ListNode(data);
    if (isEmpty())
        front = newNode;
    else
        rear -> next = newNode;
    rear = newNode;
}

int Queue::dequeue() {
    if (isEmpty()) {
        cerr << "Queue Underflow." << endl;
        return -1;
    }

    int data = front -> data;
    
    ListNode *temp = front;
    front = front -> next;
    delete temp;

    if (front == nullptr) rear = nullptr;
    return data;
}

int Queue::peek() {
    if (!isEmpty())
        return front -> data;
    
    cerr << "Queue Underflow." << endl;
    return -1;
}

unsigned int Queue::size() { 
    unsigned int count = 0;
    for (ListNode* node = front; node != nullptr; node = node -> next, count++);
    return count;
}

inline bool Queue::isEmpty() { return front == nullptr; }

bool Queue::contains(int data) {
    for (ListNode* node = front; node != nullptr; node = node -> next)
        if (node -> data == data)
            return true;
    return false;
}

void Queue::display() {
    if (isEmpty()) {
        cerr << "Queue Underflow." << endl;
        return;
    }

    cout << "[";
    for (ListNode* node = front; node != nullptr; node = node -> next)
        cout << node -> data << ", ";
    cout << "\b\b]" << endl;
}
