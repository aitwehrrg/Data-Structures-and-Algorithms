#include <bits/stdc++.h>
using namespace std;

#define MAX 1000
class Stack {
    int stack[MAX];
    int top;

    public:
    Stack(): top(-1) {}
    bool push(int);
    int pop();
    int peek();
    inline unsigned int size();
    inline bool isFull();
    inline bool isEmpty();
    bool contains(int);
    void display();
};

bool Stack::push(int data) {
    if(isFull()) {
        cerr << "Stack Overflow." << endl;
        return false;
    }

    stack[++top] = data;
    return true;
}

int Stack::pop() {
    if (!isEmpty())
        return stack[top--];

    cerr << "Stack Underflow." << endl;
    return -1;
}

int Stack::peek() {
    if (!isEmpty())
        return stack[top];

    cerr << "Stack Underflow." << endl;
    return -1;
}

inline unsigned int Stack::size() { return top + 1; }

inline bool Stack::isFull() { return size() == MAX; }

inline bool Stack::isEmpty() { return !size(); }

bool Stack::contains(int data) {
    for(int i = 0; i < size(); i++)
        if(stack[i] == data)
            return true;
    return false;
}

void Stack::display() {
    if(isEmpty()) {
        cerr << "Stack Underflow." << endl;
        return;
    }

    cout << "[";
    for (int i = top; i > -1; i--)
        cout << stack[i] << ", ";
    cout << "\b\b]" << endl;
}