//
// Created by Olga Malyugina on 18.03.21.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct fenvic {
    vector<int> data;
    int n;

    fenvic(int n_) : n(n_) {
        data.assign(n, 0);
    }

    int sum_(int height) {
        height = n - height;
        int res = 0;
        for (int i = height; i >= 0; i = (i & (i + 1)) - 1) {
            res += data[i];
        }
        return res;
        return 0;
    }

    void update_(int height) {
        height = n - height;
        for (int i = height; i < n; i = i | (i + 1)) {
            data[i]++;
        }
    }
};


struct sqrt {
    vector<int> original;
    vector<int> sums;
    int group_size = 100;
    int n;

    sqrt(int n_) {
        original.assign(100 * 100, 0);
        sums.assign(100, 0);
        n = n_;
    }

    int sum_(int height) {
        int index = n - height;
        int group_h = index / group_size;
        int res = 0;
        for (int i = 0; i < group_h; ++i) {
            res += sums[i];
        }
        for (int j = group_h * group_size; j < index; ++j) {
            res += original[j];
        }
        return res;
    }

    void update_(int height) {
        int index = n - height;
        original[index] = 1;
        sums[index / group_size]++;
    }
};

struct tree {
    vector<int> data;
    int n;

    tree(int n_) {
        n = pow(2, ceil(log2(n_)));
        data.assign(2 * n, 0);
    }

    int reccursive_sum(int s, int e, int l, int r) {
        int window = r - l + 1;
        if (s == l and e == r) {
            return data[l / window];
        }
        int m = l + window / 2;
        if (e < m) {
            int res = reccursive_sum(s, e, l, m - 1);
            return res;
        } else if (s >= m) {
            int res = reccursive_sum(s, e, m, e);
            return res;
        } else {
            int res1 = reccursive_sum(s, m - 1, l, m - 1);
            int res2 = reccursive_sum(m, e, m, r);
            return res1 + res2;
        }
    }

    int sum_(int height) {
        height--;
        int res = reccursive_sum(n + height, 2 * n - 1, n, 2 * n - 1);
        return res;
    }

    void update_(int height) {
        height--;
        int index = n + height;
        while (index > 0) {
            data[index]++;
            index = index / 2;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    int res = 0;
    for (int i = 0; i < k; ++i) {
//        fenvic data(n);
//        sqrt data(n);
        tree data(n);
        for (int j = 0; j < n; ++j) {
            int height;
            cin >> height;
            res += data.sum_(height);
            data.update_(height);
        }
    }
    cout << res;
    return 0;
}
