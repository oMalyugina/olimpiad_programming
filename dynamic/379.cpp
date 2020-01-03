//
// Created by olga on 01/01/20.
//
#include <iostream>
#include <vector>

bool checkDate(int day, int month) {
    if (day > 30) return false;
    if (month > 11) return false;
    if (day == 29 and month == 1) return false;
    if (day == 30) {
        if (month == 1) return false;
        if (month == 3) return false;
        if (month == 5) return false;
        if (month == 8) return false;
        if (month == 10) return false;
    }
    return true;
}


using namespace std;

int main() {
    int month, day;
    cin >> day >> month;
    vector<vector<bool>> res(12, vector<bool>(31, false));
    res[11][30] = true;
    for (int month_i = 11; month_i >= 0; --month_i) {
        for (int day_i = 30; day_i >= 0; --day_i) {
            if (!checkDate(day_i, month_i)) continue;
            if (checkDate(day_i + 1, month_i)) {
                bool tmp = res[month_i][day_i] or !res[month_i][day_i + 1];
                res[month_i][day_i] = tmp;
            }
            if (checkDate(day_i + 2, month_i)) {
                bool tmp = res[month_i][day_i] or !res[month_i][day_i + 2];
                res[month_i][day_i] = tmp;
            }
            if (checkDate(day_i, month_i + 1)) {
                bool tmp = res[month_i][day_i] or !res[month_i + 1][day_i];
                res[month_i][day_i] = tmp;
            }
            if (checkDate(day_i, month_i + 2)) {
                bool tmp = res[month_i][day_i] or !res[month_i + 2][day_i];
                res[month_i][day_i] = tmp;
            }
        }

    }
//    for (int i = 0; i < 12; ++i) {
//        for (int j = 0; j < 31; ++j) {
//            cout << res[i][j];
//        }
//        cout << endl;
//
//    }
    if (res[month - 1][day - 1])
        cout << 1;
    else
        cout << 2;
    return 0;

}