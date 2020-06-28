//
// Created by Olga Malyugina on 26.04.20.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check_chars(const vector<char> &current) {
    if (current[0] != current[1])
        return false;
    if (current[2] != current[1])
        return false;
    if (current[0] != current[2])
        return false;
    return true;
}

bool check_indexes(const vector<int> &current_index, const vector<string> &data) {
    for (int i = 0; i < 3; ++i) {
        if (current_index[i] >= data[i].size())
            return false;
    }
    return true;
}

int my_median(vector<int> number_chars){
    sort(number_chars.begin(), number_chars.end());
    return number_chars[1];
}

int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    vector<string> data{s1, s2, s3};
    vector<int> current_index(3, 0);
    vector<char> best_password;
    vector<char> current_char(3, ' ');
    vector<int> number_chars(3, 0);

    while (check_indexes(current_index, data)) {
        for (int i = 0; i < 3; ++i) {
            current_char[i] = data[i][current_index[i]];
        }
        if (!check_chars(current_char)) {
            cout << "IMPOSSIBLE";
            return 0;
        }
        for (int i = 0; i < 3; ++i) {
            int current_index_i = current_index[i];
            string cur_string = data[i];
            char cur_char_i = cur_string[current_index_i];
            int len_string_i = 0;
            while (current_index_i < cur_string.size() and cur_char_i == cur_string[current_index_i]) {
                current_index_i++;
                len_string_i++;
            }
            current_index[i] = current_index_i;
            number_chars[i] = len_string_i;
        }
        int number_repetitions = my_median(number_chars);
        for (int repetions = 0; repetions < number_repetitions; ++repetions) {
            best_password.push_back(current_char[0]);
        }

    }
    int delta = 0;
    for (int i = 0; i < 3; ++i) {
        if (data[i].size() - current_index[i] != 0)
            delta += 1;
    }
    if (delta > 0) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    for (auto char_:best_password) {
        cout << char_;
    }
    return 0;
}

