#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int val) {
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = val; temp->next = NULL;
    if (rear == NULL) front = rear = temp;
    else { rear->next = temp; rear = temp; }
    printf("%d enqueued\n", val);
}

void dequeue() {
    if (front == NULL) { printf("Queue Underflow\n"); return; }
    struct Node* temp = front;
    printf("%d dequeued\n", front->data);
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
}

void peek() {
    if (front == NULL) printf("Queue Empty\n");
    else printf("Front: %d\n", front->data);
}

void display() {
    struct Node* temp = front;
    if (!temp) { printf("Queue Empty\n"); return; }
    printf("Queue: ");
    while (temp) { printf("%d ", temp->data); temp = temp->next; }
    printf("\n");
}

int main() {
    enqueue(10); enqueue(20); enqueue(30);
    display(); peek();
    dequeue(); display();
    return 0;
}
