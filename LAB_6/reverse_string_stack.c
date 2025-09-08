#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

char stack[MAX];
int top = -1;

// Push a character onto the stack
void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push '%c'.\n", c);
        return;
    }
    stack[++top] = c;
}

// Pop a character from the stack
char pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return '\0';
    }
    return stack[top--];
}

// Function to reverse a string using stack
void reverseString(char str[]) {
    int n = strlen(str);

    // Push all characters onto the stack
    for (int i = 0; i < n; i++) {
        push(str[i]);
    }

    // Pop characters to reverse the string
    for (int i = 0; i < n; i++) {
        str[i] = pop();
    }
}

int main() {
    char str[MAX];

    printf("Enter a string: ");
    fgets(str, MAX, stdin);

    // Remove newline character if present
    str[strcspn(str, "\n")] = '\0';

    printf("Original string: %s\n", str);

    reverseString(str);

    printf("Reversed string: %s\n", str);

    return 0;
}
