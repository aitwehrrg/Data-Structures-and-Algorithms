#include <bits/stdc++.h>
using namespace std;

template <typename T> struct Vertex {
    T data;
    Vertex(T data = T{}): data(data) {}
};

template <typename T> class Graph {
    vector<Vertex<T>*> vertices;
    vector<vector<bool>> adjacencyMatrix;
    void dfsHelper(unsigned int, vector<bool>&);

    public:
    void addVertex(T);
    void removeVertex(unsigned int);
    bool exists(T) const;
    inline void addEdge(unsigned int, unsigned int);
    inline void removeEdge(unsigned int, unsigned int);
    inline bool checkEdge(unsigned int, unsigned int) const;
    void depthFirstSearch(unsigned int) const;
    void breadthFirstSearch(unsigned int) const;
    void display() const;
};

template <typename T> void Graph<T>::addVertex(T data) {
    Vertex<T>* newVertex = new Vertex<T>(data);
    vertices.push_back(newVertex);
    for (vector<bool>& row : adjacencyMatrix)
        row.resize(vertices.size(), false);
    adjacencyMatrix.resize(vertices.size(), vector<bool>(vertices.size(), false));
}

template <typename T> void Graph<T>::removeVertex(unsigned int index) {
    if (index >= vertices.size()) {
        cout << "Vertex does not exist." << endl;
        return;
    }

    adjacencyMatrix.erase(adjacencyMatrix.begin() + index);
    for (vector<bool>& row : adjacencyMatrix)
        row.erase(row.begin() + index);

    vertices.erase(vertices.begin() + index);
}

template <typename T> bool Graph<T>::exists(T data) const {
    for (int i = 0; i < vertices.size(); i++)
        if (vertices[i] -> data == data)
            return true;
    return false;
}

template <typename T> inline void Graph<T>::addEdge(unsigned int src, unsigned int dest) {
    if (src < vertices.size() && dest < vertices.size())
        adjacencyMatrix[src][dest] = true;
}

template <typename T> inline void Graph<T>::removeEdge(unsigned int src, unsigned int dest) {
    if (src < vertices.size() && dest < vertices.size())
        adjacencyMatrix[src][dest] = false;
}

template <typename T> inline bool Graph<T>::checkEdge(unsigned int src, unsigned int dest) const { return src < vertices.size() && dest < vertices.size() && adjacencyMatrix[src][dest]; }

template <typename T> void Graph<T>::depthFirstSearch(unsigned int src) const {
    if (src >= vertices.size()) {
        cout << "Vertex does not exist." << endl;
        return;
    }

    vector<bool> visited(vertices.size());
    cout << "[";
    dfsHelper(src, visited);
    cout << "]" << endl;
}

template <typename T> void Graph<T>::dfsHelper(unsigned int src, vector<bool>& visited) {
    if (visited[src]) return;

    visited[src] = true;
    cout << vertices[src] -> data << " -> ";

    for (int i = 0; i < vertices.size(); i++)
        if (checkEdge(src, i))
            dfsHelper(i, visited);
}

template <typename T> void Graph<T>::breadthFirstSearch(unsigned int src) const {
    if (src >= vertices.size()) {
        cout << "Vertex does not exist." << endl;
        return;
    }

    vector<bool> visited(vertices.size());
    cout << "[";

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
    cout << "]" << endl;
}

template <typename T> void Graph<T>::display() const {
    if (vertices.size() == 0) {
        cout << "Graph is empty." << endl;
        return;
    }

    cout << "  ";
    for (Vertex<T>* vertex: vertices)
        cout << vertex -> data << " ";
    cout << endl;

    for (int i = 0; i < vertices.size(); i++) {
        cout << vertices[i] -> data << " ";
        for (int j = 0; j < vertices.size(); j++)
            cout << adjacencyMatrix[i][j] << " ";
        cout << endl;
    }
}
