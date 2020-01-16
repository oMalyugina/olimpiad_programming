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
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (i==0 and j==0) res[i][j] = map[i][j];
            else if (i==0){
                res[i][j] = res[i][j-1] + map[i][j];
            } else if (j == 0){
                res[i][j] = res[i-1][j] + map[i][j];
            } else{
                res[i][j] = min(res[i-1][j] + map[i][j],res[i][j-1] + map[i][j]);
            }
        }
    }
    cout << res[N-1][M-1];
    return 0;
}