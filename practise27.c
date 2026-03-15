//Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* createList(int n) {
    struct node *head = NULL, *temp = NULL, *newnode;

    for(int i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

int length(struct node *head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

int findIntersection(struct node *l1, struct node *l2) {
    int len1 = length(l1);
    int len2 = length(l2);

    int diff = abs(len1 - len2);

    if(len1 > len2) {
        for(int i = 0; i < diff; i++)
            l1 = l1->next;
    } else {
        for(int i = 0; i < diff; i++)
            l2 = l2->next;
    }

    while(l1 != NULL && l2 != NULL) {
        if(l1->data == l2->data)
            return l1->data;

        l1 = l1->next;
        l2 = l2->next;
    }

    return -1;
}

int main() {

    int n, m;

    scanf("%d", &n);
    struct node *list1 = createList(n);

    scanf("%d", &m);
    struct node *list2 = createList(m);

    int result = findIntersection(list1, list2);

    if(result == -1)
        printf("No Intersection");
    else
        printf("%d", result);

    return 0;
}