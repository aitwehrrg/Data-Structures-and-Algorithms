#include <bits/stdc++.h>
using namespace std;

template <typename T, unsigned int MAX> class Stack {
    T stack[MAX];
    int top;

    public:
    Stack<T, MAX>(): top(-1) {}
    bool push(T);
    T pop();
    T peek();
    inline unsigned int size();
    inline bool isFull();
    inline bool isEmpty();
    void display();
};

template <typename T, unsigned int MAX> bool Stack<T, MAX>::push(T data) {
    if(isFull()) {
        cerr << "Stack<T, MAX> Overflow." << endl;
        return false;
    }

    stack[++top] = data;
    return true;
}

template <typename T, unsigned int MAX> T Stack<T, MAX>::pop() {
    if (!isEmpty())
        return stack[top--];

    cerr << "Stack Underflow." << endl;
    return T{};
}

template <typename T, unsigned int MAX> T Stack<T, MAX>::peek() {
    if (!isEmpty())
        return stack[top];

    cerr << "Stack Underflow." << endl;
    return T{};
}

template <typename T, unsigned int MAX> inline unsigned int Stack<T, MAX>::size() { return top + 1; }

template <typename T, unsigned int MAX> inline bool Stack<T, MAX>::isFull() { return size() == MAX; }

template <typename T, unsigned int MAX> inline bool Stack<T, MAX>::isEmpty() { return !size(); }

template <typename T, unsigned int MAX> void Stack<T, MAX>::display() {
    if(isEmpty()) {
        cerr << "Stack Underflow." << endl;
        return;
    }

    cout << "[";
    for (int i = top; i > -1; i--)
        cout << stack[i] << ", ";
    cout << "\b\b]" << endl;
}