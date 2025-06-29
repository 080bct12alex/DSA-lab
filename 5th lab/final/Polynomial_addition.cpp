#include <iostream>
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

    // Insert term in descending order of power
    void insertTerm(int coeff, int power) {
        if (coeff == 0) return;

        Node* newNode = new Node(coeff, power);

        if (head == NULL || power > head->power) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            Node* prev = NULL;

            while (temp != NULL && temp->power > power) {
                prev = temp;
                temp = temp->next;
            }

            if (temp != NULL && temp->power == power) {
                temp->coeff += coeff;
                delete newNode;

                if (temp->coeff == 0) {
                    if (prev)
                        prev->next = temp->next;
                    else
                        head = temp->next;
                    delete temp;
                }
            } else {
                newNode->next = temp;
                if (prev)
                    prev->next = newNode;
                else
                    head = newNode;
            }
        }
    }

    void display() {
        if (!head) {
            cout << "0\n";
            return;
        }

        Node* temp = head;
        while (temp != NULL) {
            cout << temp->coeff << "x^" << temp->power;
            if (temp->next) cout << " + ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Add two polynomials
    static Polynomial add(Polynomial& p1, Polynomial& p2) {
        Polynomial result;
        Node* a = p1.head;
        Node* b = p2.head;

        while (a != NULL || b != NULL) {
            if (a == NULL) {
                result.insertTerm(b->coeff, b->power);
                b = b->next;
            } else if (b == NULL) {
                result.insertTerm(a->coeff, a->power);
                a = a->next;
            } else if (a->power == b->power) {
                result.insertTerm(a->coeff + b->coeff, a->power);
                a = a->next;
                b = b->next;
            } else if (a->power > b->power) {
                result.insertTerm(a->coeff, a->power);
                a = a->next;
            } else {
                result.insertTerm(b->coeff, b->power);
                b = b->next;
            }
        }

        return result;
    }
};

// ---------- Main Function ----------
int main() {
    Polynomial p1, p2;

    int n1, n2;
    cout << "Enter number of terms for first polynomial: ";
    cin >> n1;

    for (int i = 0; i < n1; i++) {
        int coeff, power;
        cout << "Enter coefficient and power for term " << i + 1 << ": ";
        cin >> coeff >> power;
        p1.insertTerm(coeff, power);
    }

    cout << "Enter number of terms for second polynomial: ";
    cin >> n2;

    for (int i = 0; i < n2; i++) {
        int coeff, power;
        cout << "Enter coefficient and power for term " << i + 1 << ": ";
        cin >> coeff >> power;
        p2.insertTerm(coeff, power);
    }

    cout << "\nPolynomial 1: ";
    p1.display();

    cout << "Polynomial 2: ";
    p2.display();

    Polynomial sum = Polynomial::add(p1, p2);
    cout << "Sum: ";
    sum.display();

    return 0;
}
