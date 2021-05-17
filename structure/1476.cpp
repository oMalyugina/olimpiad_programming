//
// Created by Olga Malyugina on 29.03.21.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct simple {
    vector<bool> original;
    int sum_ = 0;


    simple() {
        original.assign(1000000, false);
    }

    void add(int index) {
        for (;; index++) {
            if (!original[index]) {
                original[index] = true;
                sum_++;
                break;
            } else {
                original[index] = false;
                sum_--;
            }
        }
    }

    int number() {
        return sum_;
    }

    void substract(int index) {
        for (;; index++) {
            if (original[index]) {
                original[index] = false;
                sum_--;
                break;
            } else {
                original[index] = true;
                sum_++;
            }

        }
    }

};

struct SQRT {
    vector<bool> original;
    vector<int> sums;
    int group_size = 317;
    int sum_ = 0;

    SQRT() {
        original.assign(317*317, false);
        sums.assign(317, 0);
    }

    void to_original(int group_i){
        int first_index_in_group = group_i * group_size;
        int last_element_in_group = (group_i + 1) * group_size - 1;
        if (sums[group_i] == group_size){
            for (int i = first_index_in_group; i <= last_element_in_group; ++i) {
                original[i] = true;
            }
            return;
        }
        if (sums[group_i] == 0){
            for (int i = first_index_in_group; i <= last_element_in_group; ++i) {
                original[i] = false;
            }
            return;
        }
    }


    void add(int index) {
        int group_i = index / group_size;
        int last_element_in_group = (group_i + 1) * group_size - 1;
        to_original(group_i);
        for (int i = index; i <= last_element_in_group; ++i) {
            if (!original[i]) {
                original[i] = true;
                sum_++;
                sums[group_i]++;
                return;
            } else {
                original[i] = false;
                sum_--;
                sums[group_i]--;
            }
        }
        group_i++;
        while(sums[group_i]==group_size){
            sums[group_i]=0;
            sum_-=group_size;
            group_i++;
        }
        to_original(group_i);
        int first_index_in_group = group_i * group_size;
        last_element_in_group = (group_i + 1) * group_size - 1;
        for (int i = first_index_in_group; i <= last_element_in_group; ++i) {
            if (!original[i]) {
                original[i] = true;
                sum_++;
                sums[group_i]++;
                return;
            } else {
                original[i] = false;
                sum_--;
                sums[group_i]--;
            }
        }
    }

    void substract(int index) {
        int group_i = index / group_size;
        int last_element_in_group = (group_i + 1) * group_size - 1;
        to_original(group_i);
        for (int i = index; i <= last_element_in_group; ++i) {
            if (original[i]) {
                original[i] = false;
                sum_--;
                sums[group_i]--;
                return;
            } else {
                original[i] = true;
                sum_++;
                sums[group_i]++;
            }
        }
        group_i++;
        while (sums[group_i]==0){
            sums[group_i]=group_size;
            sum_+=group_size;
            group_i++;
        }
        to_original(group_i);
        int first_index_in_group = group_i * group_size;
        last_element_in_group = (group_i + 1) * group_size - 1;
        for (int i = first_index_in_group; i <= last_element_in_group; ++i) {
            if (original[i]) {
                original[i] = false;
                sum_--;
                sums[group_i]--;
                return;
            } else {
                original[i] = true;
                sum_++;
                sums[group_i]++;
            }
        }
    }

    int number() {
        return sum_;
    }
};

int main() {
//    simple data;
    SQRT data;
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        string command;
        int s;
        cin >> command >> s;
        if (command == "add") {
            data.add(s);
            cout << data.number() << endl;
        } else {
            data.substract(s);
            cout << data.number() << endl;
        };
    }
    return 0;
}