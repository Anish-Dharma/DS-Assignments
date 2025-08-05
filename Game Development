#include <iostream>
using namespace std;

int main() {
    int score_1[5], score_2[5];
    int temp;

    cout << "Enter 5 two-digit scores of Player 1: " << endl;    //Input for Player 1
    for (int i = 0; i < 5; i++) {
        cin >> score_1[i];
    }

    for (int pass = 0; pass < 5 - 1; pass++) {              //Bubble Sort
        for (int sort = 0; sort < 5 - pass - 1; sort++) {
            if (score_1[sort] > score_1[sort + 1]) {
                temp = score_1[sort];
                score_1[sort] = score_1[sort + 1];
                score_1[sort + 1] = temp;
            }
        }
    }

    cout << "Enter 5 two-digit scores of Player 2: " << endl;   //Input for Player 2
    for (int i = 0; i < 5; i++) {
        cin >> score_2[i];
    }

    for (int pass = 0; pass < 5 - 1; pass++) {              //Bubble Sort 
        for (int sort = 0; sort < 5 - pass - 1; sort++) {
            if (score_2[sort] > score_2[sort + 1]) {
                temp = score_2[sort];
                score_2[sort] = score_2[sort + 1];
                score_2[sort + 1] = temp;
            }
        }
    }

    cout << "\nLevel-up! Scores sorted in ascending order:\n";  //Output of sorted arrays
  
    cout << "Player 1: ";
    for (int i = 0; i < 5; i++) {
        cout << score_1[i] << " ";
    }
    cout << endl;

    cout << "Player 2: ";
    for (int i = 0; i < 5; i++) {
        cout << score_2[i] << " ";
    }
    cout << endl;
    
    int total1 = 0, total2 = 0;     //Comparing both scores
    for (int i = 0; i < 5; i++) {
        total1 += score_1[i];
        total2 += score_2[i];
    }

    cout << "\nTotal Score of Player 1: " << total1;
    cout << "\nTotal Score of Player 2: " << total2 << endl;

    if (total1 > total2) {          //Declaring the winner
        cout << "\nPlayer 1 Wins!";
    } else if (total2 > total1) {
        cout << "\nPlayer 2 Wins!";
    } else {
        cout << "\nIt's a Tie!";
    }

    return 0;
}
