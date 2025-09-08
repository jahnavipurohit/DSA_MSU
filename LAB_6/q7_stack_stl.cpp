#include <iostream>
#include <stack> // STL stack header
using namespace std;

int main() {
    stack<int> s;
    int choice, value;

    while (true) {
        cout << "\n=== STACK OPERATIONS USING STL (C++) ===\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top Element\n";
        cout << "4. Display Size\n";
        cout << "5. Check if Empty\n";
        cout << "6. Display All Elements\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: // Push
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                cout << value << " pushed onto the stack.\n";
                break;

            case 2: // Pop
                if (s.empty()) {
                    cout << "Stack Underflow! Cannot pop.\n";
                } else {
                    cout << s.top() << " popped from the stack.\n";
                    s.pop();
                }
                break;

            case 3: // Top
                if (s.empty()) {
                    cout << "Stack is empty.\n";
                } else {
                    cout << "Top element: " << s.top() << "\n";
                }
                break;

            case 4: // Size
                cout << "Stack size: " << s.size() << "\n";
                break;

            case 5: // Empty
                if (s.empty()) {
                    cout << "Stack is empty.\n";
                } else {
                    cout << "Stack is not empty.\n";
                }
                break;

            case 6: // Display all elements
                if (s.empty()) {
                    cout << "Stack is empty.\n";
                } else {
                    cout << "Stack elements (top to bottom): ";
                    stack<int> temp = s; // Copy original stack
                    while (!temp.empty()) {
                        cout << temp.top() << " ";
                        temp.pop();
                    }
                    cout << "\n";
                }
                break;

            case 7:
                cout << "Exiting program...\n";
                return 0;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}
