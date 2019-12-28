//
// Created by olga on 26/12/19.
//
#include <iostream>
#include <vector>

using namespace std;

int sum_rows(const vector<int> &money, int start, int end) {

    int res = 0;
    for (int i = start; i < end; ++i) {
        res += money[i];
    }
    return res;
}

int main() {
//    read data
    int n;
    cin >> n;
    vector<int> money(n, 0);
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        money[n - 1 - i] = tmp;
    }
    int k;
    cin >> k;
    if (n == 0) {
        cout << 0;
        return 0;
    }

//    algorithm
    vector<vector<int>> k_steps(n, vector<int>(k + 1, 0));
    vector<vector<int>> money_res(n, vector<int>(k + 1, 0));
    for (int n_i = 0; n_i < n; ++n_i) {
        for (int k_i = 1; k_i <= k; ++k_i) {
            if (k_i >= n_i + 1) {
                k_steps[n_i][k_i] = min(n_i + 1, k_i);
                money_res[n_i][k_i] = sum_rows(money, 0, min(n_i + 1, k_i));
            } else {
                int best_res = 0;
                int best_number = 0;
                for (int i = 1; i <= k_i; ++i) {
                    int res = sum_rows(money, n_i - i + 1, n_i + 1);
                    int second_step = k_steps[n_i - i][i];
                    if (n_i - i - second_step >= 0)
                        res = res + money_res[n_i - i - second_step][second_step];
                    if (res > best_res) {
                        best_number = i;
                        best_res = res;
                    }
                }
                k_steps[n_i][k_i] = best_number;
                money_res[n_i][k_i] = best_res;
            }
        }
    }
    cout << money_res[n - 1][k];
    return 0;
}
