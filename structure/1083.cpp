//
// Created by Olga Malyugina on 15.03.21.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

struct SQRT_DEC{
    int n;
    int group_size;
    int UNDEF = -1;
    int MAX = INT_MAX;
    vector<int> original;
    vector<int> group_add;
    vector<int> group_min;
    vector<int> group_value;
    vector<long long> group_sum;

    explicit SQRT_DEC(int n_):
    n(n_),
    group_size(int(sqrt(n))),
    original(n, 0),
    group_add(1+n/group_size,0),
    group_min(1+n/group_size,MAX),
    group_value(1+n/group_size,UNDEF),
    group_sum(1+n/group_size,0)
    {
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            original[i] = tmp;
            group_min[i / group_size] = min(group_min[i / group_size], tmp);
            group_sum[i / group_size] += tmp;
        }
    }

};

int get_i(const SQRT_DEC &sqr, int index) {
    int group_i=index / sqr.group_size;
    if (sqr.group_value[group_i] == sqr.UNDEF) {
        return sqr.group_add[group_i] + sqr.original[index];
    } else {
        return sqr.group_value[group_i];
    }
}

int rmq(const SQRT_DEC &sqr, int l, int r) {
    int group_left = l / sqr.group_size;
    int group_right = r / sqr.group_size;
    int res = sqr.MAX;
    if (group_left == group_right) {
        for (int i = l; i <= r; ++i) {
            res = min(res, get_i(sqr, i));
        }
    } else {
        for (int i = l; i < (group_left + 1) * sqr.group_size; ++i) {
            res = min(res, get_i(sqr, i));
        }
        for (int i = group_left + 1; i < group_right; ++i) {
            res = min(res, sqr.group_min[i]);
        }
        for (int i = group_right * sqr.group_size; i <= r; ++i) {
            res = min(res, get_i(sqr, i));
        }
    }
    return res;
}

long long rsq(const SQRT_DEC&sqr, int l, int r) {
    int group_left = l / sqr.group_size;
    int group_right = r / sqr.group_size;
    long long res = 0;
    if (group_left == group_right) {
        for (int i = l; i <= r; ++i) {
            res += get_i(sqr, i);
        }
    } else {
        for (int i = l; i < (group_left + 1) * sqr.group_size; ++i) {
            res += get_i(sqr, i);
        }
        for (int i = group_left + 1; i < group_right; ++i) {
            res += sqr.group_sum[i];
        }
        for (int i = group_right * sqr.group_size; i <= r; ++i) {
            res += get_i(sqr, i);
        }
    }
    return res;
}

void update_min_sum_in_group(SQRT_DEC&sqr, int group_i) {
    int end = min((group_i + 1) * sqr.group_size, sqr.n);
    int sum_i = 0;
    int min_i = sqr.MAX;
    for (int i = group_i * sqr.group_size; i < end; ++i) {
        sum_i += sqr.original[i];
        min_i = min(min_i, sqr.original[i]);
    }
    sqr.group_sum[group_i] = sum_i;
    sqr.group_min[group_i] = min_i;
}

void values_in_data(SQRT_DEC&sqr, int group_i){
    int end = min((group_i + 1) * sqr.group_size, sqr.n);
    int min_i = sqr.MAX;
    int sum_i = 0;
    for (int i = group_i * sqr.group_size; i < end; ++i) {
        sqr.original[i] = get_i(sqr, i);
        min_i = min(min_i, sqr.original[i]);
        sum_i += sqr.original[i];
    }
    sqr.group_value[group_i] = sqr.UNDEF;
    sqr.group_add[group_i] = 0;
    sqr.group_sum[group_i] = sum_i;
    sqr.group_min[group_i] = min_i;
}

void update(SQRT_DEC& sqr, int l, int r, int v) {
    int group_left = l / sqr.group_size;
    int group_right = r / sqr.group_size;
    if (group_left == group_right) {
        values_in_data(sqr, group_left);
        for (int i = l; i <= r; ++i) {
            sqr.original[i] = v;
        }
        update_min_sum_in_group(sqr, group_left);
    } else {
        values_in_data(sqr, group_left);
        for (int i = l; i < (group_left + 1) * sqr.group_size; ++i) {
            sqr.original[i] = v;
        }
        update_min_sum_in_group(sqr, group_left);

        for (int i = group_left + 1; i < group_right; ++i) {
            sqr.group_value[i] = v;
            sqr.group_min[i] = v;
            sqr.group_sum[i] = v*sqr.group_size;
        }

        values_in_data(sqr, group_right);
        for (int i = group_right * sqr.group_size; i <= r; ++i) {
            sqr.original[i] = v;
        }
        update_min_sum_in_group(sqr, group_right);

    }
}

void add(SQRT_DEC&sqr, int l, int r, int v) {
    int group_left = l / sqr.group_size;
    int group_right = r / sqr.group_size;
    if (group_left == group_right) {
        values_in_data(sqr, group_left);
        for (int i = l; i <= r; ++i) {
            sqr.original[i] += v;
        }
        update_min_sum_in_group(sqr, group_left);
    } else {
        values_in_data(sqr, group_left);
        for (int i = l; i < (group_left + 1) * sqr.group_size; ++i) {
            sqr.original[i] += v;
        }
        update_min_sum_in_group(sqr, group_left);

        for (int i = group_left + 1; i < group_right; ++i) {
            if (sqr.group_value[i] == sqr.UNDEF){
                sqr.group_add[i] += v;
            }else{
                sqr.group_value[i] = sqr.group_value[i]+v;
            }
            sqr.group_min[i] += v;
            sqr.group_sum[i] += v*sqr.group_size;
        }

        values_in_data(sqr, group_right);
        for (int i = group_right * sqr.group_size; i <= r; ++i) {
            sqr.original[i] += v;
        }
        update_min_sum_in_group(sqr, group_right);
    }
}

int main() {
    int n;
    cin >> n;
    SQRT_DEC sqr(n);

    int m;
    cin >> m;
    for (int j = 0; j < m; ++j) {
        string command;
        cin >> command;
        if (command == "get") {
            int index;
            cin >> index;
            index--;
            cout << get_i(sqr, index) << endl;
        } else if (command == "update") {
            int l, r, v;
            cin >> l >> r >> v;
            l--;
            r--;
            update(sqr, l, r, v);
        } else if (command == "add") {
            int l, r, v;
            cin >> l >> r >> v;
            l--;
            r--;
            add(sqr, l, r, v);
        } else if (command == "rsq") {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            cout << rsq(sqr, l, r) << endl;
        } else if (command == "rmq") {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            cout << rmq(sqr, l, r) << endl;
        }
    }


    return 0;
}