#include <stdio.h>
#define MAX 5

int q1[MAX], q2[MAX];
int front1 = -1, rear1 = -1, front2 = -1, rear2 = -1;

int isEmpty1() { return front1 == -1; }
int isEmpty2() { return front2 == -1; }

void enqueue1(int val) {
    if (rear1 == MAX - 1) return;
    if (front1 == -1) front1 = 0;
    q1[++rear1] = val;
}
int dequeue1() {
    if (isEmpty1()) return -1;
    int val = q1[front1];
    if (front1 == rear1) front1 = rear1 = -1;
    else front1++;
    return val;
}
void enqueue2(int val) {
    if (rear2 == MAX - 1) return;
    if (front2 == -1) front2 = 0;
    q2[++rear2] = val;
}
int dequeue2() {
    if (isEmpty2()) return -1;
    int val = q2[front2];
    if (front2 == rear2) front2 = rear2 = -1;
    else front2++;
    return val;
}

void push(int val) {
    enqueue2(val);
    while (!isEmpty1()) enqueue2(dequeue1());
    while (!isEmpty2()) enqueue1(dequeue2());
    printf("%d pushed\n", val);
}

void pop() {
    if (isEmpty1()) printf("Stack Empty\n");
    else printf("%d popped\n", dequeue1());
}

void display() {
    if (isEmpty1()) { printf("Stack Empty\n"); return; }
    printf("Stack: ");
    for (int i = front1; i <= rear1; i++) printf("%d ", q1[i]);
    printf("\n");
}

int main() {
    push(10); push(20); push(30);
    display(); pop(); display();
    return 0;
}
