#include <bits/stdc++.h>
using namespace std;

template <typename T> struct ListNode {
    T data;
    ListNode<T>* next;

    ListNode<T>(T data = T{}, ListNode<T>* next = nullptr): data(data), next(next) {}
};

template <typename T> class Stack {
    ListNode<T>* top;

    public:
    Stack<T>(): top(nullptr) {}
    void push(T);
    T pop();
    T peek();
    unsigned int size();
    inline bool isEmpty();
    void display();
};

template <typename T> void Stack<T>::push(T data) {
    ListNode<T>* newNode = new ListNode<T>(data, top);
    top = newNode;
}

template <typename T> T Stack<T>::pop() {
    if (isEmpty()) {
        cerr << "Stack<T> Underflow." << endl;
        return T{};
    }

    T data = top -> data;

    ListNode<T>* temp = top;
    top = top -> next;
    delete temp;

    return data;
}

template <typename T> unsigned int Stack<T>::size() {
    unsigned int count = 0;
    for (ListNode<T>* node = top; node != nullptr; node = node -> next, count++);
    return count;
}

template <typename T> T Stack<T>::peek() {
    if (!isEmpty())
        return top -> data;
    cerr << "Stack<T> Underflow." << endl;
    return T{};
}

template <typename T> inline bool Stack<T>::isEmpty() { return top == nullptr; }

template <typename T> void Stack<T>::display() {
    if (isEmpty()) {
        cerr << "Stack<T> Underflow." << endl;
        return;
    }

    cout << "[";
    for (ListNode<T>* node = top; node != nullptr; node = node -> next)
        cout << node -> data << ", ";
    cout << "\b\b]" << endl;
}
