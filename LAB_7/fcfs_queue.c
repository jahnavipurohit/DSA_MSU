#include <stdio.h>
#define MAX 5

int queue[MAX], front = -1, rear = -1;

void enqueue(int val) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = val;
}
int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int main() {
    printf("CPU Scheduling (FCFS)\n");
    enqueue(1); enqueue(2); enqueue(3);
    int p;
    while ((p = dequeue()) != -1)
        printf("Process %d executed\n", p);
    return 0;
}
