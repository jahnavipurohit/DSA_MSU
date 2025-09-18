#include <stdio.h>
#define MAX 5

int s1[MAX], s2[MAX];
int top1 = -1, top2 = -1;

void push1(int val) { s1[++top1] = val; }
int pop1() { return s1[top1--]; }
void push2(int val) { s2[++top2] = val; }
int pop2() { return s2[top2--]; }

void enqueue(int val) {
    while (top1 != -1) push2(pop1());
    push1(val);
    while (top2 != -1) push1(pop2());
    printf("%d enqueued\n", val);
}

void dequeue() {
    if (top1 == -1) printf("Queue Empty\n");
    else printf("%d dequeued\n", pop1());
}

void display() {
    if (top1 == -1) { printf("Queue Empty\n"); return; }
    printf("Queue: ");
    for (int i = top1; i >= 0; i--) printf("%d ", s1[i]);
    printf("\n");
}

int main() {
    enqueue(10); enqueue(20); enqueue(30);
    display(); dequeue(); display();
    return 0;
}
