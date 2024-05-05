#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;

    ListNode(int data = 0, ListNode* next = nullptr): data(data), next(next) {}
};

class Stack {
    ListNode* top;

    public:
    Stack(): head(nullptr), top(nullptr) {}
    void push(int);
    int pop();
    int peek();
    unsigned int size();
    inline bool isEmpty();
    bool contains(int);
    void display();
};

void Stack::push(int data) {
    ListNode* newNode = new ListNode(data, top);
    top = newNode;
}

int Stack::pop() {
    if (isEmpty()) {
        cerr << "Stack Underflow." << endl;
        return -1;
    }

    int data = top -> data;

    ListNode* temp = top;
    top = top -> next;
    delete temp;

    return data;
}

unsigned int Stack::size() {
    unsigned int count = 0;
    for (ListNode* node = top; node != nullptr; node = node -> next, count++);
    return count;
}

int Stack::peek() {
    if (!isEmpty())
        return top -> data;
    cerr << "Stack Underflow." << endl;
    return -1;
}

inline bool Stack::isEmpty() { return top == nullptr; }

bool Stack::contains(int data) {
    for (ListNode* node = top; node != nullptr; node = node -> next)
        if (node -> data == data)
            return true;
    return false;
}

void Stack::display() {
    if (isEmpty()) {
        cerr << "Stack Underflow." << endl;
        return;
    }

    cout << "[";
    for (ListNode* node = top; node != nullptr; node = node -> next)
        cout << node -> data << ", ";
    cout << "\b\b]" << endl;
}
