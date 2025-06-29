#include <iostream>
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

class Stack {
public:
    Node* top;

    Stack() {
        top = NULL;
    }

    bool isEmpty() {
        return top == NULL;
    }

    bool checkIfNodeExist(Node* n) {
        Node* temp = top;
        while (temp != NULL) {
            if (temp->key == n->key) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void push(Node* n) {
        if (top == NULL) {
            top = n;
            cout << "Node PUSHED successfully." << endl;
        } else if (checkIfNodeExist(n)) {
            cout << "Node already exists with this Key value. Enter different Key value." << endl;
        } else {
            n->next = top;
            top = n;
            cout << "Node PUSHED successfully." << endl;
        }
    }

    Node* pop() {
        if (isEmpty()) {
            cout << "Stack underflow." << endl;
            return NULL;
        } else {
            Node* temp = top;
            top = top->next;
            return temp;
        }
    }

    Node* peek() {
        if (isEmpty()) {
            cout << "Stack is Empty." << endl;
            return NULL;
        } else {
            return top;
        }
    }

    int count() {
        int count = 0;
        Node* temp = top;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void display() {
        cout << "All values in the Stack are:" << endl;
        Node* temp = top;
        while (temp != NULL) {
            cout << "(" << temp->key << ", " << temp->data << ")" << endl;
            temp = temp->next;
        }
        cout << "Total no of Nodes in the Stack: " << count() << endl << endl;
    }
};

int main() {
    Stack s1;
    int option, key, data;

    do {
        cout << "\nWhat operation do you want to perform? "
             << "Select Option number. Enter 0 to exit." << endl;
        cout << "1. Push()" << endl;
        cout << "2. Pop()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. Peek()" << endl;
        cout << "5. Count()" << endl;
        cout << "6. Display()" << endl;
       
        cin >> option;
        Node* new_node = new Node();

        switch (option) {
            case 0:
                break;

            case 1:
                cout << "Enter KEY and VALUE of NODE to push in the stack:" << endl;
                cin >> key >> data;
                new_node->key = key;
                new_node->data = data;
                s1.push(new_node);
                break;

            case 2:
                new_node = s1.pop();
                if (new_node != NULL)
                    cout << "Popped Value: (" << new_node->key << ", " << new_node->data << ")" << endl;
                break;

            case 3:
                if (s1.isEmpty())
                    cout << "Stack is Empty" << endl;
                else
                    cout << "Stack is not Empty" << endl;
                break;

            case 4:
                new_node = s1.peek();
                if (new_node != NULL)
                    cout << "Top of Stack is: (" << new_node->key << ", " << new_node->data << ")" << endl;
                break;

            case 5:
                cout << "Count Function Called: " << s1.count() << " nodes in the stack." << endl;
                break;

            case 6:
                s1.display();
                break;

           
            default:
                cout << "Enter Proper Option number " << endl;
        }
    } while (option != 0);

    return 0;
}