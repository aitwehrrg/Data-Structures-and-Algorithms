#include <bits/stdc++.h>
using namespace std;

template <typename T> struct ListNode {
    T data;
    ListNode<T>* next;

    ListNode<T>(T data = T{}, ListNode<T><T>* next = nullptr): data(data), next(next) {}
};

template <typename T> class Queue {
    ListNode<T>* front;
    ListNode<T>* rear;

    public:
    Queue<T>(): front(nullptr), rear(nullptr) {}
    void enqueue(T);
    T dequeue();
    T peek();
    unsigned int size();
    inline bool isEmpty();
    void display();
};

template <typename T> void Queue<T>::enqueue(T data) {
    ListNode<T>* newNode = new ListNode<T>(data);
    if (isEmpty())
        front = newNode;
    else
        rear -> next = newNode;
    rear = newNode;
}

template <typename T> T Queue<T>::dequeue() {
    if (isEmpty()) {
        cerr << "Queue Underflow." << endl;
        return T{};
    }

    T data = front -> data;
    
    ListNode<T> *temp = front;
    front = front -> next;
    delete temp;

    if (front == nullptr) {
        rear = nullptr;
    }
    return data;
}

template <typename T> T Queue<T>::peek() {
    if (!isEmpty())
        return front -> data;
    
    cerr << "Queue Underflow." << endl;
    return T{};
}

template <typename T> unsigned int Queue<T>::size() { 
    unsigned int count = 0;
    for (ListNode<T>* node = front; node != nullptr; node = node -> next, count++);
    return count;
}

template <typename T> inline bool Queue<T>::isEmpty() { return front == nullptr; }

template <typename T> void Queue<T>::display() {
    if (isEmpty()) {
        cerr << "Queue Underflow." << endl;
        return;
    }

    cout << "[";
    for (ListNode<T>* node = front; node != nullptr; node = node -> next)
        cout << node -> data << ", ";
    cout << "\b\b]" << endl;
}