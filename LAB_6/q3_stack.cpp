#include <iostream>
using namespace std;

#define MAX 100

class Stack {
private:
    int arr[MAX];  // Array to store stack elements
    int top;       // Top pointer

public:
    // Constructor
    Stack() {
        top = -1;
    }

    // Push operation
    void push(int value) {
        if (top == MAX - 1) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
        cout << value << " pushed onto the stack." << endl;
    }

    // Pop operation
    int pop() {
        if (top == -1) {
            cout << "Stack Underflow! Cannot pop." << endl;
            return -1;
        }
        cout << arr[top] << " popped from the stack." << endl;
        return arr[top--];
    }

    // Peek operation (returns top element)
    int peek() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        cout << "Top element: " << arr[top] << endl;
        return arr[top];
    }

    // Display the stack
    void display() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if stack is full
    bool isFull() {
        return top == MAX - 1;
    }
};

int main() {
    Stack s;
    int choice, value;

    while (true) {
        cout << "\n--- Stack Menu (C++ Class-Based) ---\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.peek();
                break;
            case 4:
                s.display();
                break;
            case 5:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
