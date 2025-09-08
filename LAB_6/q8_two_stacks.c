#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int arr[MAX];
int top1 = -1;      // Top pointer for Stack 1
int top2 = MAX;     // Top pointer for Stack 2

// Push in Stack 1
void push1(int value) {
    if (top1 + 1 == top2) {
        printf("Stack Overflow! Cannot push %d in Stack 1.\n", value);
        return;
    }
    arr[++top1] = value;
    printf("%d pushed to Stack 1.\n", value);
}

// Push in Stack 2
void push2(int value) {
    if (top1 + 1 == top2) {
        printf("Stack Overflow! Cannot push %d in Stack 2.\n", value);
        return;
    }
    arr[--top2] = value;
    printf("%d pushed to Stack 2.\n", value);
}

// Pop from Stack 1
void pop1() {
    if (top1 == -1) {
        printf("Stack Underflow! Stack 1 is empty.\n");
        return;
    }
    printf("%d popped from Stack 1.\n", arr[top1--]);
}

// Pop from Stack 2
void pop2() {
    if (top2 == MAX) {
        printf("Stack Underflow! Stack 2 is empty.\n");
        return;
    }
    printf("%d popped from Stack 2.\n", arr[top2++]);
}

// Display Stack 1
void display1() {
    if (top1 == -1) {
        printf("Stack 1 is empty.\n");
        return;
    }
    printf("Stack 1 elements: ");
    for (int i = top1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Display Stack 2
void display2() {
    if (top2 == MAX) {
        printf("Stack 2 is empty.\n");
        return;
    }
    printf("Stack 2 elements: ");
    for (int i = top2; i < MAX; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main menu-driven function
int main() {
    int choice, value;
    while (1) {
        printf("\n=== TWO STACKS IN ONE ARRAY ===\n");
        printf("1. Push in Stack 1\n");
        printf("2. Push in Stack 2\n");
        printf("3. Pop from Stack 1\n");
        printf("4. Pop from Stack 2\n");
        printf("5. Display Stack 1\n");
        printf("6. Display Stack 2\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push in Stack 1: ");
                scanf("%d", &value);
                push1(value);
                break;
            case 2:
                printf("Enter value to push in Stack 2: ");
                scanf("%d", &value);
                push2(value);
                break;
            case 3:
                pop1();
                break;
            case 4:
                pop2();
                break;
            case 5:
                display1();
                break;
            case 6:
                display2();
                break;
            case 7:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
