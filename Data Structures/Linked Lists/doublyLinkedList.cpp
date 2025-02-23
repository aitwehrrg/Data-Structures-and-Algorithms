#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct ListNode
{
    T data;
    ListNode<T> *prev;
    ListNode<T> *next;

    ListNode(T data = T{}, ListNode<T> *prev = nullptr, ListNode<T> *next = nullptr) : data(data), prev(prev), next(next) {}
};

template <typename T>
class LinkedList
{
    ListNode<T> *head;
    void insertAfterNode(ListNode<T> *node, T data);
    void insertBeforeNode(ListNode<T> *node, T data);
    void deleteAfterNode(ListNode<T> *node);
    void deleteBeforeNode(ListNode<T> *node);

public:
    LinkedList() : head(nullptr) {}
    void insertAtBeginning(T data);
    void insertAtEnd(T data);
    void deleteAtBeginning();
    void deleteAtEnd();
    unsigned int countNodes() const;
    inline bool isEmpty() const;
    void display() const;
};

template <typename T>
void LinkedList<T>::insertAfterNode(ListNode<T> *node, T data)
{
    ListNode<T> *newNode = new ListNode<T>(data, node, node->next);
    node->next = newNode;
    if (newNode->next != nullptr)
        newNode->next->prev = newNode;
}

template <typename T>
void LinkedList<T>::insertBeforeNode(ListNode<T> *node, T data)
{
    ListNode<T> *newNode = new ListNode<T>(data, node->prev, node);
    node->prev = newNode;
    if (newNode->prev != nullptr)
        newNode->prev->next = newNode;
}

template <typename T>
void LinkedList<T>::deleteAfterNode(ListNode<T> *node)
{
    ListNode<T> *temp = node->next;
    if (temp->next != nullptr)
        temp->next->prev = node;
    node->next = temp->next;
    delete temp;
}

template <typename T>
void LinkedList<T>::deleteBeforeNode(ListNode<T> *node)
{
    ListNode<T> *temp = node->prev;
    if (temp->prev != nullptr)
        temp->prev->next = node;
    node->prev = temp->prev;
    delete temp;
}

template <typename T>
void LinkedList<T>::insertAtBeginning(T data)
{
    ListNode<T> *newNode = new ListNode<T>(data, nullptr, head);
    head = newNode;
}

template <typename T>
void LinkedList<T>::insertAtEnd(T data)
{
    if (isEmpty())
    {
        insertAtBeginning(data);
        return;
    }

    ListNode<T> *tail = head;
    while (tail->next != nullptr)
        tail = tail->next;
    insertAfterNode(tail, data);
}

template <typename T>
void LinkedList<T>::deleteAtBeginning()
{
    if (isEmpty())
    {
        cerr << "List Underflow." << endl;
        return;
    }

    ListNode<T> *temp = head;
    if (temp->next != nullptr)
        temp->next->prev = temp->prev;
    head = head->next;
    delete temp;
}

template <typename T>
void LinkedList<T>::deleteAtEnd()
{
    if (isEmpty())
    {
        cerr << "List Underflow." << endl;
        return;
    }

    if (head->next == nullptr)
    {
        deleteAtBeginning();
        return;
    }

    ListNode<T> *preTail = head;
    while (preTail->next->next != nullptr)
        preTail = preTail->next;
    deleteAfterNode(preTail);
}

template <typename T>
unsigned int LinkedList<T>::countNodes() const
{
    unsigned int count = 0;
    for (ListNode<T> *node = head; node != nullptr; node = node->next, count++)
        ;
    return count;
}

template <typename T>
inline bool LinkedList<T>::isEmpty() const { return head == nullptr; }

template <typename T>
void LinkedList<T>::display() const
{
    if (isEmpty())
    {
        cerr << "List Underflow." << endl;
        return;
    }

    cout << "[";
    for (ListNode<T> *node = head; node != nullptr; node = node->next)
        cout << node->data << ", ";
    cout << "\b\b]" << endl;
}