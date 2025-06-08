#include <iostream>
using namespace std;

#define SIZE 2

class Stack {
private:
    int arr[SIZE];
    int top;

public:
    Stack() {
        top = -1;
        for (int i = 0; i < SIZE; i++) {
            arr[i] = 0;
        }
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == SIZE - 1;
    }

    void push(int val) {
        if (isFull()) {
            cout << "Stack Overflow" << endl;
        } else {
            top++;
            arr[top] = val;
        }
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return 0;
        } else {
            int popValue = arr[top];
            arr[top] = 0;
            top--;
            return popValue;
        }
    }

    

    void display() {
        cout << "All values in the Stack are: " << endl;
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }
};

int main() {
    Stack s1;
    int option,  value;

    do {
        cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. Push()" << endl;
        cout << "2. Pop()" << endl;
        cout << "3. Display()" << endl;
        cout << "Option: ";
        cin >> option;

        switch (option) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s1.push(value);
            break;
        case 2:
            cout << "Pop Function Called - Popped Value: " << s1.pop() << endl;
            break;
        
       case 3:
            s1.display();
            break;
        
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Enter a valid option." << endl;
        }
    } while (option != 0);

    return 0;
}