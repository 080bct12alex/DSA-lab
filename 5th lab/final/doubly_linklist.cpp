#include <iostream>
using namespace std;

class Node {
public:
    int key;
    int data;
    Node* next;
    Node* previous;

    Node(int k, int d) {
        key = k;
        data = d;
        next = NULL;
        previous = NULL;
    }
};

class doublyLinkedList {
public:
    Node* head;

    doublyLinkedList() {
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

    void insertNodeAtBeginning(int key, int data) {
        if (nodeExists(key)) {
            cout << "Node already exists with key " << key << endl;
            return;
        }
        Node* n = new Node(key, data);
        if (head == NULL) {
            head = n;
        } else {
            head->previous = n;
            n->next = head;
            head = n;
        }
        cout << "Inserted at beginning: (" << key << "," << data << ")\n";
        printList();
    }

    void insertNodeAtEnd(int key, int data) {
        if (nodeExists(key)) {
            cout << "Node already exists with key " << key << endl;
            return;
        }
        Node* n = new Node(key, data);
        if (head == NULL) {
            head = n;
        } else {
            Node* ptr = head;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = n;
            n->previous = ptr;
        }
        cout << "Inserted at end: (" << key << "," << data << ")\n";
        printList();
    }

    void insertNodeAfter(int k, int key, int data) {
        Node* ptr = nodeExists(k);
        if (ptr == NULL) {
            cout << "No node exists with key " << k << endl;
            return;
        }
        if (nodeExists(key)) {
            cout << "Node already exists with key " << key << endl;
            return;
        }
        Node* n = new Node(key, data);
        Node* nextNode = ptr->next;
        ptr->next = n;
        n->previous = ptr;
        n->next = nextNode;
        if (nextNode != NULL)
            nextNode->previous = n;
        cout << "Inserted (" << key << "," << data << ") after key " << k << endl;
        printList();
    }

    void insertNodeBefore(int k, int key, int data) {
        Node* ptr = nodeExists(k);
        if (ptr == NULL) {
            cout << "No node exists with key " << k << endl;
            return;
        }
        if (nodeExists(key)) {
            cout << "Node already exists with key " << key << endl;
            return;
        }

        Node* n = new Node(key, data);
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

        cout << "Inserted (" << key << "," << data << ") before key " << k << endl;
        printList();
    }

    void deleteFromBeginning() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        int deletedKey = head->key;
        head = head->next;
        if (head != NULL)
            head->previous = NULL;
        cout << "Deleted from beginning: key " << deletedKey << endl;
        printList();
    }

    void deleteFromEnd() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        } else if (head->next == NULL) {
            cout << "Deleted from end: key " << head->key << endl;
            head = NULL;
        } else {
            Node* ptr = head;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->previous->next = NULL;
            cout << "Deleted from end: key " << ptr->key << endl;
        }
        printList();
    }

    void deleteNodeAfter(int k) {
        Node* ptr = nodeExists(k);
        if (ptr == NULL || ptr->next == NULL) {
            cout << "No node found after key " << k << endl;
            return;
        }

        Node* delNode = ptr->next;
        Node* nextNode = delNode->next;
        ptr->next = nextNode;
        if (nextNode != NULL)
            nextNode->previous = ptr;

        cout << "Deleted node after key " << k << ": key " << delNode->key << endl;
        printList();
    }

    void deleteNodeBefore(int k) {
        Node* ptr = nodeExists(k);
        if (ptr == NULL || ptr->previous == NULL) {
            cout << "No node exists before key " << k << endl;
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

        cout << "Deleted node before key " << k << ": key " << delNode->key << endl;
        printList();
    }

    void printList() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        cout << "List: ";
        Node* temp = head;
        while (temp != NULL) {
            cout << "(" << temp->key << "," << temp->data << ") <=> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    doublyLinkedList obj;

    obj.insertNodeAtBeginning(1, 10);
    obj.insertNodeAtBeginning(2, 20);
    obj.insertNodeAtEnd(3, 30);
    obj.insertNodeAfter(1, 4, 40);
    obj.insertNodeBefore(3, 5, 50);

    obj.deleteFromBeginning();
    obj.deleteFromEnd();
    obj.deleteNodeAfter(2);
    obj.deleteNodeBefore(3);

    return 0;
}
