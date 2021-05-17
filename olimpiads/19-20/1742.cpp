//
// Created by Olga Malyugina on 01.01.21.
//

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int binary_search(std::vector<std::pair<int, int>>& a, int d) {
    if (a.size() == 1) {
        if (a[0].first <= d - 1)
            return 1;
        else
            return 0;
    }
    int left = 0;
    int right = a.size() - 1;
    if (a[left].first >= d)
        return 0;
    if (a[right].first < d - 1)
        return right + 1;
    int i;
    while (left < right){
        i = left + int((right - left + 1) / 2);
        if (a[i].first - d + 1 > 0)
            right = i - 1;
        else
            left = i;
    }
    if (a[i].first <= d - 1)
        return i + 1;
    return i;
}

void solution(ifstream& cin){
    uint64_t n;
    cin >> n;

    unordered_map<int, int> diffs2numbers_dict;
    unordered_map<int, int> indexes;
    int unique_works = 0;
    for (int i = 0; i < n; ++i) {
        int work;
        cin >> work;
        if (indexes.find(work) == indexes.end()){
            unique_works++;
            if (diffs2numbers_dict.find(i) == diffs2numbers_dict.end()){
                diffs2numbers_dict[i] = 1;
            }else{
                diffs2numbers_dict[i]++;
            }
            indexes[work] = i;
        }else{
            if (diffs2numbers_dict.find(i - indexes[work] - 1) == diffs2numbers_dict.end()){
                diffs2numbers_dict[i - indexes[work] - 1] = 1;
            }else{
                diffs2numbers_dict[i - indexes[work] - 1]++;
            }
            indexes[work] = i;
        }
    }
    for (auto work_index:indexes){
        if (diffs2numbers_dict.find(n - work_index.second - 1) == diffs2numbers_dict.end()) {
            diffs2numbers_dict[n - work_index.second - 1] = 1;
        }
        else{
            diffs2numbers_dict[n - work_index.second - 1]++;
        }
    }
    indexes.clear();
    std::vector<std::pair<int, int>> diff_number(diffs2numbers_dict.begin(), diffs2numbers_dict.end());
    diffs2numbers_dict.clear();
    std::sort(diff_number.begin(), diff_number.end());

    uint64_t sum = 0;
    vector<uint64_t > prefix_sum(diff_number.size(), 0);
    int len_original_a = 0;
    int prefix_i = 0;
    vector<int> prefix_index;
    prefix_index.push_back(prefix_i);
    for (int i = diff_number.size()-1; i>=0; --i){
        sum += diff_number[i].first*diff_number[i].second;
        len_original_a += diff_number[i].second;
        prefix_sum[i] = sum;
        prefix_i += diff_number[diff_number.size()-i-1].second;
        prefix_index.push_back(prefix_i);
    }

    for (uint64_t d = 1; d <= n; ++d) {
        uint64_t index = binary_search(diff_number, d);
        uint64_t D;
        if (index < diff_number.size()) {
            uint64_t taken = len_original_a - prefix_index[index];
            D = prefix_sum[index] - (d - 1) * taken;
        } else{
            D = 0;
        }
        uint64_t all_windows = unique_works * (n - d + 1);
        cout << all_windows - D << " ";
    }
}

int main(){
    ifstream myfile("test1");
    solution(myfile);
    return 0;
}

