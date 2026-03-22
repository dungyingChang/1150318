#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int> > adj;

    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (int i = 0; i < adj[v].size(); i++) {
            int next = adj[v][i];
            if (!visited[next]) {
                DFSUtil(next, visited);
            }
        }
    }

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    void displayGraph() {
        cout << "\n===== Graph Adjacency List =====" << endl;
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            for (int j = 0; j < adj[i].size(); j++) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }

    void DFS(int start) {
        if (start < 0 || start >= V) {
            cout << "DFS 起始頂點錯誤！" << endl;
            return;
        }

        vector<bool> visited(V, false);

        cout << "\nDFS Traversal: ";
        DFSUtil(start, visited);
        cout << endl;
        cout << "Time Complexity of DFS: O(V + E)" << endl;
    }

    void BFS(int start) {
        if (start < 0 || start >= V) {
            cout << "BFS 起始頂點錯誤！" << endl;
            return;
        }

        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "\nBFS Traversal: ";

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            cout << current << " ";

            for (int i = 0; i < adj[current].size(); i++) {
                int next = adj[current][i];
                if (!visited[next]) {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }

        cout << endl;
        cout << "Time Complexity of BFS: O(V + E)" << endl;
    }
};

int main() {
    int vertices, edges;
    int u, v;
    int start;

    cout << "===== Assignment 5: DFS vs BFS =====" << endl;
    cout << "Enter number of vertices: ";
    cin >> vertices;

    if (vertices <= 0) {
        cout << "頂點數量必須大於 0！" << endl;
        return 0;
    }

    Graph g(vertices);

    cout << "Enter number of edges: ";
    cin >> edges;

    if (edges < 0) {
        cout << "邊的數量不能小於 0！" << endl;
        return 0;
    }

    cout << "\nEnter each edge (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        cout << "Edge " << i + 1 << ": ";
        cin >> u >> v;

        if (u < 0 || u >= vertices || v < 0 || v >= vertices) {
            cout << "輸入錯誤！頂點編號必須在 0 到 " << vertices - 1 << " 之間。" << endl;
            i--;
            continue;
        }

        g.addEdge(u, v);
    }

    g.displayGraph();

    cout << "\nEnter starting vertex for DFS and BFS: ";
    cin >> start;

    g.DFS(start);
    g.BFS(start);

    return 0;
}
