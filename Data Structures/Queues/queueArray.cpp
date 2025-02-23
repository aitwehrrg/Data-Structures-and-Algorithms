#include <bits/stdc++.h>
using namespace std;

template <typename T, unsigned int MAX>
class Queue
{
    unsigned int front, rear;
    unsigned int sizeVar;
    T queue[MAX];
    inline unsigned int inc(int, int = 1) const;

public:
    Queue() : front(0), rear(MAX - 1), sizeVar(0){};
    bool enqueue(T);
    T dequeue();
    T peek() const;
    inline unsigned int size() const;
    inline bool isEmpty() const;
    inline bool isFull() const;
    void display() const;
};

template <typename T, unsigned int MAX>
inline unsigned int Queue<T, MAX>::inc(int x, int increment) const { return (x + increment) % MAX; }

template <typename T, unsigned int MAX>
bool Queue<T, MAX>::enqueue(T data)
{
    if (isFull())
    {
        cerr << "Queue Overflow." << endl;
        return false;
    }
    rear = inc(rear);
    sizeVar++;
    queue[rear] = data;
    return true;
}

template <typename T, unsigned int MAX>
T Queue<T, MAX>::dequeue()
{
    if (!isEmpty())
    {
        front = inc(front);
        sizeVar--;
        return queue[inc(front, -1)];
    }

    cerr << "Queue Underflow." << endl;
    return T{};
}

template <typename T, unsigned int MAX>
T Queue<T, MAX>::peek() const
{
    if (!isEmpty())
        return queue[inc(front)];
    cerr << "Queue Underflow." << endl;
    return T{};
}

template <typename T, unsigned int MAX>
inline unsigned int Queue<T, MAX>::size() const { return sizeVar; }

template <typename T, unsigned int MAX>
inline bool Queue<T, MAX>::isEmpty() const { return !size(); }

template <typename T, unsigned int MAX>
inline bool Queue<T, MAX>::isFull() const { return size() == MAX; }

template <typename T, unsigned int MAX>
void Queue<T, MAX>::display() const
{
    if (isEmpty())
    {
        cerr << "Queue Underflow." << endl;
        return;
    }

    cout << "[";
    for (int i = 0; i < size(); i++)
        cout << queue[inc(front, i)] << ", ";
    cout << "\b\b]" << endl;
}