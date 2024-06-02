#include <bits/stdc++.h>
using namespace std;

template <typename T> struct ListNode {
    T data;
    ListNode<T>* next;

    ListNode(T data = T{}, ListNode<T>* next = nullptr): data(data), next(next) {}
};

template <typename T> class PriorityQueue {
    ListNode<T>* head;
    bool rev;

    public:
    PriorityQueue(bool rev = false): head(nullptr), rev(rev) {}
    void enqueue(T);
    T dequeue();
    T peek() const;
    unsigned int size() const;
    inline bool isEmpty() const;
    void display() const;
};

template <typename T> void PriorityQueue<T>::enqueue(T data) {
    ListNode<T>* newNode = new ListNode<T>(data);
    if (isEmpty()) {
        head = newNode;
        return;
    }

    if ((!rev && head -> data < data) || (rev && head -> data > data)) {
        newNode -> next = head;
        head = newNode;
    } else {
        ListNode<T>* node = head;
        while (node -> next != nullptr && ((!rev && node -> next -> data > data) || (rev && node -> next -> data < data)))
            node = node -> next;
        newNode -> next = node -> next;
        node -> next = newNode;
    }
}

template <typename T> T PriorityQueue<T>::dequeue() {
    if (isEmpty()) {
        cerr << "Queue Underflow." << endl;
        return T{};
    }

    T data = head -> data;
    
    ListNode<T> *temp = head;
    head = head -> next;
    delete temp;

    return data;
}

template <typename T> T PriorityQueue<T>::peek() const {
    if (!isEmpty())
        return head -> data;
    
    cerr << "Queue Underflow." << endl;
    return T{};
}

template <typename T> unsigned int PriorityQueue<T>::size() const { 
    unsigned int count = 0;
    for (ListNode<T>* node = head; node != nullptr; node = node -> next, count++);
    return count;
}

template <typename T> inline bool PriorityQueue<T>::isEmpty() const { return head == nullptr; }

template <typename T> void PriorityQueue<T>::display() const {
    if (isEmpty()) {
        cerr << "Queue Underflow." << endl;
        return;
    }

    cout << "[";
    for (ListNode<T>* node = head; node != nullptr; node = node -> next)
        cout << node -> data << ", ";
    cout << "\b\b]" << endl;
}