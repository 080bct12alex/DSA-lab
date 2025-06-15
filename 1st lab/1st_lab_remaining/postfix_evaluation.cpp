#include <iostream>
#include <stack>
#include <cmath>   

using namespace std;

// Evaluate postfix expression with single-digit operands
int EvaluatePostfix(string postfix) {
    

    stack<int> s;

    for (int i = 0; i < postfix.length(); i++) {
    char c = postfix[i];
        if (isspace(c)) continue;  // ignore spaces   
      //or //if (c == ' ') continue;  
     
        if (isdigit(c)) {
            s.push(c - '0');  // convert char digit to int and push
            
            // or  // Classical digit to integer using switch
      /* if (c >= '0' && c <= '9') {
        int value = 0;
        switch (c) {
            case '0': value = 0; break;
            case '1': value = 1; break;
            case '2': value = 2; break;
            case '3': value = 3; break;
            case '4': value = 4; break;
            case '5': value = 5; break;
            case '6': value = 6; break;
            case '7': value = 7; break;
            case '8': value = 8; break;
            case '9': value = 9; break;
        }
        s.push(value);
    } 
    */
        }
        else {
            // Operator encountered
            int A = s.top(); s.pop();
            int B = s.top(); s.pop();
            int result = 0;

            switch (c) {
                case '+': result = B + A; break;
                case '-': result = B - A; break;
                case '*': result = B * A; break;
                case '/': result = B / A; break;
                case '^': result = pow(B, A); break;
                default:
                    cout << "Error: Unknown operator " << c << endl;
                    exit(EXIT_FAILURE);
            }

            s.push(result);
        }
    }

    return s.top();
}

int main() {
    string postfix;
    cout << "Enter a postfix expression : ";
    cin >> postfix;

    int result = EvaluatePostfix(postfix);

    cout << "Evaluated Result: " << result << endl;

    return 0;
}
