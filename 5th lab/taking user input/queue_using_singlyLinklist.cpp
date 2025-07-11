#include<iostream>
using namespace std;

class Node {
public:
    int key;
    int data;
    Node* next;

    Node() {
        key = 0;
        data = 0;
        next = NULL;
    }

    Node(int k, int d) {
        key = k;
        data = d;
        next = NULL;
    }
};

class Queue {
public:
    Node* front;
    Node* rear;

    Queue() {
        front = NULL;
        rear = NULL;
    }

    bool isEmpty() {
        return (front == NULL && rear == NULL);
    }

    bool checkIfNodeExist(Node* n) {
        Node* temp = front;
        while (temp != NULL) {
            if (temp->key == n->key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void enqueue(Node* n) {
        if (isEmpty()) {
            front = rear = n;
            cout << "Node ENQUEUED successfully" << endl;
        }
        else if (checkIfNodeExist(n)) {
            cout << "Node already exists with this Key value. Enter a different Key value." << endl;
        }
        else {
            rear->next = n;
            rear = n;
            cout << "Node ENQUEUED successfully" << endl;
        }
    }

    Node* dequeue() {
        Node* temp = NULL;
        if (isEmpty()) {
            cout << "Queue underflow" << endl;
            return NULL;
        }
        else if (front == rear) {
            temp = front;
            front = rear = NULL;
        }
        else {
            temp = front;
            front = front->next;
        }
        return temp;
    }

    int count() {
        int count = 0;
        Node* temp = front;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
        }
        else {
            cout << "All values in the Queue are: " << endl;
            Node* temp = front;
            while (temp != NULL) {
                cout << "(" << temp->key << ", " << temp->data << ") -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }
};

int main() {
    Queue q;
    int option, key, data;

    do {
        cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. Enqueue()" << endl;
        cout << "2. Dequeue()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. count()" << endl;
        cout << "5. display()" << endl;
        
        cin >> option;
        Node* new_node = new Node();

        switch (option) {
        case 0:
            break;

        case 1:
            cout << "ENQUEUE Function Called -" << endl;
            cout << "Enter KEY and VALUE of NODE to ENQUEUE in the Queue: ";
            cin >> key >> data;
            new_node->key = key;
            new_node->data = data;
            q.enqueue(new_node);
            break;

        case 2:
            cout << "DEQUEUE Function Called -" << endl;
            new_node = q.dequeue();
            if (new_node != NULL) {
                cout << "Dequeued Value is: (" << new_node->key << ", " << new_node->data << ")" << endl;
                delete new_node;
            }
            break;

        case 3:
            cout << "isEmpty Function Called - " << endl;
            if (q.isEmpty())
                cout << "Queue is Empty" << endl;
            else
                cout << "Queue is NOT Empty" << endl;
            break;

        case 4:
            cout << "Count Function Called - " << endl;
            cout << "No. of nodes in the Queue: " << q.count() << endl;
            break;

        case 5:
            cout << "Display Function Called - " << endl;
            q.display();
            break;

        
        default:
            cout << "Enter a Proper Option number!" << endl;
        }

    } while (option != 0);

    return 0;
}

