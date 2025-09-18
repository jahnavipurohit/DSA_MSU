#include <stdio.h>
#define MAX 5

struct Customer { int id, priority; };
struct Customer pq[MAX];
int size = 0;

void enqueue(int id, int p) { pq[size].id = id; pq[size].priority = p; size++; }
int dequeue() {
    if (size == 0) return -1;
    int highest = 0;
    for (int i = 1; i < size; i++)
        if (pq[i].priority < pq[highest].priority) highest = i;
    int id = pq[highest].id;
    for (int i = highest; i < size - 1; i++) pq[i] = pq[i+1];
    size--;
    return id;
}

int main() {
    printf("Customer Service Queue\n");
    enqueue(1, 2); enqueue(2, 1); enqueue(3, 3);
    int c;
    while ((c = dequeue()) != -1)
        printf("Customer %d served\n", c);
    return 0;
}
