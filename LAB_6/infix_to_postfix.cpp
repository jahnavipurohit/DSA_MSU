#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

// Return precedence of operators
int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*': case '/': return 2;
        case '+': case '-': return 1;
        default: return 0;
    }
}

// Check if character is an operator
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Convert infix expression to postfix using STL stack
string infixToPostfix(const string &infix) {
    stack<char> s;
    string postfix = "";

    for (char ch : infix) {
        // Operand -> add to postfix
        if (isalnum(ch)) {
            postfix += ch;
        }
        // '(' -> push to stack
        else if (ch == '(') {
            s.push(ch);
        }
        // ')' -> pop until '('
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty()) s.pop(); // Remove '('
        }
        // Operator
        else if (isOperator(ch)) {
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    // Pop remaining operators
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix;

    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
