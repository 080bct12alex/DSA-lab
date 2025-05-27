#include <iostream>
using namespace std;

#define SIZE 5

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

    int count() {
        return (top + 1);
    }

    int peek(int pos) {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
            return 0;
        } else if (pos < 0 || pos > top) {
            cout << "Invalid Position" << endl;
            return 0;
        } else {
            return arr[pos];
        }
    }

    void change(int pos, int val) {
        if (pos < 0 || pos > top) {
            cout << "Invalid Position" << endl;
        } else {
            arr[pos] = val;
            cout << "Value changed at position " << pos << endl;
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
    int option, position, value;

    do {
        cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. Push()" << endl;
        cout << "2. Pop()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. Peek()" << endl;
        cout << "6. Count()" << endl;
        cout << "7. Change()" << endl;
        cout << "8. Display()" << endl;
        cout << "9. Clear Screen" << endl;
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
            cout << (s1.isEmpty() ? "Stack is Empty" : "Stack is not Empty") << endl;
            break;
        case 4:
            cout << (s1.isFull() ? "Stack is Full" : "Stack is not Full") << endl;
            break;
        case 5:
            cout << "Enter position to peek: ";
            cin >> position;
            cout << "Value at position " << position << ": " << s1.peek(position) << endl;
            break;
        case 6:
            cout << "Total elements in stack: " << s1.count() << endl;
            break;
        case 7:
            cout << "Enter position to change: ";
            cin >> position;
            cout << "Enter new value: ";
            cin >> value;
            s1.change(position, value);
            break;
        case 8:
            s1.display();
            break;
        case 9:
            system("cls"); // use "clear" on Linux/Mac
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