#include <stdio.h>
#define MAX 5

int cq[MAX];
int front = -1, rear = -1;

int isFull() { return (front == (rear + 1) % MAX); }
int isEmpty() { return front == -1; }

void enqueue(int val) {
    if (isFull()) printf("Queue Overflow\n");
    else {
        if (front == -1) front = 0;
        rear = (rear + 1) % MAX;
        cq[rear] = val;
        printf("%d enqueued\n", val);
    }
}

void dequeue() {
    if (isEmpty()) printf("Queue Underflow\n");
    else {
        printf("%d dequeued\n", cq[front]);
        if (front == rear) front = rear = -1;
        else front = (front + 1) % MAX;
    }
}

void display() {
    if (isEmpty()) { printf("Queue Empty\n"); return; }
    printf("Queue: ");
    int i = front;
    while (1) {
        printf("%d ", cq[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    enqueue(10); enqueue(20); enqueue(30);
    display(); dequeue(); display();
    return 0;
}
