#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;

    ListNode(int data = 0, ListNode* next = nullptr): data(data), next(next) {}
};

void insertAtBeginning(ListNode** head, int data) {
    ListNode* newNode = new ListNode(data, *head);
    *head = newNode;
}


void insertAfterNode(ListNode* node, int data) {
    ListNode* newNode = new ListNode(data, node -> next);
    node -> next = newNode;
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
    *head = (*head) -> next;
    delete temp;
}

void deleteAfterNode(ListNode* node) {
    if (node == nullptr) {
        cout << "List Underflow." << endl;
        return;
    }

    ListNode* temp = node -> next;
    node -> next = node -> next -> next;
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