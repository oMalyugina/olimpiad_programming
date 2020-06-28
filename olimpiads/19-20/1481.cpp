//
// Created by Olga Malyugina on 30.05.20.
//
#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    string prev_tree;
    cin >> prev_tree;
    int len_first = prev_tree.size();
    int full_len = len_first;
    for (int i = 1; i < n; ++i) {
        string current_tree;
        cin >> current_tree;
        int start_current = max(int(prev_tree.size()) - int(current_tree.size()), 0);
        while (start_current < prev_tree.size()) {
            int current_char_in_second = 0;
            bool found = true;
            while (start_current + current_char_in_second < prev_tree.size()) {
                if (prev_tree[start_current + current_char_in_second] != current_tree[current_char_in_second]) {
                    found = false;
                    break;
                }
                current_char_in_second++;
            }
            if (found) {
                full_len += int(current_tree.size()) - current_char_in_second;
                break;
            } else {
                start_current += current_char_in_second + 1;
            }
        }
    }

    cout << full_len - len_first;


    return 0;
}