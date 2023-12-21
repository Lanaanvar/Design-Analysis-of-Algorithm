#include <iostream>
#include <climits>
using namespace std;

int minDistance(int dist[], bool sptSet[], int n) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int dist[], int n) {
    cout << "\nVertex \t\t\t Distance from Source" << endl;
    for (int i = 0; i < n; i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;
}

void dijkstra(int **graph, int n, int src) {
    int dist[n];
    bool sptSet[n];

    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) /*n-1 because last vertex is minimised and all other vertices have been relaxed(already minimised)*/ {
        int u = minDistance(dist, sptSet, n);
        sptSet[u] = true;

        for (int v = 0; v < n; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist, n);
}

int main() {

    int n;
    cout << "\nEnter the number of vertices : ";
    cin >> n;
    
    int **graph = new int *[n];
    for (int i = 0; i < n; i++) {
        graph[i] = new int[n];
    }

    cout << "\nEnter the adjacency matrix for the graph (0 for no edge):" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    dijkstra(graph, n, source);

    // Deallocate memory
    for (int i = 0; i < n; i++) {
        delete[] graph[i];
    }
    delete[] graph;

    cout << "\n";
    return 0;
}
