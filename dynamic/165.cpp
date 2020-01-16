//
// Created by olga on 16/01/20.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> map(N, vector<int>(M, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int tmp;
            cin >> tmp;
            map[i][j] = tmp;
        }
    }
    vector<vector<int>> res(N, vector<int>(M, 0));
    res[0][0]=1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (i == N-1 and j == M-1) continue;
            if (i+map[i][j] < N){
                res[i+map[i][j]][j] += res[i][j];
            }
            if (j+map[i][j] < M){
                res[i][j+map[i][j]] += res[i][j];
            }
        }
    }
    cout << res[N-1][M-1];
    return 0;
}