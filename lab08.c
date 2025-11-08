#include <stdio.h>
#include <stdlib.h>

#define MAX 30
#define INF 9999

int parent[MAX];

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    int n, edges;
    int u, v, w;
    int i, j, k = 1;
    int mincost = 0;
    int cost[MAX][MAX];

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            cost[i][j] = INF;

    printf("Enter edges (u v w):\n");
    for (i = 1; i <= edges; i++) {
        scanf("%d %d %d", &u, &v, &w);
        cost[u][v] = w;
        cost[v][u] = w;
    }

    while (k < n) {
        int a = -1, b = -1, min = INF;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        if (a == -1 || b == -1)
            break;

        int uroot = find(a);
        int vroot = find(b);

        if (uni(uroot, vroot)) {
            printf("Edge %d: (%d - %d) cost: %d\n", k, a, b, min);
            k++;
            mincost += min;
        }

        cost[a][b] = cost[b][a] = INF;
    }

    printf("Minimum cost of MST = %d\n", mincost);
    return 0;
}
