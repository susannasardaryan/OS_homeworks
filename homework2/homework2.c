#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
}

void pop() {
    if (top == NULL) {
        printf("Empty!\n");
        return;
    }

    struct Node* temp = top;
    top = top->next;
    free(temp);
}

int showTop() {
    return top->data;
}

bool isEmpty(){
    return top==NULL;
}

int main() {
    push(10);
    push(20);
    push(30);

    printf("Top: %d\n",showTop());
    pop();
    printf("Top: %d\n",showTop());
    pop();
    printf("Top: %d\n",showTop());
    pop();
    printf("IsEmpty: %d\n",isEmpty());


    return 0;
}
