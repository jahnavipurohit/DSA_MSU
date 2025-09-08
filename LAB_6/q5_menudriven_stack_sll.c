#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Push operation
void push(int value) {
    struct Node* newNode = createNode(value);
    newNode->next = top;
    top = newNode;
    printf("\n%d pushed onto stack.\n", value);
}

// Pop operation
int pop() {
    if (top == NULL) {
        printf("\nStack Underflow! Cannot pop.\n");
        return -1;
    }
    struct Node* temp = top;
    int popped = temp->data;
    top = top->next;
    free(temp);
    printf("\n%d popped from stack.\n", popped);
    return popped;
}

// Peek operation
int peek() {
    if (top == NULL) {
        printf("\nStack is empty.\n");
        return -1;
    }
    printf("\nTop element: %d\n", top->data);
    return top->data;
}

// Display stack elements
void display() {
    if (top == NULL) {
        printf("\nStack is empty.\n");
        return;
    }
    struct Node* temp = top;
    printf("\nStack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function — menu driven
int main() {
    int choice, value;

    while (1) {
        printf("\n=== STACK OPERATIONS USING LINKED LIST ===\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}
