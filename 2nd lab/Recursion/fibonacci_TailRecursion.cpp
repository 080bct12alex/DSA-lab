#include <iostream>
using namespace std;

int fibonacciTail(int n, int a = 0, int b = 1) {
    if (n == 0)
        return a;
    if (n == 1)
        return b;
    return fibonacciTail(n - 1, b, a + b);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    
    cout << n << "th Tail Recursive Fibonacci number is "  << fibonacciTail(n) << endl;

    return 0;
}
