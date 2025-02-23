#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Vertex
{
    T data;
    Vertex(T data = T{}) : data(data) {}
};

template <typename T>
class Graph
{
    vector<Vertex<T> *> vertices;
    vector<list<unsigned int>> adjacencyList;

public:
    void addVertex(T);
    void removeVertex(unsigned int);
    bool exists(T) const;
    void addEdge(unsigned int, unsigned int);
    void removeEdge(unsigned int, unsigned int);
    bool checkEdge(unsigned int, unsigned int) const;
    void depthFirstSearch(unsigned int) const;
    void breadthFirstSearch(unsigned int) const;
    inline bool isEmpty() const;
    void display() const;
};

template <typename T>
void Graph<T>::addVertex(T data)
{
    Vertex<T> *newVertex = new Vertex<T>(data);
    vertices.push_back(newVertex);
    adjacencyList.resize(vertices.size());
}

template <typename T>
void Graph<T>::removeVertex(unsigned int index)
{
    if (index >= vertices.size())
    {
        cerr << "Vertex does not exist." << endl;
        return;
    }

    for (unsigned int i = 0; i < vertices.size(); i++)
        removeEdge(i, index);
    adjacencyList.erase(adjacencyList.begin() + index);

    Vertex<T> *temp = vertices[index];
    vertices.erase(vertices.begin() + index);
    delete temp;
}

template <typename T>
bool Graph<T>::exists(T data) const
{
    for (Vertex<T> *vertex : vertices)
        if (vertex->data == data)
            return true;
    return false;
}

template <typename T>
void Graph<T>::addEdge(unsigned int src, unsigned int dest)
{
    if (!checkEdge(src, dest))
        adjacencyList[src].push_back(dest);
}

template <typename T>
void Graph<T>::removeEdge(unsigned int src, unsigned int dest)
{
    if (!checkEdge(src, dest))
        return;

    for (unsigned int neighbor : adjacencyList[src])
        if (neighbor == dest)
        {
            adjacencyList[src].remove(index);
            return;
        }
}

template <typename T>
bool Graph<T>::checkEdge(unsigned int src, unsigned int dest) const
{
    if (src >= vertices.size() || dest >= vertices.size())
    {
        cerr << "Vertex does not exist." << endl;
        return false;
    }

    for (unsigned int neighbor : adjacencyList[src])
        if (neighbor == dest)
            return true;
    return false;
}

template <typename T>
void Graph<T>::depthFirstSearch(unsigned int src) const
{
    if (src >= vertices.size())
    {
        cerr << "Vertex does not exist." << endl;
        return;
    }

    vector<bool> visited(vertices.size());
    cout << "[";
    stack<unsigned int> s;
    s.push(src);
    visited[src] = true;

    while (!s.empty())
    {
        src = s.top();
        s.pop();
        cout << vertices[src]->data << " -> ";
        for (unsigned int neighbor : adjacencyList[src])
            if (!visited[neighbor])
            {
                s.push(neighbor);
                visited[neighbor] = true;
            }
    }
    cout << "]" << endl;
}

template <typename T>
void Graph<T>::breadthFirstSearch(unsigned int src) const
{
    if (src >= vertices.size())
    {
        cerr << "Vertex does not exist." << endl;
        return;
    }

    vector<bool> visited(vertices.size());
    cout << "[";

    queue<unsigned int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty())
    {
        src = q.front();
        q.pop();
        cout << vertices[src]->data << " -> ";
        for (unsigned int neighbor : adjacencyList[src])
            if (!visited[neighbor])
            {
                q.push(neighbor);
                visited[neighbor] = true;
            }
    }
    cout << "]" << endl;
}

template <typename T>
inline bool Graph<T>::isEmpty() const { return !vertices.size(); }

template <typename T>
void Graph<T>::display() const
{
    if (isEmpty())
    {
        cerr << "Graph is empty." << endl;
        return;
    }

    for (int i = 0; i < vertices.size(); i++)
    {
        cout << vertices[i]->data << " -> ";
        for (unsigned int neighbor : adjacencyList[i])
            cout << vertices[neighbor]->data << " -> ";
        cout << endl;
    }
}