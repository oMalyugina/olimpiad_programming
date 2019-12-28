//
// Created by olga on 28/12/19.
//

#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
    long long K;
    cin >> K;
    if (K <= 2) {
        cout << 0;
        return 0;
    }
    if (K==4){
        cout << 3;
        return 0;
    }

    for (long long i = 3; i < sqrt(K); ++i) {
        if (K % i == 0) {
            cout << i - 1;
            return 0;
        }
    }
    if (K%2==0) cout << K/2-1;
    else cout << K - 1;
    return 0;
}