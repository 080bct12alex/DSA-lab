#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

// Function to check if the character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to return precedence of operators
int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// Function to convert infix to prefix
string InfixToPrefix(stack<char> s, string infix) {
    string prefix;

    // Reverse infix expression
    reverse(infix.begin(), infix.end());

    // Replace ( with ) and vice versa
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    // Iterate through each character
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        // If operand, add to prefix string
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || isdigit(c)) {
            prefix += c;
        }

        // If '(', push to stack
        else if (c == '(') {
            s.push(c);
        }

        // If ')', pop and add to prefix until '('
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                prefix += s.top();
                s.pop();
            }
            if (!s.empty() && s.top() == '(')
                s.pop();
        }

        // If operator
        else if (isOperator(c)) {
            while (!s.empty() && precedence(c) < precedence(s.top())) {
                prefix += s.top();
                s.pop();
            }
            // For right-associative operators like '^'
            while (!s.empty() && precedence(c) == precedence(s.top()) && c != '^') {
                prefix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    // Pop remaining operators from the stack
    while (!s.empty()) {
        prefix += s.top();
        s.pop();
    }

    // Reverse result to get final prefix
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main() {
    string infix, prefix;
    cout << "Enter an Infix Expression: ";
    cin >> infix;

    stack<char> stack;
    cout << "INFIX EXPRESSION: " << infix << endl;

    prefix = InfixToPrefix(stack, infix);
    cout << "PREFIX EXPRESSION: " << prefix << endl;

    return 0;
}