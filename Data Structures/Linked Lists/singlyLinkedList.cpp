#include <bits/stdc++.h>
using namespace std;

template <typename T> struct ListNode {
    T data;
    ListNode<T>* next;

    ListNode(T data = T{}, ListNode<T>* next = nullptr): data(data), next(next) {}
};

template <typename T> class LinkedList {
    ListNode<T>* head;
    void insertAfterNode(ListNode<T>* node, T data);
    void deleteAfterNode(ListNode<T>* node);

    public:
    LinkedList(): head(nullptr) {}
    void insertAtBeginning(T data);
    void insertAtEnd(T data);
    void deleteAtBeginning();
    void deleteAtEnd();
    unsigned int countNodes() const;
    inline bool isEmpty() const;
    void display() const;
};

template <typename T> void LinkedList<T>::insertAfterNode(ListNode<T>* node, T data) {
    ListNode<T>* newNode = new ListNode<T>(data, node -> next);
    node -> next = newNode;
}

template <typename T> void LinkedList<T>::deleteAfterNode(ListNode<T>* node) {
    ListNode<T>* temp = node -> next;
    node -> next = node -> next -> next;
    delete temp;
}

template <typename T> void LinkedList<T>::insertAtBeginning(T data) {
    ListNode<T>* newNode = new ListNode<T>(data, head);
    head = newNode;
}

template <typename T> void LinkedList<T>::insertAtEnd(T data) {
    if (isEmpty()) {
        insertAtBeginning(data);
        return;
    }
    
    ListNode<T>* tail = head;
    while (tail -> next != nullptr) tail = tail -> next;
    insertAfterNode(tail, data);
}

template <typename T> void LinkedList<T>::deleteAtBeginning() {
    if (isEmpty()) {
        cout << "List Underflow." << endl;
        return;
    }

    ListNode<T>* temp = head;
    head = head -> next;
    delete temp;
}

template <typename T> void LinkedList<T>::deleteAtEnd() {
    if (isEmpty()) {
        cout << "List Underflow." << endl;
        return;
    }

    if (head -> next == nullptr) {
        deleteAtBeginning();
        return;
    }

    ListNode<T>* preTail = head;
    while (preTail -> next -> next != nullptr) preTail = preTail -> next;
    deleteAfterNode(preTail);
}

template <typename T> unsigned int LinkedList<T>::countNodes() const {
    unsigned int count = 0;
    for (ListNode<T>* node = head; node != nullptr; node = node -> next, count++);
    return count;
}

template <typename T> inline bool LinkedList<T>::isEmpty() const { return head == nullptr; }

template <typename T> void LinkedList<T>::display() const {
    if (isEmpty()) {
        cout << "List Underflow." << endl;
        return;
    }

    cout << "[";
    for (ListNode<T>* node = head; node != nullptr; node = node -> next)
        cout << node -> data << ", ";
    cout << "\b\b]" << endl;
}