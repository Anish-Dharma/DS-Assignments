#include <iostream>
using namespace std;

int main() {
    int city = 3;
    int week = 7;
    float temp[city][week];

    cout << "Enter daily temperature data for 3 cities and 7 days:\n";
    for (int i = 0; i < city; ++i) {
       // cout << "For City " << (i + 1) << ":\n";
        for (int j = 0; j < week; ++j) {
            cout << " Temperature at City "<<(i+1)<<" on Day " << (j + 1) << ": ";
            cin >> temp[i][j];
        }
    }
    cout<<"----Temperature Data Table----\n";
    cout << "City     Day1     Day2     Day3     Day4     Day5     Day6     Day7     Weekly Average\n";
    cout << "--------------------------------------------------------------------------------\n";

    double total_week_temp = 0;
    for (int i = 0; i < city; ++i) {
        double total_city_temp = 0;
        cout.width(8);
        cout << left << (i + 1);
        for (int j = 0; j < week; ++j) {
            cout.width(8);
            cout << temp[i][j];
            total_city_temp += temp[i][j];
        }
        double avg_city_week = total_city_temp / week;
        cout.width(8);
        cout << avg_city_week << "\n";
        total_week_temp += total_city_temp;
    }

    cout << "--------------------------------------------------------------------------------\n";
    cout << "Daily Average:";
    for (int j = 0; j < week; ++j) {
        double total_day_temp = 0;
        for (int i = 0; i < city; ++i) {
            total_day_temp += temp[i][j];
        }
        double avg_day = total_day_temp / city;
        cout.width(8);
        cout << avg_day;
    }
    cout << "\n";

    double overall_avg_week = total_week_temp / (city * week);
    cout << "\nWeekly Average Temperature: " << overall_avg_week << "\n";

    return 0;
}

