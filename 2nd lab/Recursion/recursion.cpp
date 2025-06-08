#include <iostream>
using namespace std;

// 1. Factorial using recursion
int factorial(int n) {
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

// 2. Fibonacci using recursion
int fibonacci(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// 3. Factorial using tail recursion
int factorialTail(int n, int result = 1) {
    if (n <= 1)
        return result;
    return factorialTail(n - 1, result * n);
}

// 4. Fibonacci using tail recursion
int fibonacciTail(int n, int a = 0, int b = 1) {
    if (n == 0)
        return a;
    if (n == 1)
        return b;
    return fibonacciTail(n - 1, b, a + b);
}

int main() {
    int choice, n;

    cout << "Choose an option:\n";
    cout << "1. Factorial (normal recursion)\n";
    cout << "2. Fibonacci (normal recursion)\n";
    cout << "3. Factorial (tail recursion)\n";
    cout << "4. Fibonacci (tail recursion)\n";
    cout << "Enter your choice (1-4): ";
    cin >> choice;

    cout << "\nEnter a number: ";
    cin >> n;

    switch (choice) {
        case 1:
            cout << "Factorial of " << n << " is " << factorial(n) << endl;
            break;
        case 2:
            cout << n << "th Fibonacci number is " << fibonacci(n) << endl;
            break;
        case 3:
            cout << "Tail Recursive Factorial of " << n << " is " << factorialTail(n) << endl;
            break;
        case 4:
            cout << n << "th Tail Recursive Fibonacci number is "  << fibonacciTail(n) << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
    }

    return 0;
}
