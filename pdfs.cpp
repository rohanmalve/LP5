#include <iostream>
#include <vector>
#include <stack>
#include <omp.h>

#define MAX_THREADS 4

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void parallelDFS(int startNode) {
    stack<int> s;
    s.push(startNode);
    
    while (!s.empty()) {
        int node = s.top();
        s.pop();
        
        if (!visited[node]) {
            visited[node] = true;
            
            // Process node here...
            cout << "Node: " << node << endl;
            
            // Parallelize the exploration of neighbors
            #pragma omp parallel for num_threads(MAX_THREADS)
            for (int neighbor : graph[node]) {
                if (!visited[neighbor]) {
                    #pragma omp critical
                    {
                        s.push(neighbor);
                    }
                }
            }
        }
    }
}

int main() {
    int numNodes, numEdges;
    cout << "Enter the number of nodes and edges: ";
    cin >> numNodes >> numEdges;
    
    // Initialize graph and visited array
    graph.resize(numNodes);
    visited.resize(numNodes, false);
    
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
    
    // Perform parallel DFS
    parallelDFS(startNode);
    
    return 0;
}
