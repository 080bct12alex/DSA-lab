#include <iostream>
using namespace std;


int factorialTail(int n, int result = 1) {
    if (n <= 1)
        return result;
    return factorialTail(n - 1, result * n);
}

int main() {
    int n;
    cout << "\nEnter a number: ";
    cin >> n;
    
    cout << "Tail Recursive Factorial of " << n << " is " << factorialTail(n) << endl;
   
    return 0;
}
