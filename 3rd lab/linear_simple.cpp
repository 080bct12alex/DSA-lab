#include <iostream>
using namespace std;

class LinearQueue {
private:
    int front;
    int rear;
    int arr[5];

public:
    LinearQueue() {
        front = -1;
        rear = -1;
        for (int i = 0; i < 5; i++)
            arr[i] = 0;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return (rear == 4);
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        } else if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;
        }
        arr[rear] = val;
    }

    int dequeue() {
        int x = 0;
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return x;
        } else if (front == rear) {  // only one element
            x = arr[front];
            arr[front] = 0;
            front = rear = -1;
        } else {
            x = arr[front];
            arr[front] = 0;
            front++;
        }
        return x;
    }

    int count() {
        if (isEmpty())
            return 0;
        return (rear - front + 1);
    }

    void display() {
        cout << "All values in the Queue are: ";
        for (int i = 0; i < 5; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    LinearQueue q1;
    int value, option;

    do {
        cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. Enqueue()" << endl;
        cout << "2. Dequeue()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. count()" << endl;
        cout << "6. display()" << endl;

        cin >> option;

        switch (option) {
            case 0:
                break;
            case 1:
                cout << "Enqueue Operation\nEnter an item to enqueue in the Queue: ";
                cin >> value;
                q1.enqueue(value);
                break;
            case 2:
                cout << "Dequeue Operation\nDequeued Value: " << q1.dequeue() << endl;
                break;
            case 3:
                cout << (q1.isEmpty() ? "Queue is Empty" : "Queue is not Empty") << endl;
                break;
            case 4:
                cout << (q1.isFull() ? "Queue is Full" : "Queue is not Full") << endl;
                break;
            case 5:
                cout << "Count Operation\nCount of items in Queue: " << q1.count() << endl;
                break;
            case 6:
                cout << "Display Function Called - " << endl;
                q1.display();
                break;
            default:
                cout << "Enter Proper Option Number" << endl;
        }
    } while (option != 0);

    return 0;
}
