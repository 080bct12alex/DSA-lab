#include <iostream> //without comment
#include <cmath>
using namespace std;

class Node {
public:
    int coeff;
    int power;
    Node* next;

    Node(int c, int p) {
        coeff = c;
        power = p;
        next = NULL;
    }
};

class Polynomial {
public:
    Node* head;

    Polynomial() {
        head = NULL;
    }

    void insertTerm(int coeff, int power) {
        if (coeff == 0) return;

        Node* newNode = new Node(coeff, power);
        if (head == NULL || power > head->power) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            Node* prev = NULL;

            while (temp && temp->power > power) {
                prev = temp;
                temp = temp->next;
            }

            if (temp && temp->power == power) {
                temp->coeff += coeff;
                delete newNode;
                if (temp->coeff == 0) {
                    if (prev) prev->next = temp->next;
                    else head = temp->next;
                    delete temp;
                }
            } else {
                newNode->next = temp;
                if (prev) prev->next = newNode;
                else head = newNode;
            }
        }
    }

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

    void display() {
        if (!head) {
            cout << "0" << endl;
            return;
        }
        Node* temp = head;
        while (temp) {
            cout << temp->coeff << "x^" << temp->power;
            temp = temp->next;
            if (temp) cout << " + ";
        }
        cout << endl;
    }

    int evaluate(int x) {
        int result = 0;
        Node* temp = head;
        while (temp) {
            result += temp->coeff * pow(x, temp->power);
            temp = temp->next;
        }
        return result;
    }

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

// --- Menu Driver ---
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
            poly1 = Polynomial();  // reset
            poly1.createPolynomial();
            break;
        case 2:
            poly2 = Polynomial();  // reset
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
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}