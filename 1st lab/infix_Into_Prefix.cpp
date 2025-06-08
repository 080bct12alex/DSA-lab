#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

// Function to check if a character is an operator
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
string InfixToPrefix(string infix) {
    stack<char> s;
    string prefix;

    // Step 1: Reverse the given expression (infix)
    reverse(infix.begin(), infix.end());

    // Step 1: Swap '(' with ')' and vice versa ie Replace “(“ with “)” and vice versa as part of reverse
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    // Step 2:Scan the reversed expression from left to right(Iterate through each character) 
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        // Step 3: If operand, add to result(prefix string)
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || isdigit(c)) {
            prefix += c;
        }

        // Step 5: If parenthesis  
        // Step 5.a: If   '(', push to stack
        else if (c == '(') {
            s.push(c);
        }

        // Step 5.b: If ')', pop operators from stack to prefix until '('
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                prefix += s.top();
                s.pop();
            }
            if (!s.empty() && s.top() == '(')
                s.pop();  // remove the '('
        }

        // Step 3: If operator
        else if (isOperator(c)) {
    // If the stack is empty, push the operator
    if (s.empty()) {
        s.push(c);
    }
    else {
        // If current operator has higher precedence than top of stack, push it
        if (precedence(c) > precedence(s.top())) {
            s.push(c);
        }
        // If current operator has equal precedence and is '^' (right-associative)
        else if ((precedence(c) == precedence(s.top())) && (c == '^')) {
            // Pop all '^' operators of the same precedence from the stack
            while (precedence(c) == precedence(s.top()) && c == '^') {
                prefix += s.top();  
                s.pop();            
            }
            s.push(c);              // Push current '^' onto the stack
        }
        // If current operator has equal precedence but is NOT '^'
        else if ((precedence(c) == precedence(s.top()))) {
            // Just push the current operator (assumes left-associative)
            s.push(c);
        }
        else {
            // If current operator has lower precedence, pop from stack to result
            while (!s.empty() && precedence(c) < precedence(s.top())) {
                prefix += s.top();  
                s.pop();            
            }
            // After popping, push the current operator
            s.push(c);
        }
    }
}

    }

    // Step 6: Pop remaining operators from the stack
    while (!s.empty()) {
        prefix += s.top();
        s.pop();
    }

    // Step 7: Reverse to get final prefix
    reverse(prefix.begin(), prefix.end());

    return prefix;
}

int main() {
    string infix;
    cout << "\nEnter an Infix Expression: ";
    cin >> infix;

    cout << "INFIX EXPRESSION: " << infix << endl;

    string prefix = InfixToPrefix(infix);
    cout << "PREFIX EXPRESSION: " << prefix << endl;

    return 0;
}
