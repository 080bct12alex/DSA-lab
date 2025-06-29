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

    void insertNodeAtEnd(Node* n) {
        if (nodeExists(n->key)) {
            cout << "Node already exists with key: " << n->key << endl;
            return;
        }
        if (head == NULL) {
            head = n;
            cout << "Node appended as head node." << endl;
        } else {
            Node* ptr = head;
            while (ptr->next != NULL) ptr = ptr->next;
            ptr->next = n;
            n->previous = ptr;
            cout << "Node insert at end (appended) ." << endl;
        }
    }

    void insertNodeAtBeginning(Node* n) {
        if (nodeExists(n->key)) {
            cout << "Node already exists with key: " << n->key << endl;
            return;
        }
        if (head == NULL) {
            head = n;
            cout << "Node prepended as head node." << endl;
        } else {
            head->previous = n;
            n->next = head;
            head = n;
            cout << "Node insert at beginning (prepended)." << endl;
        }
    }

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
        if (nextNode == NULL) {
            ptr->next = n;
            n->previous = ptr;
            cout << "Node inserted at end." << endl;
        } else {
            n->next = nextNode;
            nextNode->previous = n;
            n->previous = ptr;
            ptr->next = n;
            cout << "Node inserted in between." << endl;
        }
    }

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

    void insertNodeAtPosition(int position, Node* n) {
        if (position < 1) {
            cout << "Invalid position." << endl;
            return;
        }
        if (nodeExists(n->key)) {
            cout << "Node already exists with key: " << n->key << endl;
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
            if (nextNode != NULL)
                nextNode->previous = n;
            cout << "Node inserted at position " << position << "." << endl;
        }
    }

    // a. DELETE NODE FROM BEGINNING
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

    // b. DELETE NODE FROM END
    void deleteFromEnd() {
        if (head == NULL) {
            cout << "List is empty." << endl;
        } else if (head->next == NULL) {
            cout << "Node with key " << head->key << " deleted from end (only node)." << endl;
            head = NULL;
        } else {
            Node* ptr = head;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->previous->next = NULL;
            cout << "Node with key " << ptr->key << " deleted from end." << endl;
        }
    }

    // c. DELETE NODE AFTER SPECIFIC NODE
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

    // d. DELETE NODE FROM NTH POSITION
    void deleteNodeFromPosition(int position) {
        if (position < 1 || head == NULL) {
            cout << "Invalid position or list is empty." << endl;
            return;
        }

        if (position == 1) {
            deleteFromBeginning();
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
            Node* prev = ptr->previous;
            Node* next = ptr->next;
            prev->next = next;
            if (next != NULL)
                next->previous = prev;
            cout << "Node at position " << position << " deleted." << endl;
        }
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
    int option, key1, k1, data1, pos;

    do {
        cout << "\nWhat operation do you want to perform? Enter 0 to exit." << endl;
        cout << "1. Append Node" << endl;
        cout << "2. Prepend Node" << endl;
        cout << "3. Insert Node After" << endl;
        cout << "4. Print List" << endl;
        cout << "5. Insert Before Specific Node" << endl;
        cout << "6. Insert at Nth Position" << endl;

        // DELETE OPERATIONS IN YOUR ORDER
        cout << "7. a. Delete Node from Beginning of the List" << endl;
        cout << "8. b. Delete Node from End of the List" << endl;
        cout << "9. c. Delete Node After Specific Node" << endl;
        cout << "10. d. Delete Node from Nth Position of the List" << endl;

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
            obj.printList();
            break;

        case 5:
            cout << "Enter key to insert before: ";
            cin >> k1;
            cout << "Enter key and data of new node: ";
            cin >> key1 >> data1;
            n1->key = key1;
            n1->data = data1;
            obj.insertNodeBefore(k1, n1);
            break;

        case 6:
            cout << "Enter position to insert at: ";
            cin >> pos;
            cout << "Enter key and data of new node: ";
            cin >> key1 >> data1;
            n1->key = key1;
            n1->data = data1;
            obj.insertNodeAtPosition(pos, n1);
            break;

        case 7:
            obj.deleteFromBeginning();
            break;

        case 8:
            obj.deleteFromEnd();
            break;

        case 9:
            cout << "Enter key to delete after: ";
            cin >> k1;
            obj.deleteNodeAfter(k1);
            break;

        case 10:
            cout << "Enter position to delete node at: ";
            cin >> pos;
            obj.deleteNodeFromPosition(pos);
            break;

        default:
            cout << "Invalid option. Try again." << endl;
        }
    } while (option != 0);

    return 0;
