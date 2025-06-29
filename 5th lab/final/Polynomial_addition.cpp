#include <iostream>
using namespace std;

class Node {
public:
    int key;    // power of x
    int data;   // coefficient
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

class SinglyLinkedList {
public:
    Node* head;

    SinglyLinkedList() {
        head = NULL;
    }

    // Append node at the end
    void appendNode(Node* n) {
        if (head == NULL) {
            head = n;
        } else {
            Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = n;
        }
    }

    // Print polynomial
    void printPolynomial() {
        if (head == NULL) {
            cout << "0";
            return;
        }
        Node* temp = head;
        bool firstTerm = true;
        while (temp != NULL) {
            if (temp->data != 0) {
                if (!firstTerm && temp->data > 0) cout << " + ";
                else if (temp->data < 0) cout << " - ";

                int absCoeff = temp->data < 0 ? -temp->data : temp->data;
                if (absCoeff != 1 || temp->key == 0)
                    cout << absCoeff;
                if (temp->key > 0) {
                    cout << "x";
                    if (temp->key > 1)
                        cout << "^" << temp->key;
                }
                firstTerm = false;
            }
            temp = temp->next;
        }
        if (firstTerm) cout << "0"; // All coeff were zero
    }

    // Add two polynomials (this and other)
    static SinglyLinkedList addPolynomials(SinglyLinkedList& p1, SinglyLinkedList& p2) {
        SinglyLinkedList result;

        Node* ptr1 = p1.head;
        Node* ptr2 = p2.head;

        // We assume the polynomial linked lists are sorted by descending power.
        // If not sorted, sorting is needed before addition.

        while (ptr1 != NULL && ptr2 != NULL) {
            if (ptr1->key == ptr2->key) {
                int sumCoeff = ptr1->data + ptr2->data;
                if (sumCoeff != 0)
                    result.appendNode(new Node(ptr1->key, sumCoeff));
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            } else if (ptr1->key > ptr2->key) {
                result.appendNode(new Node(ptr1->key, ptr1->data));
                ptr1 = ptr1->next;
            } else {
                result.appendNode(new Node(ptr2->key, ptr2->data));
                ptr2 = ptr2->next;
            }
        }

        // Add remaining terms
        while (ptr1 != NULL) {
            result.appendNode(new Node(ptr1->key, ptr1->data));
            ptr1 = ptr1->next;
        }
        while (ptr2 != NULL) {
            result.appendNode(new Node(ptr2->key, ptr2->data));
            ptr2 = ptr2->next;
        }

        return result;
    }
};

// Helper function to create polynomial from user input
void createPolynomial(SinglyLinkedList& poly) {
    int n, power, coeff;
    cout << "Enter number of terms in polynomial: ";
    cin >> n;
    cout << "Enter terms in descending order of powers:\n";
    for (int i = 0; i < n; i++) {
        cout << "Power: ";
        cin >> power;
        cout << "Coefficient: ";
        cin >> coeff;
        poly.appendNode(new Node(power, coeff));
    }
}

int main() {
    SinglyLinkedList poly1, poly2, sum;

    cout << "Create first polynomial:\n";
    createPolynomial(poly1);

    cout << "\nCreate second polynomial:\n";
    createPolynomial(poly2);

    cout << "\nFirst Polynomial: ";
    poly1.printPolynomial();
    cout << endl;

    cout << "Second Polynomial: ";
    poly2.printPolynomial();
    cout << endl;

    sum = SinglyLinkedList::addPolynomials(poly1, poly2);

    cout << "Sum of Polynomials: ";
    sum.printPolynomial();
    cout << endl;

    return 0;
}
