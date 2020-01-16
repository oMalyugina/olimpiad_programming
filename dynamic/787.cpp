//
// Created by olga on 16/01/20.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    int res;
    if (N==1)
        res = a[0];
    else if (N % 2) {
        int res1 = min(a[(N - 3) / 2], a[(N - 3) / 2+1]);
        int res2 = min(a[(N - 3) / 2+1], a[(N - 3) / 2+2]);
        res = max(res1, res2);
    } else {
        res = max(a[(N - 2) / 2], a[(N - 2) / 2+1]);

    }
    cout << res;

    return 0;
}
