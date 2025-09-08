#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to reverse a string using stack
string reverseString(const string &str) {
    stack<char> s;

    // Push all characters into the stack
    for (char ch : str) {
        s.push(ch);
    }

    // Pop characters to build reversed string
    string reversed = "";
    while (!s.empty()) {
        reversed += s.top();
        s.pop();
    }

    return reversed;
}

int main() {
    string str;

    cout << "Enter a string: ";
    getline(cin, str);

    cout << "Original string: " << str << endl;

    string reversed = reverseString(str);

    cout << "Reversed string: " << reversed << endl;

    return 0;
}
