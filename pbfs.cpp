#include <iostream>
#include <vector>
#include <queue>
#include <omp.h>

#define MAX_THREADS 4

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void parallelBFS(int startNode) {
    queue<int> q;
    int level = 0;
    
    q.push(startNode);
    visited[startNode] = true;
    
    while (!q.empty()) {
        int qSize = q.size();
        
        #pragma omp parallel for num_threads(MAX_THREADS)
        for (int i = 0; i < qSize; ++i) {
            int node = q.front();
            q.pop();
            
            // Process node here...
            cout << "Node: " << node << ", Level: " << level << endl;
            
            // Enqueue unvisited neighbors
            for (int neighbor : graph[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        
        level++;
    }
}

int main() {
    int numNodes, numEdges;
    cout << "Enter the number of nodes and edges: ";
    cin >> numNodes >> numEdges;
    
    // Initialize graph and visited array
    graph.resize(100);
    visited.resize(100, false);
    
    // Build the graph
    cout << "Enter the edges: " << endl;
    for (int i = 0; i < numEdges; ++i) {
        int u, v;
        cin >> u >> v;
        
        // Add edge (undirected graph)
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    int startNode;
    cout << "Enter the starting node: ";
    cin >> startNode;
    
    // Perform parallel BFS
    parallelBFS(startNode);
    
    return 0;
}
