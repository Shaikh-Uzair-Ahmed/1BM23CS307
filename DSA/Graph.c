#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100



void addEdge(int adj[MAX][MAX], int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1; // Undirected graph
}

void bfs(int adj[MAX][MAX], int V, int s,bool visited[MAX]) {
// Create a queue for BFS
    int q[MAX], front = 0, rear = 0;
// Mark the source node as visited and enqueue it
    visited[s] = true;
    q[rear++] = s;
    while (front < rear) { // Iterate over the queue
    // Dequeue a vertex and print it
    int curr = q[front++];
    printf("%d ", curr);

// Get all adjacent vertices of the dequeued vertex
// If an adjacent has not been visited, mark it visited and enqueue it
    for (int i = 0; i < V; i++) {
        if (adj[curr][i] == 1 && !visited[i]) {
            visited[i] = true;
            q[rear++] = i;
            }
        }
    }
}

// Function to perform DFS using recursion

void dfs(int adj[MAX][MAX], int V, int s,bool visited[MAX]) {
    // Mark the current node as visited
    visited[s] = true;
    // Print the current node
    printf("%d ", s);
    // Recur for all the vertices adjacent to the current node
    for (int i = 0; i < V; i++) {
    // If the vertex is adjacent and not visited, recurse on it
        if (adj[s][i] == 1 && !visited[i]) {
        dfs(adj, V, i, visited);
        }
    }
}

int main() {
    int V = 5;
// Adjacency matrix representation of the
    int adj[MAX][MAX] = {0};
    bool visited1[MAX] = {false};
    bool visited2[MAX] = {false};
// Add edges to the graph
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 4);
    printf("BFS starting from 0:\n");
    bfs(adj, V, 0,visited1);
    printf("\nDFS starting from 0:\n");
    dfs(adj, V, 0,visited2);
    return 0;

}