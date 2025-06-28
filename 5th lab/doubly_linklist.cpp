#include <iostream>
using namespace std;

class Node {
public:
    int key;
    int data;
    Node* next;
    Node* previous;

    Node() {
        key = 0;
        data = 0;
        next = NULL;
        previous = NULL;
    }

    Node(int k, int d) {
        key = k;
        data = d;
        next = NULL;
        previous = NULL;
    }
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() {
        head = NULL;
    }

    Node* nodeExists(int k) {
        Node* temp = NULL;
        Node* ptr = head;
        while (ptr != NULL) {
            if (ptr->key == k) {
                temp = ptr;
                break;
            }
            ptr = ptr->next;
        }
        return temp;
    }

    void appendNode(Node* n) {
        if (nodeExists(n->key) != NULL) {
            cout << "Node already exists with key value: " << n->key << endl;
        } else {
            if (head == NULL) {
                head = n;
                cout << "Node appended as head node." << endl;
            } else {
                Node* ptr = head;
                while (ptr->next != NULL) {
                    ptr = ptr->next;
                }
                ptr->next = n;
                n->previous = ptr;
                cout << "Node appended." << endl;
            }
        }
    }

    void prependNode(Node* n) {
        if (nodeExists(n->key) != NULL) {
            cout << "Node already exists with key value: " << n->key << endl;
        } else {
            if (head == NULL) {
                head = n;
                cout << "Node prepended as head node." << endl;
            } else {
                head->previous = n;
                n->next = head;
                head = n;
                cout << "Node prepended." << endl;
            }
        }
    }

    void insertNodeAfter(int k, Node* n) {
        Node* ptr = nodeExists(k);
        if (ptr == NULL) {
            cout << "No node exists with key value: " << k << endl;
        } else {
            if (nodeExists(n->key) != NULL) {
                cout << "Node already exists with key value: " << n->key << endl;
            } else {
                Node* nextNode = ptr->next;
                if (nextNode == NULL) {
                    ptr->next = n;
                    n->previous = ptr;
                    cout << "Node inserted at the end." << endl;
                } else {
                    n->next = nextNode;
                    nextNode->previous = n;
                    n->previous = ptr;
                    ptr->next = n;
                    cout << "Node inserted in between." << endl;
                }
            }
        }
    }

    void insertNodeBefore(int k, Node* n) {
        Node* ptr = nodeExists(k);
        if (ptr == NULL) {
            cout << "No node exists with key value: " << k << endl;
        } else {
            if (nodeExists(n->key) != NULL) {
                cout << "Node already exists with key value: " << n->key << endl;
            } else {
                Node* prevNode = ptr->previous;
                if (prevNode == NULL) {
                    n->next = head;
                    head->previous = n;
                    head = n;
                } else {
                    prevNode->next = n;
                    n->previous = prevNode;
                    n->next = ptr;
                    ptr->previous = n;
                }
                cout << "Node inserted before key " << k << "." << endl;
            }
        }
    }

    void insertNodeAtPosition(int position, Node* n) {
        if (position < 1) {
            cout << "Invalid position." << endl;
            return;
        }

        if (nodeExists(n->key) != NULL) {
            cout << "Node already exists with key value: " << n->key << endl;
            return;
        }

        if (position == 1) {
            prependNode(n);
            return;
        }

        Node* ptr = head;
        int count = 1;
        while (ptr != NULL && count < position - 1) {
            ptr = ptr->next;
            count++;
        }

        if (ptr == NULL) {
            cout << "Position out of bounds." << endl;
        } else {
            Node* nextNode = ptr->next;
            ptr->next = n;
            n->previous = ptr;
            n->next = nextNode;
            if (nextNode != NULL) {
                nextNode->previous = n;
            }
            cout << "Node inserted at position " << position << "." << endl;
        }
    }

    void deleteNodeByKey(int k) {
        Node* ptr = nodeExists(k);
        if (ptr == NULL) {
            cout << "No node exists with key value: " << k << endl;
        } else {
            if (ptr == head) {
                head = head->next;
                if (head != NULL) {
                    head->previous = NULL;
                }
                cout << "Head node deleted." << endl;
            } else {
                Node* prevNode = ptr->previous;
                Node* nextNode = ptr->next;

                if (nextNode == NULL) {
                    prevNode->next = NULL;
                    cout << "Node deleted at the end." << endl;
                } else {
                    prevNode->next = nextNode;
                    nextNode->previous = prevNode;
                    cout << "Node deleted in between." << endl;
                }
            }
        }
    }

    void deleteNodeAfter(int k) {
        Node* ptr = nodeExists(k);
        if (ptr == NULL) {
            cout << "No node exists with key value: " << k << endl;
        } else {
            Node* delNode = ptr->next;
            if (delNode == NULL) {
                cout << "No node exists after key value: " << k << endl;
            } else {
                Node* nextNode = delNode->next;
                ptr->next = nextNode;
                if (nextNode != NULL) {
                    nextNode->previous = ptr;
                }
                cout << "Node after key " << k << " deleted." << endl;
            }
        }
    }

    void deleteNodeAtPosition(int position) {
        if (position < 1) {
            cout << "Invalid position." << endl;
            return;
        }

        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        if (position == 1) {
            deleteNodeByKey(head->key);
            return;
        }

        Node* ptr = head;
        int count = 1;
        while (ptr != NULL && count < position) {
            ptr = ptr->next;
            count++;
        }

        if (ptr == NULL) {
            cout << "Position out of bounds." << endl;
        } else {
            deleteNodeByKey(ptr->key);
        }
    }

    void updateNodeByKey(int k, int d) {
        Node* ptr = nodeExists(k);
        if (ptr != NULL) {
            ptr->data = d;
            cout << "Node data updated successfully." << endl;
        } else {
            cout << "Node doesn't exist with key value: " << k << endl;
        }
    }

    void printList() {
        if (head == NULL) {
            cout << "No nodes in the doubly linked list." << endl;
        } else {
            cout << "Doubly Linked List values: " << endl;
            Node* temp = head;
            while (temp != NULL) {
                cout << "(" << temp->key << "," << temp->data << ") <==> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }
};

int main() {
    DoublyLinkedList obj;
    int option;
    int key1, k1, data1, pos;

    do {
        cout << "\nWhat operation do you want to perform? Enter 0 to exit." << endl;
        cout << "1. Append Node" << endl;
        cout << "2. Prepend Node" << endl;
        cout << "3. Insert Node After" << endl;
        cout << "4. Delete Node By Key" << endl;
        cout << "5. Update Node By Key" << endl;
        cout << "6. Print List" << endl;
        cout << "7. Clear Screen" << endl;
        cout << "8. Insert Before Specific Node" << endl;
        cout << "9. Insert at Nth Position" << endl;
        cout << "10. Delete After Specific Node" << endl;
        cout << "11. Delete at Nth Position" << endl;

        cin >> option;
        Node* n1 = new Node();

        switch (option) {
        case 0:
            break;

        case 1:
            cout << "Enter key and data: ";
            cin >> key1 >> data1;
            n1->key = key1;
            n1->data = data1;
            obj.appendNode(n1);
            break;

        case 2:
            cout << "Enter key and data: ";
            cin >> key1 >> data1;
            n1->key = key1;
            n1->data = data1;
            obj.prependNode(n1);
            break;

        case 3:
            cout << "Enter key of existing node: ";
            cin >> k1;
            cout << "Enter key and data of new node: ";
            cin >> key1 >> data1;
            n1->key = key1;
            n1->data = data1;
            obj.insertNodeAfter(k1, n1);
            break;

        case 4:
            cout << "Enter key of node to delete: ";
            cin >> k1;
            obj.deleteNodeByKey(k1);
            break;

        case 5:
            cout << "Enter key and new data: ";
            cin >> key1 >> data1;
            obj.updateNodeByKey(key1, data1);
            break;

        case 6:
            obj.printList();
            break;

        case 7:
            system("cls"); // Use "clear" if on Linux/Mac
            break;

        case 8:
            cout << "Enter key of node to insert before: ";
            cin >> k1;
            cout << "Enter key and data of new node: ";
            cin >> key1 >> data1;
            n1->key = key1;
            n1->data = data1;
            obj.insertNodeBefore(k1, n1);
            break;

        case 9:
            cout << "Enter position to insert at: ";
            cin >> pos;
            cout << "Enter key and data of new node: ";
            cin >> key1 >> data1;
            n1->key = key1;
            n1->data = data1;
            obj.insertNodeAtPosition(pos, n1);
            break;

        case 10:
            cout << "Enter key to delete node after: ";
            cin >> k1;
            obj.deleteNodeAfter(k1);
            break;

        case 11:
            cout << "Enter position to delete node at: ";
            cin >> pos;
            obj.deleteNodeAtPosition(pos);
            break;

        default:
            cout << "Invalid option. Please try again." << endl;
        }

    } while (option != 0);

    return 0;
}