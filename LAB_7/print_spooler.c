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
    printf("Print Spooler Simulation\n");
    enqueue(101); enqueue(102); enqueue(103);
    int job;
    while ((job = dequeue()) != -1)
        printf("Print Job %d completed\n", job);
    return 0;
}
