/*Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.*/
#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX];
bool visited[MAX];
int V, E;

// DFS function to detect cycle
bool dfs(int node, int parent) {
    visited[node] = true;

    for (int i = 0; i < V; i++) {
        if (graph[node][i]) {  // if edge exists
            if (!visited[i]) {
                if (dfs(i, node))
                    return true;
            }
            else if (i != parent) {
                // visited node that is not parent → cycle
                return true;
            }
        }
    }
    return false;
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    // initialize graph
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        for (int j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        // undirected graph
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    // check for cycle in all components
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}