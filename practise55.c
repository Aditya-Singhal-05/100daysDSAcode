#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Build tree from level-order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);

    struct Node* queue[MAX];
    int front = 0, rear = -1;

    queue[++rear] = root;
    int i = 1;

    while (i < n) {
        struct Node* curr = queue[front++];

        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[++rear] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[++rear] = curr->right;
        }
        i++;
    }

    return root;
}

// Right view function
void rightView(struct Node* root) {
    if (root == NULL) return;

    struct Node* queue[MAX];
    int front = 0, rear = -1;

    queue[++rear] = root;

    while (front <= rear) {
        int levelSize = rear - front + 1;

        for (int i = 0; i < levelSize; i++) {
            struct Node* curr = queue[front++];

            // Last node of level → right view
            if (i == levelSize - 1)
                printf("%d ", curr->data);

            if (curr->left)
                queue[++rear] = curr->left;

            if (curr->right)
                queue[++rear] = curr->right;
        }
    }
}

// Main
int main() {
    int N;
    scanf("%d", &N);

    int arr[MAX];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, N);

    rightView(root);

    return 0;
}