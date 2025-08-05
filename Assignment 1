#include <iostream>
using namespace std;

int main() {
    const int cities = 3;
    const int months = 4;
    float rainfall[cities][months];

    for (int i = 0; i < cities; i++) {
        for (int j = 0; j < months; j++) {
            cout << "Enter rainfall for City " << i + 1 << ", Month " << j + 1 << ": ";
            cin >> rainfall[i][j];
        }
    }

    cout << "\nRainfall Data Table:\n";
    cout << "City\t";
    for (int j = 0; j < months; j++) {
        cout << "Month" << j + 1 << "\t";
    }
    cout << "Average\n";

    for (int i = 0; i < cities; i++) {
        float sum = 0;
        cout << i + 1 << "\t";
        for (int j = 0; j < months; j++) {
            cout << rainfall[i][j] << "\t";
            sum += rainfall[i][j];
        }
        float average = sum / months;
        cout << average << endl;
    }

    return 0;
}
