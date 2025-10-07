#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int value) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d pushed to stack\n", value);
}

void pop() {
    if (top == NULL) {
        printf("Empty!\n");
        return;
    }
    printf("%d popped from stack\n", top->data);
    struct Node* temp = top;
    top = top->next;
    free(temp);
}

void showTop() {
    if (top == NULL)
        printf("Empty!\n");
    else
        printf("Top : %d\n", top->data);
}

int main() {
    push(10);
    push(20);
    push(30);

    showTop();
    pop();
    showTop();

    return 0;
}
