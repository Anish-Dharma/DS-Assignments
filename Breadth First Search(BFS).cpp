/*Breadth First Search (BFS):
Application:Indexing web pages for search engines.
Example: A web crawler uses BFS to visit web pages systematically, starting from a seed URL and exploring links level by level. Nodes represent web pages. Edges represent hyperlinks. BFS ensures that pages at the same "depth" (distance from the starting page) are visited before moving to deeper levels. Write a program to simulate the indexing of web pages for a search engine using a Breadth-First Search (BFS) algorithm.
*/
#include <iostream>
using namespace std;

class Graph {
private:
    int vertex;
    int adj[20][20];
    bool visited[20];
    int queueArr[20];
    int front, rear;

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

    void BFS(int start) {
        for (int i = 0; i < vertex; i++) visited[i] = false;
        front = rear = -1;
        queueArr[++rear] = start;
        visited[start] = true;

        cout << "\nBFS Traversal: ";
        while (front != rear) {
            int v = queueArr[++front];
            cout << v << " ";
            for (int i = 0; i < vertex; i++) {
                if (adj[v][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    queueArr[++rear] = i;
                }
            }
        }
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

    g.BFS(start);

    return 0;
}
