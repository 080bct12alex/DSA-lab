//simple or normal + special   CircularQueue
#include <iostream>
using namespace std;


class CircularDeque {
private:
    int front;
    int rear;
    int arr[5];
    int itemCount;

public:
    CircularDeque() {
        itemCount = 0;
        front = -1;
        rear = -1;
        for (int i = 0; i < 5; i++)
            arr[i] = 0;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return ((rear + 1) % 5 == front);
    }

    void enqueueRear(int val) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        } else if (isEmpty()) {
            rear = front = 0;
        } else {
            rear = (rear + 1) % 5;
        }
        arr[rear] = val;
        itemCount++;
    }

    void enqueueFront(int val) {     //special
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        } else if (isEmpty()) {
            front = rear = 0;
        } else {
            front = (front - 1 + 5) % 5; // Wrap around
        }
        arr[front] = val;
        itemCount++;
    }

    int dequeueFront() {    
        int x = 0;
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return x;
        } else if (rear == front) {
            x = arr[front];
            arr[front] = 0;
            rear = front = -1;
        } else {
            x = arr[front];
            arr[front] = 0;
            front = (front + 1) % 5;
        }
        itemCount--;
        return x;
    }

    int dequeueRear() {      //special
        int x = 0;
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return x;
        } else if (rear == front) {
            x = arr[rear];
            arr[rear] = 0;
            front = rear = -1;
        } else {
            x = arr[rear];
            arr[rear] = 0;
            rear = (rear - 1 + 5) % 5; // Wrap around
        }
        itemCount--;
        return x;
    }

    int count() {
        return itemCount;
    }

    void display() {
        cout << "All values in the Deque are: ";
        for (int i = 0; i < 5; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};




int main() {
    CircularDeque q1;
    int value, option;

    do {
        cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. Enqueue at REAR" << endl;
        cout << "2. Dequeue from FRONT" << endl;
        cout << "3. Enqueue at FRONT" << endl;
        cout << "4. Dequeue from REAR" << endl;
        cout << "5. isEmpty()" << endl;
        cout << "6. isFull()" << endl;
        cout << "7. count()" << endl;
        cout << "8. display()" << endl;

        cin >> option;

        switch (option) {
            case 0:
                break;
            case 1:
                cout << "Enter an item to enqueue at REAR: ";
                cin >> value;
                q1.enqueueRear(value);
                break;
            case 2:
                cout << "Dequeued from FRONT: " << q1.dequeueFront() << endl;
                break;
            case 3:
                cout << "Enter an item to enqueue at FRONT: ";
                cin >> value;
                q1.enqueueFront(value);
                break;
            case 4:
                cout << "Dequeued from REAR: " << q1.dequeueRear() << endl;
                break;
            case 5:
                cout << (q1.isEmpty() ? "Queue is Empty" : "Queue is not Empty") << endl;
                break;
            case 6:
                cout << (q1.isFull() ? "Queue is Full" : "Queue is not Full") << endl;
                break;
            case 7:
                cout << "Count of items in Queue: " << q1.count() << endl;
                break;
            case 8:
                q1.display();
                break;
            default:
                cout << "Enter Proper Option Number" << endl;
        }

    } while (option != 0);

    return 0;
}
