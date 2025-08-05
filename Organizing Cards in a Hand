#include <iostream>
#include <string>
using namespace std;

int cardvalue(string card) {
    if (card == "A") return 1;
    if (card == "J") return 11;
    if (card == "Q") return 12;
    if (card == "K") return 13;
    return stoi(card); // For numbers 2-10
}

int main() {
    string cards[5];

    cout << "Enter 5 cards (A/2-10/J/Q/K): " << endl;   //Input
    for (int i = 0; i < 5; i++) {
        cin >> cards[i];
    }

    for (int i = 1; i < 5; i++) {   //Insertion Sort
        string key = cards[i];
        int keyvalue = cardvalue(key);
        int j = i - 1;

        while (j >= 0 && cardvalue(cards[j]) > keyvalue) {
            cards[j + 1] = cards[j];
            j--;
        }
        cards[j + 1] = key;
    }

    cout << "\nOrganized cards in hand: ";  //Output
    for (int i = 0; i < 5; i++) {
        cout << cards[i] << " ";
    }
    cout << endl;

    return 0;
}
