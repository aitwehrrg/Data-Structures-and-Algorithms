#include <bits/stdc++.h>
using namespace std;

template <typename T> struct ListNode {
    T data;
    ListNode<T>* next;

    ListNode(T data = T{}, ListNode<T>* next = nullptr): data(data), next(next) {}
};

template <typename T> class Stack {
    ListNode<T>* top;

    public:
    Stack(): top(nullptr) {}
    void push(T);
    T pop();
    T peek() const;
    unsigned int size() const;
    inline bool isEmpty() const;
    void display() const;
};

template <typename T> void Stack<T>::push(T data) {
    ListNode<T>* newNode = new ListNode<T>(data, top);
    top = newNode;
}

template <typename T> T Stack<T>::pop() {
    if (isEmpty()) {
        cerr << "Stack Underflow." << endl;
        return T{};
    }

    T data = top -> data;

    ListNode<T>* temp = top;
    top = top -> next;
    delete temp;

    return data;
}

template <typename T> T Stack<T>::peek() const {
    if (!isEmpty())
        return top -> data;
    cerr << "Stack Underflow." << endl;
    return T{};
}

template <typename T> unsigned int Stack<T>::size() const {
    unsigned int count = 0;
    for (ListNode<T>* node = top; node != nullptr; node = node -> next, count++);
    return count;
}

template <typename T> inline bool Stack<T>::isEmpty() const { return top == nullptr; }

template <typename T> void Stack<T>::display() const {
    if (isEmpty()) {
        cerr << "Stack Underflow." << endl;
        return;
    }

    cout << "[";
    for (ListNode<T>* node = top; node != nullptr; node = node -> next)
        cout << node -> data << ", ";
    cout << "\b\b]" << endl;
}