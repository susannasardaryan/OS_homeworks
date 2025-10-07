#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int value) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) { 
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d added to queue\n", value);
}

void dequeue() {
    if (front == NULL) {
        printf("Empty!\n");
        return;
    }

    printf("%d removed\n", front->data);
    struct Node* temp = front;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

void showFront() {
    if (front == NULL)
        printf("Empty!\n");
    else
        printf("Front : %d\n", front->data);
}


int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    showFront();
    dequeue();
    showFront();

    return 0;
}

