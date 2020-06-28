//
// Created by Olga Malyugina on 17.04.20.
//


#include <iostream>
#include <vector>

using namespace std;


template <class T>
void print_matrix(const vector<vector<T>>& matrix){
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
    vector<vector<int>> res(N, vector<int>(N, 0));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            char tmp;
            cin >> tmp;
            res[i][j] = tmp == '1';
        }
    }
//    print_matrix(res);

    int max_ = 0;
    for (int i = 0; i < N; ++i) {
        if (res[i][0] == 1) {
            max_ = 1;
            break;
        }
        if (res[0][i] == 1){
            max_ = 1;
            break;
        }
    }
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < N; ++j) {
            if (!res[i][j])
                continue;
            int min_value = min(res[i-1][j-1], res[i-1][j]);
            min_value = min(min_value, res[i][j-1]);
            res[i][j] = min_value+1;
            max_ = max(max_, res[i][j]);
        }
    }

//    print_matrix(res);

    cout << max_*max_;
    return 0;
}
