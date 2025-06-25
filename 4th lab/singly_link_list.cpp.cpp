#include <iostream>
using namespace std;

// Node class
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

// Singly Linked List class
class SinglyLinkedList {
public:
    Node* head;

    SinglyLinkedList() {
        head = NULL;
    }

    Node* nodeExists(int k) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->key == k)
                return temp;
            temp = temp->next;
        }
        return NULL;
    }

    void appendNode(Node* n) {
        if (nodeExists(n->key)) {
            cout << "Node already exists with key " << n->key << endl;
            return;
        }
        if (head == NULL) {
            head = n;
        } else {
            Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = n;
        }
        cout << "Node Appended" << endl;
    }

    void prependNode(Node* n) {
        if (nodeExists(n->key)) {
            cout << "Node already exists with key " << n->key << endl;
            return;
        }
        n->next = head;
        head = n;
        cout << "Node Prepended" << endl;
    }

    void insertNodeAfter(int k, Node* n) {
        Node* ptr = nodeExists(k);
        if (ptr == NULL) {
            cout << "No node exists with key " << k << endl;
            return;
        }
        if (nodeExists(n->key)) {
            cout << "Node already exists with key " << n->key << endl;
            return;
        }
        n->next = ptr->next;
        ptr->next = n;
        cout << "Node Inserted After " << k << endl;
    }

    void insertNodeBefore(int k, Node* n) {
        if (nodeExists(n->key)) {
            cout << "Node already exists with key " << n->key << endl;
            return;
        }
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        if (head->key == k) {
            n->next = head;
            head = n;
            cout << "Node Inserted Before " << k << endl;
            return;
        }
        Node* prev = head;
        Node* curr = head->next;
        while (curr != NULL) {
            if (curr->key == k) {
                prev->next = n;
                n->next = curr;
                cout << "Node Inserted Before " << k << endl;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        cout << "Node with key " << k << " not found." << endl;
    }

    void insertNodeAtPosition(int pos, Node* n) {
        if (pos < 1) {
            cout << "Invalid position." << endl;
            return;
        }
        if (nodeExists(n->key)) {
            cout << "Node already exists with key " << n->key << endl;
            return;
        }
        if (pos == 1) {
            n->next = head;
            head = n;
            cout << "Node inserted at position 1" << endl;
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++)
            temp = temp->next;
        if (temp == NULL) {
            cout << "Position out of bounds." << endl;
            return;
        }
        n->next = temp->next;
        temp->next = n;
        cout << "Node inserted at position " << pos << endl;
    }

    void deleteFromBeginning() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        head = head->next;
        cout << "Node deleted from beginning" << endl;
    }

    void deleteFromEnd() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        if (head->next == NULL) {
            head = NULL;
            cout << "Last node deleted" << endl;
            return;
        }
        Node* prev = NULL;
        Node* curr = head;
        while (curr->next != NULL) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        cout << "Node deleted from end" << endl;
    }

    void deleteAfterNode(int k) {
        Node* ptr = nodeExists(k);
        if (ptr == NULL || ptr->next == NULL) {
            cout << "Cannot delete after key " << k << endl;
            return;
        }
        ptr->next = ptr->next->next;
        cout << "Node deleted after key " << k << endl;
    }

    void deleteFromPosition(int pos) {
        if (pos < 1 || head == NULL) {
            cout << "Invalid position or list is empty." << endl;
            return;
        }
        if (pos == 1) {
            head = head->next;
            cout << "Node deleted at position 1" << endl;
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++)
            temp = temp->next;
        if (temp == NULL || temp->next == NULL) {
            cout << "Position out of bounds." << endl;
            return;
        }
        temp->next = temp->next->next;
        cout << "Node deleted at position " << pos << endl;
    }

    void deleteNodeByKey(int k) {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        if (head->key == k) {
            head = head->next;
            cout << "Node with key " << k << " deleted" << endl;
            return;
        }
        Node* prev = head;
        Node* curr = head->next;
        while (curr != NULL) {
            if (curr->key == k) {
                prev->next = curr->next;
                cout << "Node with key " << k << " deleted" << endl;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        cout << "Node with key " << k << " not found" << endl;
    }

    void updateNodeByKey(int k, int d) {
        Node* ptr = nodeExists(k);
        if (ptr != NULL) {
            ptr->data = d;
            cout << "Node data updated" << endl;
        } else {
            cout << "Node not found" << endl;
        }
    }

    void printList() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != NULL) {
            cout << "(" << temp->key << "," << temp->data << ") → ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

// Main program
int main() {
    SinglyLinkedList s;
    int option, key1, k1, data1, pos;

    do {
        cout << "\nChoose an operation (0 to exit):\n";
        cout << "1. Append Node at End\n";
        cout << "2. Prepend Node at Beginning\n";
        cout << "3. Insert Node After a Given Node\n";
        cout << "4. Insert Node Before a Given Node\n";
        cout << "5. Insert Node at Nth Position\n";
        cout << "6. Delete Node by Key\n";
        cout << "7. Delete Node from Beginning\n";
        cout << "8. Delete Node from End\n";
        cout << "9. Delete Node After a Given Node\n";
        cout << "10. Delete Node from Nth Position\n";
        cout << "11. Update Node by Key\n";
        cout << "12. Print Linked List\n";
        cin >> option;

        Node* n1 = new Node();

        switch (option) {
        case 0:
            break;
        case 1:
            cout << "Enter key & data: ";
            cin >> key1 >> data1;
            n1->key = key1;
            n1->data = data1;
            s.appendNode(n1);
            break;
        case 2:
            cout << "Enter key & data: ";
            cin >> key1 >> data1;
            n1->key = key1;
            n1->data = data1;
            s.prependNode(n1);
            break;
        case 3:
            cout << "Enter key of existing node: ";
            cin >> k1;
            cout << "Enter key & data of new node: ";
            cin >> key1 >> data1;
            n1->key = key1;
            n1->data = data1;
            s.insertNodeAfter(k1, n1);
            break;
        case 4:
            cout << "Enter key of node to insert before: ";
            cin >> k1;
            cout << "Enter key & data of new node: ";
            cin >> key1 >> data1;
            n1->key = key1;
            n1->data = data1;
            s.insertNodeBefore(k1, n1);
            break;
        case 5:
            cout << "Enter position (1-based): ";
            cin >> pos;
            cout << "Enter key & data of new node: ";
            cin >> key1 >> data1;
            n1->key = key1;
            n1->data = data1;
            s.insertNodeAtPosition(pos, n1);
            break;
        case 6:
            cout << "Enter key of node to delete: ";
            cin >> k1;
            s.deleteNodeByKey(k1);
            break;
        case 7:
            s.deleteFromBeginning();
            break;
        case 8:
            s.deleteFromEnd();
            break;
        case 9:
            cout << "Enter key after which to delete: ";
            cin >> k1;
            s.deleteAfterNode(k1);
            break;
        case 10:
            cout << "Enter position to delete from: ";
            cin >> pos;
            s.deleteFromPosition(pos);
            break;
        case 11:
            cout << "Enter key & new data: ";
            cin >> key1 >> data1;
            s.updateNodeByKey(key1, data1);
            break;
        case 12:
            s.printList();
            break;
        
        default:
            cout << "Invalid option." << endl;
        }

    } while (option != 0);

    return 0;
}
