#include <iostream>
using namespace std;

class Graph {
private:
    int vertex;
    int adj[20][20];
    bool visited[20];

public:
    void input() {
        int edge;
        cout << "Enter number of vertices (max 20): ";
        cin >> vertex;

        for (int i = 0; i < vertex; i++)
            for (int j = 0; j < vertex; j++)
                adj[i][j] = 0;

        cout << "Enter number of edges: ";
        cin >> edge;

        cout << "Enter edges (u v, 0-based indexing):\n";
        for (int i = 0; i < edge; i++) {
            int u, v;
            cin >> u >> v;
            adj[u][v] = 1;
        }
    }

    void display() {
        cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < vertex; i++) {
            for (int j = 0; j < vertex; j++)
                cout << adj[i][j] << " ";
            cout << endl;
        }
    }

    void Recursion(int v) {
        visited[v] = true;
        cout << v << " ";

        for (int i = 0; i < vertex; i++) {
            if (adj[v][i] == 1 && !visited[i])
                Recursion(i);
        }
    }

    void DFS(int start) {
        for (int i = 0; i < vertex; i++) visited[i] = false;
        cout << "\nDFS Traversal: ";
        Recursion(start);
        cout << endl;
    }
};

int main() {
    Graph g;
    g.input();
    g.display();

    int start;
    cout << "\nEnter starting page (0-based index): ";
    cin >> start;

    g.DFS(start);

    return 0;
}


