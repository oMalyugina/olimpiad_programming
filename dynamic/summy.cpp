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

int main(){

    int N;
    cin >> N;

    vector<int> numbers;
    for (int i = 0; i < N; ++i) {
        int number;
        cin >> number;
        numbers.push_back(number);
    }

    int max_sum = std::accumulate(numbers.begin(),numbers.end(),0);

    int sum_number[max_sum+1];

    for (int sum_i = 0; sum_i <= max_sum; ++sum_i) {
        sum_number[sum_i] = 0;
    }

    for (int sum_i = 0; sum_i <= max_sum; ++sum_i) {
        for (const auto &number : numbers) {
            if (number < sum_i)
                continue;
            if (sum_number[sum_i - number] == 0)
                continue;
        }
    }

    return 0;
}