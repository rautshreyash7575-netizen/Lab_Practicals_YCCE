#include <stdio.h>

#define MAX 30
#define INF 9999

struct Edge {
    int u, v, w;
};

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
    int n, e;
    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &e);

    struct Edge edges[e];
    printf("Enter edges (u v w):\n");
    for (int i = 0; i < e; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    int mincost = 0, k = 0;

    while (k < n - 1) {
        int min = INF;
        int a = -1, b = -1;

        for (int i = 0; i < e; i++) {
            int uroot = find(edges[i].u);
            int vroot = find(edges[i].v);

            if (uroot != vroot && edges[i].w < min) {
                min = edges[i].w;
                a = edges[i].u;
                b = edges[i].v;
            }
        }

        if (a == -1) break;

        if (uni(find(a), find(b))) {
            printf("Edge %d: (%d-%d) cost: %d\n", k + 1, a, b, min);
            mincost += min;
            k++;
        }
    }

    printf("Minimum cost of MST = %d\n", mincost);
    return 0;
}
