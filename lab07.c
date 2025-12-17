#include <stdio.h>

#define N 9

int graph[N+1][N+1];
int visited[N+1];

void addEdge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void BFS(int start) {
    int queue[N], front = 0, rear = 0;
    for (int i = 1; i <= N; i++) visited[i] = 0;

    printf("BFS Order: ");
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 1; i <= N; i++)
            if (graph[node][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
    }
    printf("\n");
}

void DFS(int start) {
    int stack[N], top = -1;
    for (int i = 1; i <= N; i++) visited[i] = 0;

    printf("DFS Order: ");
    stack[++top] = start;

    while (top >= 0) {
        int node = stack[top--];
        if (!visited[node]) {
            printf("%d ", node);
            visited[node] = 1;

            for (int i = N; i >= 1; i--)
                if (graph[node][i] && !visited[i])
                    stack[++top] = i;
        }
    }
    printf("\n");
}

int main() {
    addEdge(1,2); addEdge(1,4);
    addEdge(2,3); addEdge(2,5);
    addEdge(3,6);
    addEdge(4,5); addEdge(4,7);
    addEdge(5,6); addEdge(5,8);
    addEdge(6,9);
    addEdge(7,8);
    addEdge(8,9);

    int start = 1;
    printf("Starting from Node %d\n", start);
    BFS(start);
    DFS(start);

    return 0;
}

