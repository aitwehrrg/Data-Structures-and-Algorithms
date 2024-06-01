#include <bits/stdc++.h>
using namespace std;

template <typename T> struct Vertex {
    T data;
    Vertex(T data = T{}): data(data) {}
};

template <typename T> class Graph {
    vector<Vertex<T>*> vertices;
    vector<list<Vertex<T>*>> adjacencyList;
    void dfsHelper(unsigned int, vector<bool>&);
    void bfsHelper(unsigned int, vector<bool>&);

    public:
    void addVertex(Vertex<T>*);
    inline void addEdge(unsigned int, unsigned int);
    inline bool checkEdge(unsigned int, unsigned int) const;
    void dfs(unsigned int);
    void bfs(unsigned int);
    void display() const;
};

template <typename T> void Graph<T>::addVertex(Vertex<T>* vertex) {
    vertices.push_back(vertex);
    adjacencyList.resize(vertices.size());    
}

template <typename T> inline void Graph<T>::addEdge(unsigned int src, unsigned int dest) {
    if (!checkEdge(src, dest))
        adjacencyList[src].push_back(vertices[dest]);    
}

template <typename T> inline bool Graph<T>::checkEdge(unsigned int src, unsigned int dest) const {
    for (Vertex<T>* vertex : adjacencyList[src])
        if (vertex == vertices[dest])
            return true;
    return false;
}

template <typename T> void Graph<T>::dfs(unsigned int src) {
    vector<bool> visited(vertices.size());
    cout << "[";
    dfsHelper(src, visited);
    cout << "null]" << endl;
}

template <typename T> void Graph<T>::dfsHelper(unsigned int src, vector<bool>& visited) {
    if (visited[src]) return;

    visited[src] = true;
    cout << vertices[src] -> data << " -> ";

    for (int i = 0; i < vertices.size(); i++)
        if (checkEdge(src, i))
            dfsHelper(i, visited);
}

template <typename T> void Graph<T>::bfs(unsigned int src) {
    vector<bool> visited(vertices.size());
    cout << "[";
    bfsHelper(src, visited);
    cout << "null]" << endl;
}

template <typename T> void Graph<T>::bfsHelper(unsigned int src, vector<bool>& visited) {
    queue<unsigned int> q;

    q.push(src);
    visited[src] = true;

    while (!q.empty()) {
        src = q.front(); q.pop();
        cout << vertices[src] -> data << " -> ";
        for (int i = 0; i < vertices.size(); i++)
            if (checkEdge(src, i) && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
    }
}

template <typename T> void Graph<T>::display() const {
    for (int i = 0; i < vertices.size(); i++) {
        cout << vertices[i] -> data << " -> ";
        for (Vertex<T>* vertex : adjacencyList[i])
            cout << vertex -> data << " -> ";
        cout << endl;
    }
}