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
        Node* ptr = head;
        while (ptr != NULL) {
            if (ptr->key == k)
                return ptr;
            ptr = ptr->next;
        }
        return NULL;
    }

    // a. INSERT NODE AT BEGINNING
    void insertNodeAtBeginning(Node* n) {
        if (nodeExists(n->key)) {
            cout << "Node already exists with key: " << n->key << endl;
            return;
        }
        if (head == NULL) {
            head = n;
        } else {
            head->previous = n;
            n->next = head;
            head = n;
        }
        cout << "Node inserted at beginning." << endl;
    }

    // b. INSERT NODE AT END
    void insertNodeAtEnd(Node* n) {
        if (nodeExists(n->key)) {
            cout << "Node already exists with key: " << n->key << endl;
            return;
        }
        if (head == NULL) {
            head = n;
        } else {
            Node* ptr = head;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = n;
            n->previous = ptr;
        }
        cout << "Node inserted at end." << endl;
    }

    // c. INSERT NODE AFTER SPECIFIC NODE
    void insertNodeAfter(int k, Node* n) {
        Node* ptr = nodeExists(k);
        if (ptr == NULL) {
            cout << "No node exists with key: " << k << endl;
            return;
        }
        if (nodeExists(n->key)) {
            cout << "Node already exists with key: " << n->key << endl;
            return;
        }

        Node* nextNode = ptr->next;
        ptr->next = n;
        n->previous = ptr;
        n->next = nextNode;
        if (nextNode != NULL)
            nextNode->previous = n;

        cout << "Node inserted after key " << k << "." << endl;
    }

    // d. INSERT NODE BEFORE SPECIFIC NODE
    void insertNodeBefore(int k, Node* n) {
        Node* ptr = nodeExists(k);
        if (ptr == NULL) {
            cout << "No node exists with key: " << k << endl;
            return;
        }
        if (nodeExists(n->key)) {
            cout << "Node already exists with key: " << n->key << endl;
            return;
        }

        Node* prevNode = ptr->previous;
        n->next = ptr;
        ptr->previous = n;

        if (prevNode == NULL) {
            n->previous = NULL;
            head = n;
        } else {
            prevNode->next = n;
            n->previous = prevNode;
        }

        cout << "Node inserted before key " << k << "." << endl;
    }

    // e. DELETE NODE FROM BEGINNING
    void deleteFromBeginning() {
        if (head == NULL) {
            cout << "List is empty." << endl;
        } else {
            int deletedKey = head->key;
            head = head->next;
            if (head != NULL)
                head->previous = NULL;
            cout << "Node with key " << deletedKey << " deleted from beginning." << endl;
        }
    }

    // f. DELETE NODE FROM END
    void deleteFromEnd() {
        if (head == NULL) {
            cout << "List is empty." << endl;
        } else if (head->next == NULL) {
            cout << "Node with key " << head->key << " deleted from end." << endl;
            head = NULL;
        } else {
            Node* ptr = head;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->previous->next = NULL;
            cout << "Node with key " << ptr->key << " deleted from end." << endl;
        }
    }

    // g. DELETE NODE AFTER SPECIFIC NODE
    void deleteNodeAfter(int k) {
        Node* ptr = nodeExists(k);
        if (ptr == NULL || ptr->next == NULL) {
            cout << "No node found after key " << k << "." << endl;
            return;
        }

        Node* delNode = ptr->next;
        Node* nextNode = delNode->next;
        ptr->next = nextNode;
        if (nextNode != NULL)
            nextNode->previous = ptr;
        cout << "Node after key " << k << " deleted." << endl;
    }

    // h. DELETE NODE BEFORE SPECIFIC NODE
    void deleteNodeBefore(int k) {
        Node* ptr = nodeExists(k);
        if (ptr == NULL || ptr->previous == NULL) {
            cout << "No node exists before key " << k << "." << endl;
            return;
        }

        Node* delNode = ptr->previous;
        Node* prevNode = delNode->previous;

        if (prevNode == NULL) {
            ptr->previous = NULL;
            head = ptr;
        } else {
            prevNode->next = ptr;
            ptr->previous = prevNode;
        }

        cout << "Node before key " << k << " deleted." << endl;
    }

    void printList() {
        if (head == NULL) {
            cout << "List is empty." << endl;
        } else {
            cout << "Doubly Linked List: ";
            Node* temp = head;
            while (temp != NULL) {
                cout << "(" << temp->key << "," << temp->data << ") <=> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }
};

int main() {
    DoublyLinkedList obj;
    int option, key1, k1, data1;
    Node* n1 = nullptr;

    do {
        cout << "\nWhat operation do you want to perform? Enter 0 to exit." << endl;
        cout << "1. Insert Node at Beginning" << endl;
        cout << "2. Insert Node at End" << endl;
        cout << "3. Insert Node After Specific Node" << endl;
        cout << "4. Insert Node Before Specific Node" << endl;
        cout << "5. Delete Node from Beginning" << endl;
        cout << "6. Delete Node from End" << endl;
        cout << "7. Delete Node After Specific Node" << endl;
        cout << "8. Delete Node Before Specific Node" << endl;
        cout << "9. Print List" << endl;

        cin >> option;

        switch (option) {
        case 0:
            break;

        case 1:
            n1 = new Node();
            cout << "Enter key and data: ";
            cin >> key1 >> data1;
            n1->key = key1;
            n1->data = data1;
            obj.insertNodeAtBeginning(n1);
            break;

        case 2:
            n1 = new Node();
            cout << "Enter key and data: ";
            cin >> key1 >> data1;
            n1->key = key1;
            n1->data = data1;
            obj.insertNodeAtEnd(n1);
            break;

        case 3:
            n1 = new Node();
            cout << "Enter key of existing node: ";
            cin >> k1;
            cout << "Enter key and data of new node: ";
            cin >> key1 >> data1;
            n1->key = key1;
            n1->data = data1;
            obj.insertNodeAfter(k1, n1);
            break;

        case 4:
            n1 = new Node();
            cout << "Enter key to insert before: ";
            cin >> k1;
            cout << "Enter key and data of new node: ";
            cin >> key1 >> data1;
            n1->key = key1;
            n1->data = data1;
            obj.insertNodeBefore(k1, n1);
            break;

        case 5:
            obj.deleteFromBeginning();
            break;

        case 6:
            obj.deleteFromEnd();
            break;

        case 7:
            cout << "Enter key to delete after: ";
            cin >> k1;
            obj.deleteNodeAfter(k1);
            break;

        case 8:
            cout << "Enter key to delete before: ";
            cin >> k1;
            obj.deleteNodeBefore(k1);
            break;

        case 9:
            obj.printList();
            break;

        default:
            cout << "Invalid option. Try again." << endl;
        }

    } while (option != 0);

    return 0;
}
