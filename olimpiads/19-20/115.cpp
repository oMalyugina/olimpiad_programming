//
// Created by Olga Malyugina on 26.02.21.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<long long>> prefix_sum(n, vector<long long>(m, 0));

    for (int i = 0; i < n; ++i) {
        long long cur = 0;
        for (int j = 0; j < m; ++j) {
            long long tmp;
            cin >> tmp;
            cur += tmp;
            if (i == 0) {
                prefix_sum[i][j] = cur;
            } else {
                prefix_sum[i][j] = prefix_sum[i - 1][j] + cur;
            }
        }
    }

    long long best_value = prefix_sum[0][0];
    long long cur_rectungle = 0;
    for (int l = 0; l < m; ++l) {
        for (int r = l+1; r < m+1; ++r) {
            long long min_value = 0;
            for (int i = 0; i < n; ++i) {
                if (l == 0) {
                    cur_rectungle = prefix_sum[i][r-1];
                } else {
                    cur_rectungle = prefix_sum[i][r-1] - prefix_sum[i][l - 1];
                }
                best_value = max(best_value, cur_rectungle - min_value);
                if (cur_rectungle < min_value) {
                    min_value = cur_rectungle;
                }
            }
        }
    }
    cout << best_value;


    return 0;
}