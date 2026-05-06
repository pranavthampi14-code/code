#include <iostream>
#include <vector>
#include <queue>
#include <iomanip> // for setw
using namespace std;

const int N = 4; // Number of landmarks
string landmarks[N] = {"Admin", "Canteen", "Sports", "Workshop"};

int adjMatrix[N][N];   // Adjacency Matrix
vector<int> adjList[N]; // Adjacency List

bool visitedDFS[N];
bool visitedBFS[N];

// DFS using adjacency matrix       
void DFS(int v) {
    visitedDFS[v] = true;
    cout << landmarks[v] << " -> ";

    for (int i = 0; i < N; i++) {
        if (adjMatrix[v][i] == 1 && !visitedDFS[i]) {
            DFS(i);
        }
    }
}

// BFS using adjacency list
void BFS(int start) {
    queue<int> q;
    visitedBFS[start] = true;
    q.push(start);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << landmarks[curr] << " -> ";

        for (int neighbor : adjList[curr]) {
            if (!visitedBFS[neighbor]) {
                visitedBFS[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    cout << "Enter adjacency matrix for the graph (" << N << "x" << N << "):\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> adjMatrix[i][j];
        }
    }

    // Build adjacency list from adjacency matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (adjMatrix[i][j] == 1) {
                adjList[i].push_back(j);
            }
        }
    }

    cout << "\nAdjacency Matrix Representation:\n";
    cout << setw(12) << " " ;
    for (int j = 0; j < N; j++) {
        cout << setw(10) << landmarks[j];
    }
    cout << "\n";

    for (int i = 0; i < N; i++) {
        cout << setw(12) << landmarks[i];
        for (int j = 0; j < N; j++) {
            cout << setw(10) << adjMatrix[i][j];
        }
        cout << "\n";
    }
    cout << "\n";

    cout << "DFS Traversal (Adjacency Matrix):\n";
    DFS(0); // Start from Admin
    cout << "\n\n";

    cout << "BFS Traversal (Adjacency List):\n";
    BFS(0); // Start from Admin
    cout << "\n";

    return 0;
}
