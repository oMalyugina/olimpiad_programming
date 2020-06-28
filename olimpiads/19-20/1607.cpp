//
// Created by Olga Malyugina on 15.05.20.
//

#include <iostream>

using namespace std;

long long powerFast(long long num, long long deg, long long modul) {
    long result = 1;
    while (deg) {
        if (deg % 2 == 0) {
            deg /= 2;
            num = num * num % modul;
        } else {
            deg--;
            result = result * num % modul;
        }
    }

    return result;
}

int main() {
    long long a, n, m;
    cin >> a >> n >> m;
    long long q = a % m;
    if (q == 0) {
        cout << 1;
        return 0;
    }
    long long sum;
    if (q == 1)
        sum = (q * n + 1) % m;
    else {
        sum = 1;
        int res = 1;
        for (int i = 1; i <= n; ++i) {
            res = res * q;
            sum = (sum + res);
        }
    }
    cout << (sum)%m;
    return 0;
}