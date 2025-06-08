#include <iostream>
using namespace std;

int steps = 0; // Global variable to count steps

// Recursive function to solve Tower of Hanoi
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        steps++;
        cout << "Step " << steps << ": Move disk 1 from " << source << " to " << destination << endl;
        return;
    }

    // Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, source, destination, auxiliary);

    // Move the nth disk from source to destination
    steps++;
    cout << "Step " << steps << ": Move disk " << n << " from " << source << " to " << destination << endl;

    // Move n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;
    cout << "\nEnter number of disks: ";
    cin >> n;

    // A, B, C represent the rods
    towerOfHanoi(n, 'A', 'B', 'C');

    cout << "Total steps: " << steps << endl;
    return 0;
}
