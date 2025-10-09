#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    int size;
    struct Node* front;
    struct Node* back;
};

struct Queue obj;

void enqueue(int value) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (obj.back == NULL) {
        obj.front = obj.back = newNode;
    } else {
        obj.back->next = newNode;
        obj.back = newNode;
    }

    printf("%d added to queue\n", value);
}

void dequeue() {
    if (obj.front == NULL) {
        printf("Empty!\n");
        return;
    }

    struct Node* temp = obj.front;
    obj.front = obj.front->next;

    if (obj.front == NULL)
        obj.back = NULL;

    free(temp);
}

int showFront() {
    return obj.front->data;
}

int showBack() {
    return obj.back->data;
}

int main() {
    obj.size = 0;
    obj.front = NULL;
    obj.back = NULL;

    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("front: %d\n",showFront());
    printf("back: %d\n",showBack());
    dequeue();
    printf("front: %d\n",showFront());
    printf("back: %d\n",showBack());
    dequeue();
    return 0;
}

