//Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }

    struct Node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    return value;
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int evaluatePostfix(char exp[]) {
    char* token = strtok(exp, " ");

    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(atoi(token));
        }
        else if (isOperator(token[0])) {
            int b = pop();
            int a = pop();
            int result;

            switch (token[0]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
                default: return -1;
            }

            push(result);
        }

        token = strtok(NULL, " ");
    }

    return pop();
}

int main() {
    char exp[1000];

    fgets(exp, sizeof(exp), stdin);

    exp[strcspn(exp, "\n")] = '\0';

    int result = evaluatePostfix(exp);
    printf("%d\n", result);

    return 0;
}