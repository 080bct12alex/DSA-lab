//have comment
#include <iostream>
#include <cmath> // for pow()
using namespace std;

// Node class represents one term in the polynomial (like 3x^2)
class Node {
public:
    int coeff;  // coefficient (e.g., 3)
    int power;  // power of x (e.g., 2)
    Node* next; // pointer to next term

    // Constructor to initialize node
    Node(int c, int p) {
        coeff = c;
        power = p;
        next = NULL;
    }
};

// Polynomial class contains linked list and operations
class Polynomial {
public:
    Node* head;

    Polynomial() {
        head = NULL; // initially empty polynomial
    }

    // Insert a term into the polynomial in decreasing order of power
    void insertTerm(int coeff, int power) {
        if (coeff == 0) return; // skip 0 terms

        Node* newNode = new Node(coeff, power);

        // Insert at head if list is empty or new power is greater
        if (head == NULL || power > head->power) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            Node* prev = NULL;

            // Traverse to correct position
            while (temp && temp->power > power) {
                prev = temp;
                temp = temp->next;
            }

            // If same power, just add the coefficients
            if (temp && temp->power == power) {
                temp->coeff += coeff;
                delete newNode; // we don’t need new node
                // If result is 0, remove node
                if (temp->coeff == 0) {
                    if (prev) prev->next = temp->next;
                    else head = temp->next;
                    delete temp;
                }
            } else {
                // Insert the term in correct position
                newNode->next = temp;
                if (prev) prev->next = newNode;
                else head = newNode;
            }
        }
    }

    // Create polynomial by user input
    void createPolynomial() {
        int n;
        cout << "Enter number of terms: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            int coeff, power;
            cout << "Enter coefficient and power of term " << i + 1 << ": ";
            cin >> coeff >> power;
            insertTerm(coeff, power);
        }
    }

    // Display polynomial nicely
    void display() {
        if (!head) {
            cout << "0" << endl;
            return;
        }

        Node* temp = head;
        while (temp) {
            cout << temp->coeff << "x^" << temp->power;
            if (temp->next) cout << " + ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Evaluate the polynomial for a given x
    int evaluate(int x) {
        int result = 0;
        Node* temp = head;

        while (temp) {
            result += temp->coeff * pow(x, temp->power);
            temp = temp->next;
        }

        return result;
    }

    // Add two polynomials and return result
    static Polynomial add(Polynomial& p1, Polynomial& p2) {
        Polynomial result;
        Node* a = p1.head;
        Node* b = p2.head;

        while (a || b) {
            if (!b || (a && a->power > b->power)) {
                result.insertTerm(a->coeff, a->power);
                a = a->next;
            } else if (!a || (b && b->power > a->power)) {
                result.insertTerm(b->coeff, b->power);
                b = b->next;
            } else {
                result.insertTerm(a->coeff + b->coeff, a->power);
                a = a->next;
                b = b->next;
            }
        }
        return result;
    }

    // Subtract p2 from p1
    static Polynomial subtract(Polynomial& p1, Polynomial& p2) {
        Polynomial result;
        Node* a = p1.head;
        Node* b = p2.head;

        while (a || b) {
            if (!b || (a && a->power > b->power)) {
                result.insertTerm(a->coeff, a->power);
                a = a->next;
            } else if (!a || (b && b->power > a->power)) {
                result.insertTerm(-b->coeff, b->power);
                b = b->next;
            } else {
                result.insertTerm(a->coeff - b->coeff, a->power);
                a = a->next;
                b = b->next;
            }
        }
        return result;
    }

    // Multiply two polynomials
    static Polynomial multiply(Polynomial& p1, Polynomial& p2) {
        Polynomial result;

        for (Node* a = p1.head; a; a = a->next) {
            for (Node* b = p2.head; b; b = b->next) {
                result.insertTerm(a->coeff * b->coeff, a->power + b->power);
            }
        }
        return result;
    }
};

// --- Main Menu Program ---
int main() {
    Polynomial poly1, poly2, result;
    int choice;

    while (true) {
        cout << "\n--- Polynomial Menu ---\n";
        cout << "1. Create Polynomial 1\n";
        cout << "2. Create Polynomial 2\n";
        cout << "3. Display Polynomial 1\n";
        cout << "4. Display Polynomial 2\n";
        cout << "5. Add Polynomials\n";
        cout << "6. Subtract Polynomials (P1 - P2)\n";
        cout << "7. Multiply Polynomials\n";
        cout << "8. Evaluate Polynomial 1\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            poly1 = Polynomial(); // reset poly1
            poly1.createPolynomial();
            break;
        case 2:
            poly2 = Polynomial(); // reset poly2
            poly2.createPolynomial();
            break;
        case 3:
            cout << "Polynomial 1: ";
            poly1.display();
            break;
        case 4:
            cout << "Polynomial 2: ";
            poly2.display();
            break;
        case 5:
            result = Polynomial::add(poly1, poly2);
            cout << "Sum: ";
            result.display();
            break;
        case 6:
            result = Polynomial::subtract(poly1, poly2);
            cout << "Difference (P1 - P2): ";
            result.display();
            break;
        case 7:
            result = Polynomial::multiply(poly1, poly2);
            cout << "Product: ";
            result.display();
            break;
        case 8:
            int x;
            cout << "Enter value of x: ";
            cin >> x;
            cout << "Result: " << poly1.evaluate(x) << endl;
            break;
        case 9:
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}