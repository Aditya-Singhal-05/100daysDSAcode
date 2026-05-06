#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge (undirected)
void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

// DFS
void DFS(int v) {
    visited[v] = 1;

    struct Node* temp = adj[v];
    while (temp) {
        int u = temp->vertex;
        if (!visited[u]) {
            DFS(u);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize
    for (int i = 1; i <= n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    int components = 0;

    // Count components
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            DFS(i);
            components++;
        }
    }

    printf("%d\n", components);

    return 0;
}