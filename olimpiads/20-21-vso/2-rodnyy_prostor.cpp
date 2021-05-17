//
// Created by Olga Malyugina on 14.04.21.
//

#include <vector>
#include <iostream>
#include <cmath>
#include <stack>
#include <unordered_map>

#define NOHASH -1

using namespace std;

hash<char> hasher_char;
hash<string> hasher_string;

int my_str2int(char c) {
    int res = int(c) - int('a');
    return res;
}

struct Tree {
    int n_in_tree;
    int pow2;
    int len_string;
    vector<int> array_tree;
    vector<vector<size_t>> hashes;
    vector<vector<int>> next_char;
    string original;
    vector<vector<string>> ans;

    Tree(int n_, string &s) {
        original = s;
        pow2 = ceil(log2(n_ + 1)) + 1;
        n_in_tree = pow(2, pow2);
        len_string = original.size();
        array_tree.assign(2 * n_in_tree, -1);
        hashes.assign(pow2, vector<size_t>(len_string, NOHASH));
        next_char.assign(pow2, vector<int>(len_string, -1));
        ans.assign(pow2, vector<string>(len_string + 1, ""));
    }

    bool is_first_better(int pos1, int pos2) {
        int cur_window = pow2 - 1;
        while (cur_window >= 0 and pos1 != n_in_tree and pos2 != n_in_tree) {
            if (hashes[cur_window][pos1] == NOHASH or hashes[cur_window][pos2] == NOHASH) {
                cur_window--;
                continue;
            }
            if (hashes[cur_window][pos1] == hashes[cur_window][pos2]) {
                pos1 = next_char[cur_window][pos1];
                pos2 = next_char[cur_window][pos2];
            }
            cur_window--;
        }
        if (pos1 == pos2 == n_in_tree) {
            return true;
        }
        if (pos1 == len_string)
            return true;
        if (pos2 == len_string)
            return false;
        if (original[pos1] < original[pos2]) {
            return true;
        } else {
            return false;
        }
    }

    void update_tree(int pos) {
        pos = n_in_tree + pos;
        array_tree[pos] = pos - n_in_tree;
        pos /= 2;
        while (pos > 0) {
            if (array_tree[2 * pos] == -1) {
                array_tree[pos] = array_tree[2 * pos + 1];
            } else if (array_tree[2 * pos + 1] == -1) {
                array_tree[pos] = array_tree[2 * pos];
            } else if (is_first_better(array_tree[2 * pos], array_tree[2 * pos + 1])) {
                array_tree[pos] = array_tree[2 * pos];
            } else {
                array_tree[pos] = array_tree[2 * pos + 1];
            }
            pos /= 2;
        }
    }


    void update(int next, int pos) {
        for (int i = 0; i < pow2 and pos + pow(2, i) <= len_string; ++i) {
            ans[i][pos] = original.substr(pos, pow(2, i));
            hashes[i][pos] = hasher_string(ans[i][pos]);
        }
        int cur_window = 0;
        next_char[0][pos] = next;
        while (next != len_string and next != -1) {
            next = next_char[cur_window][next];
            next_char[cur_window + 1][pos] = next;
            cur_window++;
        }
        update_tree(pos);
    }

    int get_rec_min(int l, int r, int lc, int rc) {
        int window = rc - lc + 1;
        if (l == lc and r == rc) {
            return array_tree[l / window];
        }
        int m = lc + window / 2;
        if (l >= m) {
            int res = get_rec_min(l, r, m, rc);
            return res;
        }
        if (r < m) {
            int res = get_rec_min(l, r, lc, m - 1);
            return res;
        }
        int res1 = get_rec_min(l, m - 1, lc, m - 1);
        int res2 = get_rec_min(m, r, m, rc);
        if (is_first_better(res1, res2))
            return res1;
        else
            return res2;
    }

    int get_min(int l, int r) {
        if (r == len_string)
            return len_string;
        int res = get_rec_min(n_in_tree + l, n_in_tree + r, n_in_tree, n_in_tree * 2 - 1);
        return res;
    }

};

vector<int> comute_possible_deleted(int n, const vector<vector<bool>> &can_del, const string &s) {
    vector<int> can_be_deleted_after(n, 0);
    stack<int> help;
    help.push(n - 1);
    for (int i = n - 2; i >= 0; --i) {
        int cur_char = my_str2int(s[i]);
        int last = n - 1;
        if (not help.empty()) {
            int last = help.top();
            int last_char = my_str2int(s[last]);
            while (can_del[cur_char][last_char]) {
                help.pop();
                if (help.empty())
                    break;
                last = help.top();
                last_char = my_str2int(s[last]);
            }
        }
        if (help.empty()) {
            last = n;
        } else {
            last = help.top();
        }
        int res = last - i - 1;
        can_be_deleted_after[i] = res;
        help.push(i);
    }
    return can_be_deleted_after;
}

int main() {
    int k, n;
    cin >> k >> n;
    vector<vector<bool>> can_del(k, vector<bool>(k, false));
    for (int i = 0; i < k; ++i) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < k; ++j) {
            can_del[i][j] = (tmp[j] == '1');
        }
    }
    string s;
    cin >> s;
    vector<int> can_be_deleted_after = comute_possible_deleted(n, can_del, s);

    vector<string> ans(n, "");
    Tree tree(n, s);
    tree.update(n, n - 1);
    for (int i = n - 2; i >= 0; --i) {
        int best_next = tree.get_min(i + 1, i + can_be_deleted_after[i] + 1);
        tree.update(best_next, i);
    }
    int pos = 0;
    while (pos != n) {
        cout << s[pos];
        pos = tree.next_char[0][pos];
    }
    return 0;
}

