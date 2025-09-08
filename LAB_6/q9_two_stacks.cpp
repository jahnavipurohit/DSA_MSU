#include <iostream>
#include <cstdlib>
using namespace std;

#define MAX 10

class TwoStacks {
private:
    int arr[MAX];
    int top1;
    int top2;

public:
    // Constructor
    TwoStacks() {
        top1 = -1;
        top2 = MAX;
    }

    // Push in Stack 1
    void push1(int value) {
        if (top1 + 1 == top2) {
            cout << "Stack Overflow! Cannot push " << value << " in Stack 1.\n";
            return;
        }
        arr[++top1] = value;
        cout << value << " pushed to Stack 1.\n";
    }

    // Push in Stack 2
    void push2(int value) {
        if (top1 + 1 == top2) {
            cout << "Stack Overflow! Cannot push " << value << " in Stack 2.\n";
            return;
        }
        arr[--top2] = value;
        cout << value << " pushed to Stack 2.\n";
    }

    // Pop from Stack 1
    void pop1() {
        if (top1 == -1) {
            cout << "Stack Underflow! Stack 1 is empty.\n";
            return;
        }
        cout << arr[top1--] << " popped from Stack 1.\n";
    }

    // Pop from Stack 2
    void pop2() {
        if (top2 == MAX) {
            cout << "Stack Underflow! Stack 2 is empty.\n";
            return;
        }
        cout << arr[top2++] << " popped from Stack 2.\n";
    }

    // Display Stack 1
    void display1() {
        if (top1 == -1) {
            cout << "Stack 1 is empty.\n";
            return;
        }
        cout << "Stack 1 elements: ";
        for (int i = top1; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Display Stack 2
    void display2() {
        if (top2 == MAX) {
            cout << "Stack 2 is empty.\n";
            return;
        }
        cout << "Stack 2 elements: ";
        for (int i = top2; i < MAX; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    TwoStacks ts;
    int choice, value;

    while (true) {
        cout << "\n=== TWO STACKS IN ONE ARRAY ===\n";
        cout << "1. Push in Stack 1\n";
        cout << "2. Push in Stack 2\n";
        cout << "3. Pop from Stack 1\n";
        cout << "4. Pop from Stack 2\n";
        cout << "5. Display Stack 1\n";
        cout << "6. Display Stack 2\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push in Stack 1: ";
                cin >> value;
                ts.push1(value);
                break;
            case 2:
                cout << "Enter value to push in Stack 2: ";
                cin >> value;
                ts.push2(value);
                break;
            case 3:
                ts.pop1();
                break;
            case 4:
                ts.pop2();
                break;
            case 5:
                ts.display1();
                break;
            case 6:
                ts.display2();
                break;
            case 7:
                cout << "Exiting program...\n";
                exit(0);
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
    return 0;
}
