#include <bits/stdc++.h>
using namespace std;

template <typename T> struct ListNode {
    T data;
    ListNode<T>* prev;
    ListNode<T>* next;

    ListNode<T>(T data = T{}, ListNode<T>* prev = nullptr, ListNode<T>* next = nullptr): data(data), prev(prev), next(next) {}
};

template <typename T> void insertAtBeginning(ListNode<T>** head, T data) {
    ListNode<T>* newNode = new ListNode<T>(data, nullptr, *head);
    *head = newNode;
}

template <typename T> void insertAfterNode(ListNode<T>* node, T data) {
    ListNode<T>* newNode = new ListNode<T>(data, node, node -> next);
    node -> next = newNode;
    if (newNode -> next != nullptr) newNode -> next -> prev = newNode;
}

template <typename T> void insertBeforeNode(ListNode<T>* node, T data) {
    ListNode<T>* newNode = new ListNode<T>(data, node -> prev, node);
    node -> prev = newNode;
    if (newNode -> prev != nullptr) newNode -> prev -> next = newNode;
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
    if (temp -> next != nullptr) temp -> next -> prev = temp -> prev;
    *head = (*head) -> next;
    delete temp;
}

template <typename T> void deleteAfterNode(ListNode<T>* node) {
    if (node == nullptr) {
        cout << "List Underflow." << endl;
        return;
    }

    ListNode<T>* temp = node -> next;
    if (temp -> next != nullptr) temp -> next -> prev = node;
    node -> next = temp -> next;
    delete temp;
}

template <typename T> void deleteBeforeNode(ListNode<T>* node) {
    if (node == nullptr) {
        cout << "List Underflow." << endl;
        return;
    }

    ListNode<T>* temp = node -> prev;
    if (temp -> prev != nullptr) temp -> prev -> next = node;
    node -> prev = temp -> prev;
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