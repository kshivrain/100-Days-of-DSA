/*Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).*/
#include <stdio.h>

#define MAX 100

int queue[MAX], front = 0, rear = -1;

// Enqueue
void enqueue(int x) {
    queue[++rear] = x;
}

// Dequeue
int dequeue() {
    return queue[front++];
}

// Check if queue is empty
int isEmpty() {
    return front > rear;
}

int main() {
    int n, e;
    int adj[MAX][MAX] = {0};
    int indegree[MAX] = {0};
    int u, v, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    // Input edges
    printf("Enter edges (u v) where u -> v:\n");
    for(i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    // Calculate indegree
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    // Add vertices with indegree 0 to queue
    for(i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            enqueue(i);
        }
    }

    printf("Topological Order: ");

    int count = 0;

    while(!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);
        count++;

        // Reduce indegree of adjacent nodes
        for(i = 0; i < n; i++) {
            if(adj[node][i] == 1) {
                indegree[i]--;
                if(indegree[i] == 0) {
                    enqueue(i);
                }
            }
        }
    }

    // Check for cycle
    if(count != n) {
        printf("\nGraph has a cycle. Topological sort not possible.\n");
    }

    return 0;
}