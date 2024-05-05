#include <bits/stdc++.h>
using namespace std;

struct Vertex {
    char data;
    Vertex(char data = 0): data(data) {}
};

class Graph {
    vector<Vertex*> vertices;
    vector<vector<bool>> adjacencyMatrix;
    void dfsHelper(unsigned int, vector<bool>&);

    public:
    void addVertex(Vertex*);
    inline void addEdge(unsigned int, unsigned int);
    inline bool checkEdge(unsigned int, unsigned int);
    void dfs(unsigned int);
    // void bfs();
    void display();
};

void Graph::addVertex(Vertex* vertex) {
    vertices.push_back(vertex);
    
    adjacencyMatrix.resize(vertices.size(), vector<bool>(vertices.size(), false));
}

inline void Graph::addEdge(unsigned int src, unsigned int dest) {
    adjacencyMatrix[src][dest] = true;
}

inline bool Graph::checkEdge(unsigned int src, unsigned int dest) {
    return adjacencyMatrix[src][dest];
}

void Graph::dfs(unsigned int src) {
    vector<bool> visited(adjacencyMatrix.size());
    cout << "[";
    dfsHelper(src, visited);
    cout << "null]" << endl;
}

void Graph::dfsHelper(unsigned int src, vector<bool>& visited) {
    if (visited[src]) return;

    visited[src] = true;
    cout << vertices[src] -> data << " -> ";

    for (int i = 0; i < adjacencyMatrix.size(); i++)
        if (checkEdge(src, i))
            dfsHelper(i, visited);
}

void Graph::display() {
    cout << "  ";
    for (Vertex* vertex: vertices)
        cout << vertex -> data << " ";
    cout << endl;

    for (int i = 0; i < adjacencyMatrix.size(); i++) {
        cout << vertices[i] -> data << " ";
        for (int j = 0; j < adjacencyMatrix.size(); j++)
            cout << adjacencyMatrix[i][j] << " ";
        cout << endl;
    }
}