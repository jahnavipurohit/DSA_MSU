#include <stdio.h>
#define MAX 5

struct Element {
    int data, priority;
};
struct Element pq[MAX];
int size = 0;

int isFull() { return size == MAX; }
int isEmpty() { return size == 0; }

void enqueue(int val, int p) {
    if (isFull()) printf("Priority Queue Full\n");
    else {
        pq[size].data = val;
        pq[size].priority = p;
        size++;
        printf("%d enqueued with priority %d\n", val, p);
    }
}

void dequeue() {
    if (isEmpty()) { printf("Priority Queue Empty\n"); return; }
    int highest = 0;
    for (int i = 1; i < size; i++)
        if (pq[i].priority < pq[highest].priority) highest = i;
    printf("%d dequeued (priority %d)\n", pq[highest].data, pq[highest].priority);
    for (int i = highest; i < size - 1; i++) pq[i] = pq[i + 1];
    size--;
}

void peek() {
    if (isEmpty()) printf("Queue Empty\n");
    else {
        int highest = 0;
        for (int i = 1; i < size; i++)
            if (pq[i].priority < pq[highest].priority) highest = i;
        printf("Front: %d (priority %d)\n", pq[highest].data, pq[highest].priority);
    }
}

void display() {
    if (isEmpty()) { printf("Empty Queue\n"); return; }
    printf("Queue: ");
    for (int i = 0; i < size; i++)
        printf("(%d,p%d) ", pq[i].data, pq[i].priority);
    printf("\n");
}

int main() {
    enqueue(10, 2); enqueue(20, 1); enqueue(30, 3);
    display(); peek();
    dequeue(); display();
    return 0;
}
