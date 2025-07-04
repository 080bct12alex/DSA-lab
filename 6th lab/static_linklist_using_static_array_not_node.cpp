#include <iostream>
using namespace std;

#define MAX 100  // Maximum size of the static list

class StaticList {
private:
    int arr[MAX];
    int size;

public:
    StaticList() {
        size = 0;
    }

    // a. Insert at beginning
    void insertAtBeginning(int data) {
        if (size >= MAX) {
            cout << "List is full!" << endl;
            return;
        }
        for (int i = size; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = data;
        size++;
    }

    // b. Insert at end
    void insertAtEnd(int data) {
        if (size >= MAX) {
            cout << "List is full!" << endl;
            return;
        }
        arr[size++] = data;
    }

    // c. Insert after a specific element
    void insertAfterElement(int element, int data) {
        if (size >= MAX) {
            cout << "List is full!" << endl;
            return;
        }

        int pos = -1;
        for (int i = 0; i < size; i++) {
            if (arr[i] == element) {
                pos = i;
                break;
            }
        }

        if (pos == -1) {
            cout << "Element not found!" << endl;
            return;
        }

        for (int i = size; i > pos + 1; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos + 1] = data;
        size++;
    }

    // d. Delete from beginning
    void deleteFromBeginning() {
        if (size == 0) {
            cout << "List is empty!" << endl;
            return;
        }

        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    // e. Delete from end
    void deleteFromEnd() {
        if (size == 0) {
            cout << "List is empty!" << endl;
            return;
        }

        size--;
    }

    // f. Delete after a specific element
    void deleteAfterElement(int element) {
        if (size == 0) {
            cout << "List is empty!" << endl;
            return;
        }

        int pos = -1;
        for (int i = 0; i < size - 1; i++) {
            if (arr[i] == element) {
                pos = i;
                break;
            }
        }

        if (pos == -1 || pos + 1 >= size) {
            cout << "Element not found or no element to delete after it!" << endl;
            return;
        }

        for (int i = pos + 1; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    void printList() {
        if (size == 0) {
            cout << "List is empty!" << endl;
            return;
        }

        cout << "List: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Main program
int main() {
    StaticList list;
    int choice, data, element;

    do {
        cout << "\n--- Choose the operation you want to perform ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert after Specific Element\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete after Specific Element\n";
        cout << "7. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter data to insert at beginning: ";
            cin >> data;
            list.insertAtBeginning(data);
            break;
        case 2:
            cout << "Enter data to insert at end: ";
            cin >> data;
            list.insertAtEnd(data);
            break;
        case 3:
            cout << "Enter element after which to insert: ";
            cin >> element;
            cout << "Enter data to insert: ";
            cin >> data;
            list.insertAfterElement(element, data);
            break;
        case 4:
            list.deleteFromBeginning();
            break;
        case 5:
            list.deleteFromEnd();
            break;
        case 6:
            cout << "Enter element after which to delete: ";
            cin >> element;
            list.deleteAfterElement(element);
            break;
        case 7:
            list.printList();
            break;
        case 0:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}