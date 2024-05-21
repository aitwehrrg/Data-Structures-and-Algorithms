#include <bits/stdc++.h>
using namespace std;

template <typename T> struct ListNode {
    T data;
    ListNode<T>* next;

    ListNode<T>(T data = T{}, ListNode<T>* next = nullptr): data(data), next(next) {}
};

template <typename T> void insertAtBeginning(ListNode<T>** head, T data) {
    ListNode<T>* newNode = new ListNode<T>(data, *head);
    *head = newNode;
}


template <typename T> void insertAfterNode(ListNode<T>* node, T data) {
    ListNode<T>* newNode = new ListNode<T>(data, node -> next);
    node -> next = newNode;
}

template <typename T> void insertAtEnd(ListNode<T>* head, T data) {
    ListNode<T>* tail = head;
    while (tail -> next != nullptr) tail = tail -> next;

    insertAfterNode(tail, data);
}

template <typename T> void deleteAtBeginning(ListNode<T>** head) {
    if (*head == nullptr) {
        cout << "List Underflow." << endl;
        return;
    }

    ListNode<T>* temp = *head;
    *head = (*head) -> next;
    delete temp;
}

template <typename T> void deleteAfterNode(ListNode<T>* node) {
    if (node == nullptr) {
        cout << "List Underflow." << endl;
        return;
    }

    ListNode<T>* temp = node -> next;
    node -> next = node -> next -> next;
    delete temp;
}

template <typename T> void deleteAtEnd(ListNode<T>* head) {
    if (head == nullptr) {
        cout << "List Underflow." << endl;
        return;
    }

    ListNode<T>* preTail = head;
    while (preTail -> next -> next != nullptr) preTail = preTail -> next;

    deleteAfterNode(preTail);
}

template <typename T> unsigned int countNodes(ListNode<T>* head) {
    unsigned int count = 0;
    for (ListNode<T>* node = head; node != nullptr; node = node -> next, count++);
    return count;
}

template <typename T> void display(ListNode<T>* head) {
    if (head == nullptr) {
        cout << "List Underflow." << endl;
        return;
    }

    cout << "[";
    for (ListNode<T>* node = head; node != nullptr; node = node -> next)
        cout << node -> data << ", ";
    cout << "\b\b]" << endl;
}