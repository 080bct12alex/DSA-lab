#include <iostream>
#include <stack>
#include <string>

using namespace std;

void checkParentheses(string expression) {
    stack<int> positions; // Stores positions (indexes) of '('
    bool errorFound = false;

    for (int i = 0; i < expression.length(); ++i) {
        char ch = expression[i];

        if (ch == '(') {
            positions.push(i); // Store the index of '('
        } else if (ch == ')') {
            if (positions.empty()) {
                cout << "Unmatched ')' at position " << i << endl;
                errorFound = true;
            } else {
                positions.pop(); // Pop the matched '('
            }
        }
    }

    // Unmatched '(' remaining in the stack
    while (!positions.empty()) {
        cout << "Unmatched '(' at position " << positions.top() << endl;
        positions.pop();
        errorFound = true;
    }

    if (!errorFound) {
        cout << "All parentheses are correctly matched.\n";
    }
}

int main() {
    string expression;

    cout << "\nEnter an arithmetic expression: ";
    getline(cin, expression);   // Reads the whole line with spaces

    checkParentheses(expression);

    return 0;
}
