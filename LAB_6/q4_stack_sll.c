#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
struct Node {
    int data;
    struct Node* next;
};

// Pointer to the top of the stack
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
    newNode->next = top; // Link new node to previous top
    top = newNode;       // Update top
    printf("%d pushed onto stack.\n", value);
}

// Pop operation
int pop() {
    if (top == NULL) {
        printf("Stack Underflow! Cannot pop.\n");
        return -1;
    }
    struct Node* temp = top;
    int popped = temp->data;
    top = top->next;
    free(temp);
    printf("%d popped from stack.\n", popped);
    return popped;
}

// Peek operation
int peek() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }
    printf("Top element: %d\n", top->data);
    return top->data;
}

// Display stack elements
void display() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test push, pop, and display
int main() {
    // Testing operations
    push(10);
    push(20);
    push(30);
    display();
    pop();
    peek();
    display();
    return 0;
}
