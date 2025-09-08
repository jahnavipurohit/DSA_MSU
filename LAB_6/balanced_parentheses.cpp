#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check if opening and closing brackets match
bool isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

// Function to check if expression has balanced parentheses
bool isBalanced(const string &expr) {
    stack<char> s;

    for (char ch : expr) {
        // If opening bracket, push onto stack
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        // If closing bracket, check if stack top matches
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty() || !isMatchingPair(s.top(), ch)) {
                return false;
            }
            s.pop();
        }
    }

    // Expression is balanced if stack is empty at the end
    return s.empty();
}

int main() {
    string expr;

    cout << "Enter an expression: ";
    cin >> expr;

    if (isBalanced(expr))
        cout << "The expression is BALANCED.\n";
    else
        cout << "The expression is NOT BALANCED.\n";

    return 0;
}
