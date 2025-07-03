#include <iostream>
using namespace std;

#define MAX 5  // Maximum size of the static list    or define directly in arr[]

class staticList {
private:
    int arr[MAX];
    int size;

public:
    staticList() {
        size = 0;
    }

    void display() {
        cout << "List: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
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
        cout << "Inserted " << data << " at beginning." << endl;
        display();
    }

    // b. Insert at end
    void insertAtEnd(int data) {
        if (size >= MAX) {
            cout << "List is full!" << endl;
            return;
        }
        arr[size] = data;
        size++;
        cout << "Inserted " << data << " at end." << endl;
        display();
    }

    // c. Insert after specific element
    void insertAfterElement(int element, int data) {
        int index = -1;
        for (int i = 0; i < size; i++) {
            if (arr[i] == element) {
                index = i;
                break;
            }
        }
        if (index == -1 || size >= MAX) {
            cout << "Element not found or list is full!" << endl;
            return;
        }
        for (int i = size; i > index + 1; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index + 1] = data;
        size++;
        cout << "Inserted " << data << " after " << element << "." << endl;
        display();
    }

    // d. Delete from beginning
    void deleteFromBeginning() {
        if (size == 0) {
            cout << "List is empty!" << endl;
            return;
        }
        int removed = arr[0];
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        cout << "Deleted " << removed << " from beginning." << endl;
        display();
    }

    // e. Delete from end
    void deleteFromEnd() {
        if (size == 0) {
            cout << "List is empty!" << endl;
            return;
        }
        int removed = arr[size - 1];
        size--;
        cout << "Deleted " << removed << " from end." << endl;
        display();
    }

    // f. Delete after specific element
    void deleteAfterElement(int element) {
        int index = -1;
        for (int i = 0; i < size - 1; i++) {
            if (arr[i] == element) {
                index = i;
                break;
            }
        }
        if (index == -1 || index + 1 >= size) {
            cout << "Element not found or no element to delete after it!" << endl;
            return;
        }
        int removed = arr[index + 1];
        for (int i = index + 1; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        cout << "Deleted " << removed << " after " << element << "." << endl;
        display();
    }
};

int main() {
    staticList list;
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
            list.display();
            break;

        case 0:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 0);

    return 0;
}
