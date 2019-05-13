//
// Created by olga on 11/05/19.
//

#include <iostream>

using namespace std;

int main() {
    int e, f, n;
    cin >> e >> f >> n;
    int a[n][2];
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    int m = f - e;
    int table[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j == 0) {
                table[i][0] = 0;
                if ((i + 1) % a[0][1] == 0) table[i][0] = (i + 1) / a[0][1] * a[0][0];
            } else {
                if (i + 1 >= a[j][1]) {
                    table[i][j] = max(table[i - a[j][1]][j] + a[j][0], table[i][j - 1]);
                } else {
                    table[i][j] = table[i][j - 1];
                }
            }
        }
    }
    int maxx = table[m - 1][n - 1];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j == 0) {
                table[i][0] = 0;
                if ((i + 1) % a[0][1] == 0) table[i][0] = (i + 1) / a[0][1] * a[0][0];
            } else {
                if (1 + i >= a[j][1]) {
                    table[i][j] = min(table[i - a[j][1]][j] + a[j][0], table[i][j - 1]);
                } else {
                    table[i][j] = table[i][j - 1];
                }
            }
        }
    }
    cout << "array " << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
    cout << "res " << endl;
    if (table[m - 1][n - 1] == 0 || maxx == 0) {
        cout << "This is impossible.";
        return 0;
    }
    cout << table[m - 1][n - 1] << ' ' << maxx;
}