//
// Created by olga on 28/05/19.
//

#include <iostream>
#include <cmath>

int main() {
    int final_number;
    std::cin >> final_number;

    int cur_sum[final_number + 1];
    int prev_sum[final_number + 1];

    for (int i = 0; i < final_number + 1; ++i) {
        cur_sum[i] = 0;
        prev_sum[i] = 1;
    }

    for (int j = 1; j <= ceil(log2(final_number)); ++j) {
        int two = int(pow(2, j));
        if (two > final_number)
            continue;
        for (int sum_i = 0; sum_i < final_number + 1; ++sum_i) {
            if (sum_i + two <= final_number) {
                cur_sum[sum_i + two] += prev_sum[sum_i] + cur_sum[sum_i];
            }
        }
        for (int i = 0; i < final_number + 1; ++i) {
            prev_sum[i] += cur_sum[i];
            cur_sum[i] = 0;
        }
    }
    std::cout << prev_sum[final_number];
    return 0;
}

