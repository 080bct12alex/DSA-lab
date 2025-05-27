#include<iostream>
#include<stack>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

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

string InfixToPostfix(stack<char> s, string infix) {
    string postfix;
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        // If operand, add to postfix
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            postfix += c;
        }
        // If '(', push to stack
        else if (c == '(') {
            s.push(c);
        }
        // If ')', pop until '('
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty()) s.pop(); // remove '('
        }
        // If operator
        else if (isOperator(c)) {
            while (!s.empty() && precedence(c) <= precedence(s.top()) && !(c == '^' && s.top() == '^')) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    // Pop all remaining operators
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix_exp, postfix_exp;
    cout << "Enter an Infix Expression: ";
    cin >> infix_exp;

    stack<char> s;
    cout << "INFIX EXPRESSION: " << infix_exp << endl;
    postfix_exp = InfixToPostfix(s, infix_exp);
    cout << "POSTFIX EXPRESSION: " << postfix_exp << endl;

    return 0;
}