#include <iostream>

using namespace std;

int main() {
    int e, f, n;
    cin >> e >> f >> n;
    int a[n][2];
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    int weight = f - e;
    int table[weight][n];
    if (weight == 0) {
        cout << "0 0";
        return 0;
    }
    for (int weight_i = 0; weight_i < weight; weight_i++) {
        for (int obj_i = 0; obj_i < n; obj_i++) {
            if (obj_i == 0) {
                table[weight_i][0] = 0;
                if ((weight_i + 1) % a[0][1] == 0) table[weight_i][0] = (weight_i + 1) / a[0][1] * a[0][0];
            } else {
                if (weight_i >= a[obj_i][1] && table[weight_i - a[obj_i][1]][obj_i] != 0) {
                    table[weight_i][obj_i] = max(table[weight_i - a[obj_i][1]][obj_i] + a[obj_i][0],
                                                 table[weight_i][obj_i - 1]);
                } else if ((weight_i + 1) == a[obj_i][1]) {
                    table[weight_i][obj_i] = max(a[obj_i][0], table[weight_i][obj_i - 1]);
                }
                else {
                    table[weight_i][obj_i] = table[weight_i][obj_i - 1];
                }
            }
        }
    }
/*cout << endl;
for (int i=0;i<weight;i++)
{
for (int j=0;j<n;j++)
cout << table[i][j] << ' ';
cout << endl;
}*/
    int maxx = table[weight - 1][n - 1];
    for (int weight_i = 0; weight_i < weight; weight_i++) {
        for (int obj_i = 0; obj_i < n; obj_i++) {
            if (obj_i == 0) {
                table[weight_i][0] = 1000000;
                if ((weight_i + 1) % a[0][1] == 0) table[weight_i][0] = (weight_i + 1) / a[0][1] * a[0][0];
            } else {
                if (weight_i >= a[obj_i][1] && table[weight_i - a[obj_i][1]][obj_i] != 1000000) {
                    table[weight_i][obj_i] = min(table[weight_i - a[obj_i][1]][obj_i] + a[obj_i][0],
                                                 table[weight_i][obj_i - 1]);
                } else if ((weight_i + 1) == a[obj_i][1])
                    table[weight_i][obj_i] = min(a[obj_i][0], table[weight_i][obj_i - 1]);
                else {
                    table[weight_i][obj_i] = table[weight_i][obj_i - 1];
                }
            }
        }
    }
    if (table[weight - 1][n - 1] == 1000000 || maxx == 0) {
        cout << "This is impossible.";
        return 0;
    }
    cout << table[weight - 1][n - 1] << ' ' << maxx;
}