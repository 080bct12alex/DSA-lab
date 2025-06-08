#include<iostream>
#include<stack>
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

// Function to convert infix to postfix
string InfixToPostfix( string infix) {
    stack<char> s;
    string postfix;
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        // If operand, add to postfix
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || isdigit(c)) {
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
            if (!s.empty()) 
            s.pop(); // remove '('
        }
        // If operator
      else if (isOperator(c)) { 
    if (s.empty()) {
        s.push(c);           // If the stack is empty, push the operator directly
    }
    else if (precedence(c) > precedence(s.top())) {
        s.push(c);              // If current operator has higher precedence than stack top, push it
    }
    else if (precedence(c) == precedence(s.top()) && c == '^') {
        s.push(c);                 // If current operator is '^' and has equal precedence, push it (right-associative)
    }
    else {
        // While stack is not empty AND
        // (current operator has lower precedence OR
        // has equal precedence and is left-associative)
        while (!s.empty() &&
               ((precedence(c) < precedence(s.top())) ||
                (precedence(c) == precedence(s.top()) && c != '^'))) {
            postfix += s.top(); // Pop operator from stack and add to postfix expression
            s.pop();            // Remove that operator from stack
        }
        s.push(c); // After popping lower or equal precedence operators, push current operator
    }
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
    string infix, postfix;
    cout << "\nEnter an Infix Expression: ";
    cin >> infix;

   
    cout << "INFIX EXPRESSION: " << infix << endl;
    postfix = InfixToPostfix(infix);
    cout << "POSTFIX EXPRESSION: " << postfix << endl;

    return 0;
}