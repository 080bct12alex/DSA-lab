 
 
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
    Stack s;

    s.push(new Node(1, 10));

    s.display();

    Node* poppedNode = s.pop();
   
    cout << "Popped node: (" << poppedNode->key << ", " << poppedNode->data << ")" << endl;
    

    s.display();

    return 0;
}
