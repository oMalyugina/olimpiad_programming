//
// Created by Olga Malyugina on 01.04.21.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int MAX_TIME = 10000;

bool is_enought(const vector<int> &data) {
    int current = 0;
    for (int i : data) {
        current += i;
        if (current == 0)
            return false;
    }
    return true;
}

bool is_additional(const vector<int> &data, const vector<vector<int>> &time_ends) {
    int current = 0;
    int smallest_end = MAX_TIME+10;
    for (int i=0; i< data.size(); i++) {
        current += data[i];

        if (current > 1){
            for( int end: time_ends[i]){
                smallest_end = min(end, smallest_end);
            }
        }else{
            smallest_end = MAX_TIME+10;
        }
        if (i == smallest_end){
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    int k;
    cin >> k;
    vector<vector<int>> time_ends(MAX_TIME, vector<int>());
    for (int i = 0; i < k; ++i) {
        int n;
        cin >> n;
        vector<int> data(MAX_TIME, 0);
        for (int j = 0; j < n; ++j) {
            int start, end;
            cin >> start >> end;
            data[start]++;
            if (end != MAX_TIME){
                data[end]--;
            }
            end--;
            time_ends[start].push_back(end);
        }
        if (not is_enought(data)) {
            cout << "Wrong Answer" << endl;
            continue;
        }
        if (is_additional(data, time_ends)) {
            cout << "Wrong Answer" << endl;
            continue;
        }
        cout << "Accepted" << endl;
    }

    return 0;
}