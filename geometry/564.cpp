//
// Created by olga on 18/08/19.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> lens;
    for (int i = 0; i < n; ++i) {
        int len;
        cin >> len;
        lens.push_back(len);
    }

    long double max_square = 0;
    int res1, res2, res3;
    if (lens.size() < 3) {
        cout << -1;
        return 0;
    }
    for (int j = 0; j < lens.size() - 2; ++j) {
        for (int i = j + 1; i < lens.size() - 1; ++i) {
            for (int k = i + 1; k < lens.size(); ++k) {
                if (lens[i] >= lens[k] + lens[j]) continue;
                if (lens[j] >= lens[k] + lens[i]) continue;
                if (lens[k] >= lens[i] + lens[j]) continue;
                long double p = (lens[i] + lens[j] + lens[k]) * 1. / 2.;
                long double square = p * (p - lens[i]) * (p - lens[j]) * (p - lens[k]);
                if (max_square < square) {
                    res1 = i;
                    res2 = j;
                    res3 = k;
                    max_square = square;
                }
            }
        }
    }
    if (max_square != 0) {
        cout.precision(17);
        cout << sqrt(max_square) << endl;
        cout << res1 + 1 << " " << res2 + 1 << " " << res3 + 1;
    } else {
        cout << -1;
    }
}