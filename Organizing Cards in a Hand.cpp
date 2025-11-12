#include <iostream>
using namespace std;

int main() {
    int cards[5];

    cout << "Enter 5 card values (1 to 13): " << endl;
    for (int i = 0; i < 5; i++) {
        cin >> cards[i];
    }

    cout << "\n--- Sorting Cards (Insertion Sort) ---\n";
    for (int i = 1; i < 5; i++) {
        int key = cards[i];
        int j = i - 1;

        while (j >= 0 && cards[j] > key) {
            cards[j + 1] = cards[j];
            j--;
        }
        cards[j + 1] = key;

        cout << "After Pass " << i << ": ";
        for (int k = 0; k < 5; k++) {
            cout << cards[k] << " ";
        }
        cout << endl;
    }

    cout << "\nFinal Sorted Cards: ";
    for (int i = 0; i < 5; i++) {
        cout << cards[i] << " ";
    }
    cout << endl;

    return 0;
}
