#include <bits/stdc++.h>
using namespace std;

struct Vertex {
    char data;
    Vertex(char data = 0): data(data) {}
};

class Graph {
    vector<Vertex*> vertices;
    vector<list<Vertex*>> adjacencyList;
    void dfsHelper(unsigned int, vector<bool>&);
    void bfsHelper(unsigned int, vector<bool>&);

    public:
    void addVertex(Vertex*);
    inline void addEdge(unsigned int, unsigned int);
    inline bool checkEdge(unsigned int, unsigned int);
    void dfs(unsigned int);
    void bfs(unsigned int);
    void display();
};

void Graph::addVertex(Vertex* vertex) {
    vertices.push_back(vertex);
    adjacencyList.resize(vertices.size());    
}

inline void Graph::addEdge(unsigned int src, unsigned int dest) {
    if (!checkEdge(src, dest))
        adjacencyList[src].push_back(vertices[dest]);    
}

inline bool Graph::checkEdge(unsigned int src, unsigned int dest) {
    for (Vertex* vertex : adjacencyList[src])
        if (vertex == vertices[dest])
            return true;
    return false;
}

void Graph::dfs(unsigned int src) {
    vector<bool> visited(vertices.size());
    cout << "[";
    dfsHelper(src, visited);
    cout << "null]" << endl;
}

void Graph::dfsHelper(unsigned int src, vector<bool>& visited) {
    if (visited[src]) return;

    visited[src] = true;
    cout << vertices[src] -> data << " -> ";

    for (int i = 0; i < vertices.size(); i++)
        if (checkEdge(src, i))
            dfsHelper(i, visited);
}

void Graph::bfs(unsigned int src) {
    vector<bool> visited(vertices.size());
    cout << "[";
    bfsHelper(src, visited);
    cout << "null]" << endl;
}

void Graph::bfsHelper(unsigned int src, vector<bool>& visited) {
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

void Graph::display() {
    for (int i = 0; i < vertices.size(); i++) {
        cout << vertices[i] -> data << " -> ";
        for (Vertex* vertex : adjacencyList[i])
            cout << vertex -> data << " -> ";
        cout << endl;
    }
}