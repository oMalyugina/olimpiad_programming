//
// Created by olga on 13/06/19.
//

#include <iostream>

using std::cin;
using std::cout;

#include <vector>

using std::vector;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> hills(N);
    vector<int> colors;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int most;
            cin >> most;
            if (most == 1) {
                hills[i].push_back(j);

            }

        }

    }
    for (int i = 0; i < N; i++) {
        int color;
        cin >> color;
        colors.push_back(color);

    }

    int res = 0;
    for (int hill_i = 0; hill_i < N; hill_i++) {
        for (auto hill: hills[hill_i]) {
            if (colors[hill_i] != colors[hill]) res++;

        }

    }
    cout << res / 2;
    return 0;
}