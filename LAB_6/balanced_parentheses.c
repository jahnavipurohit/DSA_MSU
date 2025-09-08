#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

// Push a character onto the stack
void push(char ch) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = ch;
}

// Pop a character from the stack
char pop() {
    if (top == -1) {
        return '\0';  // Stack underflow
    }
    return stack[top--];
}

// Function to check if opening and closing brackets match
int isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

// Function to check if expression has balanced parentheses
int isBalanced(char expr[]) {
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        // If opening bracket, push to stack
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }
        // If closing bracket, pop and check match
        else if (ch == ')' || ch == '}' || ch == ']') {
            char topChar = pop();
            if (!isMatchingPair(topChar, ch)) {
                return 0; // Not balanced
            }
        }
    }

    // If stack empty, expression is balanced
    return top == -1;
}

int main() {
    char expr[MAX];

    printf("Enter an expression: ");
    scanf("%s", expr);

    if (isBalanced(expr))
        printf("The expression is BALANCED.\n");
    else
        printf("The expression is NOT BALANCED.\n");

    return 0;
}
