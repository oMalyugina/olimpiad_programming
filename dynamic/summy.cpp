//
// Created by olga on 11/05/19.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::unordered_set;

int main(){

    int N;
    cin >> N;

    vector<int> numbers;
    for (int i = 0; i < N; ++i) {
        int number;
        cin >> number;
        numbers.push_back(number);
    }

    unordered_set<int> sum;
    sum.insert(0);
    for (const auto &number : numbers) {
        unordered_set<int> tmp_sum;
        for (const auto &item : sum) {
            tmp_sum.insert(item+number);
        }
        sum.insert(tmp_sum.begin(), tmp_sum.end());
    }

    cout << sum.size();
    return 0;
}