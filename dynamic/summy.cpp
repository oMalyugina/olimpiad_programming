//
// Created by olga on 11/05/19.
//

#include <iostream>
#include <vector>
#include<numeric>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {

    int N;
    cin >> N;

    vector<int> numbers;
    for (int i = 0; i < N; ++i) {
        int number;
        cin >> number;
        numbers.push_back(number);
    }

    int max_sum = std::accumulate(numbers.begin(), numbers.end(), 0);

    int sum[max_sum + 1];

    for (int sum_i = 0; sum_i <= max_sum; ++sum_i) {
        sum[sum_i] = 0;
    }
    sum[0] = 1;

    for (const auto &number : numbers) {
        int sum_prev[max_sum + 1];
        for (int sum_i = 0; sum_i <= max_sum; ++sum_i) {
            sum_prev[sum_i] = sum[sum_i];
        }
        for (int sum_i = 0; sum_i <= max_sum; ++sum_i) {
            if (sum_prev[sum_i] == 1) {
                continue;
            }
            if (sum_i >= number) {
                if (sum_prev[sum_i - number] == 1) {
                    sum[sum_i] = 1;
                }
            }
        }
    }

    int result = 0;
    for (int i = 0; i < max_sum + 1; ++i) {
        result += sum[i];
    }

    cout << result;

    return 0;
}