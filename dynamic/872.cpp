//
// Created by olga on 21/01/20.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

bool comporator(string one, string two){
    return one.size()<two.size();
}

int main(){
    int N;
    cin >> N;
    vector<string> words;
    map<string, int> seen_pair;
    for (int i = 0; i < N; ++i) {
        string tmp;
        cin >> tmp;
        words.push_back(tmp);
    }
    sort(words.begin(), words.end(), comporator);

    int best_count = 0;
    for (const string &word:words){
        int count = 1;
        for (const auto &seen:seen_pair){
            if (word.size() <= seen.first.size()) continue;
            auto res = std::mismatch(seen.first.begin(), seen.first.end(), word.begin());
            if (res.first == seen.first.end())
            {
                count = max(count, seen.second+1);
            }

        }
        seen_pair[word]=count;
        best_count = max(best_count, count);
    }
    cout << best_count;

    return 0;
}