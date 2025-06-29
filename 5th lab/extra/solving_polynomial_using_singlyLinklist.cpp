#include <iostream>
#include <cmath>
using namespace std;

class Node {
public:
    int coeff;    // Coefficient
    int power;    // Power of x
    Node* next;

    Node(int c, int p) {
        coeff = c;
        power = p;
        next = NULL;
    }
};

class Polynomial {
private:
    Node* head;

public:
    Polynomial() {
        head = NULL;
    }

    // Insert term in descending order of power
    void insertTerm(int coeff, int power) {
        Node* newNode = new Node(coeff, power);

        // Insert at beginning or before the first larger power
        if (head == NULL || power > head->power) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL && temp->next->power >= power) {
                temp = temp->next;
            }

            // Combine like terms
            if (temp->power == power) {
                temp->coeff += coeff;
                delete newNode;
            } else {
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
    }

    // Display polynomial
    void display() {
        if (head == NULL) {
            cout << "0";
            return;
        }

        Node* temp = head;
        while (temp != NULL) {
            cout << temp->coeff << "x^" << temp->power;
            temp = temp->next;
            if (temp != NULL)
                cout << " + ";
        }
        cout << endl;
    }

    // Evaluate polynomial for a given x
    int evaluate(int x) {
        int result = 0;
        Node* temp = head;
        while (temp != NULL) {
            result += temp->coeff * pow(x, temp->power);
            temp = temp->next;
        }
        return result;
    }
};

// --- Main Function ---
int main() {
    Polynomial poly;

    int n;
    cout << "Enter number of terms in polynomial: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int coeff, power;
        cout << "Enter coefficient and power for term " << i + 1 << ": ";
        cin >> coeff >> power;
        poly.insertTerm(coeff, power);
    }

    cout << "Polynomial: ";
    poly.display();

    int x;
    cout << "Enter value of x to evaluate the polynomial: ";
    cin >> x;
    cout << "Result: " << poly.evaluate(x) << endl;

    return 0;
}
