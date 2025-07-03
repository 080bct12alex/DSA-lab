#include <iostream>
using namespace std;

class Node {
public:
    int key, data;
    Node* next;

    Node(int k, int d) {
        key = k;
        data = d;
        next = NULL;
    }
};

class Queue {
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = NULL;
    }

    void enqueue(int key, int data) {
        Node* n = new Node(key, data);
        if (rear == NULL) {
            front = rear = n;
        } else {
            rear->next = n;
            rear = n;
        }
        cout << "Enqueued: (" << key << ", " << data << ")\n";
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == NULL) rear = NULL;
        cout << "Dequeued: (" << temp->key << ", " << temp->data << ")\n";
        delete temp;
    }

    void display() {
        if (front == NULL) {
            cout << "Queue is empty\n";
            return;
        }
        Node* temp = front;
        cout << "Queue: ";
        while (temp != NULL) {
            cout << "(" << temp->key << ", " << temp->data << ") -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    Queue q;


    q.enqueue(1, 10);
    q.enqueue(2, 20);
    q.enqueue(3, 30);

    q.display();


    q.dequeue();
    q.display();

    return 0;
}
