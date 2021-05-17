//
// Created by Olga Malyugina on 18.03.21.
//

#include <iostream>
#include <vector>

using namespace std;

void update(vector<long long> &fenvic, int index, int value) {
    for (; index < fenvic.size(); index = index | (index + 1)) {
        fenvic[index] += value;
    }
}

vector<long long> build_fenvic(vector<int> &data) {
    vector<long long> res(data.size(), 0);
    for (int i = 0; i < data.size(); ++i) {
        update(res, i, data[i]);
    }

    return res;
}

long long sum(vector<long long> &fenvic, int r) {
    long long res = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) {
        res += fenvic[r];
    }
    return res;
}

long long sum(vector<long long> &fenvic, int l, int r) {
    if (l == 0) {
        return sum(fenvic, r);
    } else {
        return sum(fenvic, r) - sum(fenvic, l - 1);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> fenvic(n, 0);
    for (int i = 0; i < m; ++i) {
        string command;
        cin >> command;
        if (command == "add") {
            int index, value;
            cin >> index >> value;
            index--;
            update(fenvic, index, value);
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            cout << sum(fenvic, l, r) << endl;
        }
    }

    return 0;
}