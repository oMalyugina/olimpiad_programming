//
// Created by olga on 24.01.20.
//

#include <iostream>
#include <vector>

using namespace std;


int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<bool>> map(N + 2, vector<bool>(M + 2, false));
    vector<vector<int>> hres(N + 2, vector<int>(M + 2, 0));
    vector<vector<int>> vres(N + 2, vector<int>(M + 2, 0));
    for (int i = 0; i < K; ++i) {
        int vFirst, hFirst, vLast, hLast;
        cin >> vFirst >> hFirst >> vLast >> hLast;
        for (int x = vFirst; x <= vLast; ++x) {
            for (int y = hFirst; y <= hLast; ++y) {
                map[x][y] = true;
            }
        }
    }

    int best_res = 0;
    for (int x = 1; x <= N; ++x) {
        for (int y = 1; y <= M; ++y) {

            if (map[x][y] == false and map[x-1][y] == false and map[x][y-1] == false and map[x+1][y] == false and map[x][y+1] == false) {
                hres[x][y] = hres[x - 1][y] + 1;
                vres[x][y] = vres[x][y-1] + 1;
                best_res = max(hres[x][y]*vres[x][y], best_res);
            }
            else{
                hres[x][y] = 0;
                vres[x][y] = 0;
            }

        }
    }

    cout << best_res;

    return 0;
}
