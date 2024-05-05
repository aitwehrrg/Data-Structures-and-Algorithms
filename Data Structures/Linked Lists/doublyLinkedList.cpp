#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int data;
    ListNode* prev;
    ListNode* next;

    ListNode(int data = 0, ListNode* prev = nullptr, ListNode* next = nullptr): data(data), prev(prev), next(next) {}
};

void insertAtBeginning(ListNode** head, int data) {
    ListNode* newNode = new ListNode(data, nullptr, *head);
    *head = newNode;
}

void insertAfterNode(ListNode* node, int data) {
    ListNode* newNode = new ListNode(data, node, node -> next);
    node -> next = newNode;
    if (newNode -> next != nullptr) newNode -> next -> prev = newNode;
}

void insertBeforeNode(ListNode* node, int data) {
    ListNode* newNode = new ListNode(data, node -> prev, node);
    node -> prev = newNode;
    if (newNode -> prev != nullptr) newNode -> prev -> next = newNode;
}

void insertAtEnd(ListNode* head, int data) {
    ListNode* tail = head;
    while (tail -> next != nullptr) tail = tail -> next;

    insertAfterNode(tail, data);
}

void deleteAtBeginning(ListNode** head) {
    if (*head == nullptr) {
        cout << "List Underflow." << endl;
        return;
    }

    ListNode* temp = *head;
    if (temp -> next != nullptr) temp -> next -> prev = temp -> prev;
    *head = (*head) -> next;
    delete temp;
}

void deleteAfterNode(ListNode* node) {
    if (node == nullptr) {
        cout << "List Underflow." << endl;
        return;
    }

    ListNode* temp = node -> next;
    if (temp -> next != nullptr) temp -> next -> prev = node;
    node -> next = temp -> next;
    delete temp;
}

void deleteBeforeNode(ListNode* node) {
    if (node == nullptr) {
        cout << "List Underflow." << endl;
        return;
    }

    ListNode* temp = node -> prev;
    if (temp -> prev != nullptr) temp -> prev -> next = node;
    node -> prev = temp -> prev;
    delete temp;
}

void deleteAtEnd(ListNode* head) {
    if (head == nullptr) {
        cout << "List Underflow." << endl;
        return;
    }

    ListNode* preTail = head;
    while (preTail -> next -> next != nullptr) preTail = preTail -> next;
    deleteAfterNode(preTail);
}

unsigned int countNodes(ListNode* head) {
    unsigned int count = 0;
    for (ListNode* node = head; node != nullptr; node = node -> next, count++);
    return count;
}

void display(ListNode* head) {
    if (head == nullptr) {
        cout << "List Underflow." << endl;
        return;
    }

    cout << "[";
    for (ListNode* node = head; node != nullptr; node = node -> next)
        cout << node -> data << ", ";
    cout << "\b\b]" << endl;
}