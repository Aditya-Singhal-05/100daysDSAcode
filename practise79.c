#include <stdio.h>
#include <limits.h>

#define MAX 100

// adjacency list
struct Node {
    int v, w;
    struct Node* next;
};

struct Node* adj[MAX];

// heap
struct Heap {
    int v;
    int dist;
};

struct Heap heap[MAX * MAX];
int size = 0;

// swap
void swap(struct Heap* a, struct Heap* b) {
    struct Heap temp = *a;
    *a = *b;
    *b = temp;
}

// heapify up
void up(int i) {
    while (i > 0 && heap[(i - 1) / 2].dist > heap[i].dist) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// heapify down
void down(int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && heap[l].dist < heap[smallest].dist)
        smallest = l;
    if (r < size && heap[r].dist < heap[smallest].dist)
        smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        down(smallest);
    }
}

// push
void push(int v, int d) {
    heap[size].v = v;
    heap[size].dist = d;
    up(size);
    size++;
}

// pop
struct Heap pop() {
    struct Heap root = heap[0];
    heap[0] = heap[--size];
    down(0);
    return root;
}

// add edge (directed or undirected depends on input)
void addEdge(int u, int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->v = v;
    newNode->w = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Dijkstra
void dijkstra(int n, int src) {
    int dist[MAX];

    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;
    push(src, 0);

    while (size > 0) {
        struct Heap cur = pop();
        int u = cur.v;

        struct Node* temp = adj[u];
        while (temp) {
            int v = temp->v;
            int w = temp->w;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }

            temp = temp->next;
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i] == INT_MAX ? -1 : dist[i]);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        addEdge(u, v, w);
        // If undirected, also add:
        // addEdge(v, u, w);
    }

    int src;
    scanf("%d", &src);

    dijkstra(n, src);

    return 0;
}