#include <stdio.h>
#define MAX 10

int arr[MAX];
int front1 = -1, rear1 = -1;
int front2 = MAX, rear2 = MAX;

void enqueue1(int val) {
    if (rear1 + 1 == rear2) printf("Overflow\n");
    else {
        if (front1 == -1) front1 = 0;
        arr[++rear1] = val;
        printf("%d enqueued in Q1\n", val);
    }
}

void enqueue2(int val) {
    if (rear2 - 1 == rear1) printf("Overflow\n");
    else {
        if (front2 == MAX) front2 = MAX - 1;
        arr[--rear2] = val;
        printf("%d enqueued in Q2\n", val);
    }
}

void dequeue1() {
    if (front1 == -1 || front1 > rear1) printf("Q1 Empty\n");
    else printf("%d dequeued from Q1\n", arr[front1++]);
}

void dequeue2() {
    if (front2 == MAX || front2 < rear2) printf("Q2 Empty\n");
    else printf("%d dequeued from Q2\n", arr[front2--]);
}

void display1() {
    if (front1 == -1 || front1 > rear1) { printf("Q1 Empty\n"); return; }
    printf("Q1: ");
    for (int i = front1; i <= rear1; i++) printf("%d ", arr[i]);
    printf("\n");
}

void display2() {
    if (front2 == MAX || front2 < rear2) { printf("Q2 Empty\n"); return; }
    printf("Q2: ");
    for (int i = front2; i >= rear2; i--) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    enqueue1(10); enqueue1(20);
    enqueue2(100); enqueue2(200);
    display1(); display2();
    dequeue1(); dequeue2();
    display1(); display2();
    return 0;
}
