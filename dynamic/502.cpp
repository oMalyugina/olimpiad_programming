//
// Created by Olga Malyugina on 04.04.20.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


template<class T>
void print_matrix(const vector<vector<T>> &matrix) {
    cout << "print matrix" << endl;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> field(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> field[i][j];
        }
    }

    vector<vector<int>> res(N + 1, vector<int>(N+1, 0));
    for (int i = 0; i < N; ++i) {
        res[1][i+1] = field[i][0];
    }

    for (int num_column = 2; num_column < N + 1; ++num_column) {
        for (int field_column = 1; field_column < N+1; ++field_column) {
            for (int column_i = 0; column_i <= N - field_column; ++column_i) {
                int sum_raws = field_column+column_i;
                int curr_weight = field[field_column - 1][num_column - 1];
                int prev_value = res[num_column-1][sum_raws];
                res[num_column][sum_raws] = max(prev_value, res[num_column][sum_raws]);
                int cuur_value = res[num_column][sum_raws];
                int possible_value = res[num_column-1][column_i] + curr_weight;
                res[num_column][sum_raws] = max(cuur_value, possible_value);
            }
        }
    }

    print_matrix(res);
    cout << res[N][N];
}