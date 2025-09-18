#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

int isFull() { return rear == MAX - 1; }
int isEmpty() { return front == -1 || front > rear; }

void enqueue(int val) {
    if (isFull()) printf("Queue Overflow\n");
    else {
        if (front == -1) front = 0;
        queue[++rear] = val;
        printf("%d enqueued\n", val);
    }
}

void dequeue() {
    if (isEmpty()) printf("Queue Underflow\n");
    else printf("%d dequeued\n", queue[front++]);
}

void peek() {
    if (isEmpty()) printf("Queue Empty\n");
    else printf("Front: %d\n", queue[front]);
}

void display() {
    if (isEmpty()) printf("Queue Empty\n");
    else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++) printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    enqueue(10); enqueue(20); enqueue(30);
    display(); peek();
    dequeue(); display();
    return 0;
}
