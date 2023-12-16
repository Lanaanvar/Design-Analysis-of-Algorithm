#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

const int MAX_VERTICES = 100; // Change the maximum number of vertices as needed

class Graph {
public:
    int vertices;
    int adjacencyList[MAX_VERTICES][MAX_VERTICES];

    Graph(int v) : vertices(v) {
        // Initialize the adjacency list
        for (int i = 0; i < MAX_VERTICES; ++i) {
            for (int j = 0; j < MAX_VERTICES; ++j) {
                adjacencyList[i][j] = 0;
            }
        }
    }

    void addEdge(int v, int w) {
        adjacencyList[v][w] = 1;
        adjacencyList[w][v] = 1;
    }

    void bfs(int start) {
        bool visited[MAX_VERTICES] = {false};
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int current = q.front();
            cout << current << " ";
            q.pop();

            for (int neighbor = 0; neighbor < vertices; ++neighbor) {
                if (adjacencyList[current][neighbor] == 1 && !visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    bool hasPath(int start, int end, bool visited[]) {
        if (start == end) {
            return true;
        }

        visited[start] = true;

        for (int neighbor = 0; neighbor < vertices; ++neighbor) {
            if (adjacencyList[start][neighbor] == 1 && !visited[neighbor]) {
                if (hasPath(neighbor, end, visited)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool hasPath(int start, int end) {
        bool visited[MAX_VERTICES] = {false};
        return hasPath(start, end, visited);
    }
};

int main() {
    // Create a sample graph
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);

    cout << "BFS Traversal: ";
    g.bfs(0);
    cout << endl;

    int startNode = 0;
    int endNode = 6;

    if (g.hasPath(startNode, endNode)) {
        cout << "Path exists from node " << startNode << " to node " << endNode << "." << endl;
    } else {
        cout << "No path exists from node " << startNode << " to node " << endNode << "." << endl;
    }

    return 0;
}
