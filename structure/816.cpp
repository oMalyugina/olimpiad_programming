//
// Created by olga on 03/02/20.
//

#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
    int m, n, k;
    cin >> m >> n >> k;
    vector<set<int>> sets(n + 1);
    for (int i = 0; i < k; ++i) {
        string command;
        cin >> command;
        if (command == "ADD") {
            int n_set, element;
            cin >> element >> n_set;
            sets[n_set].insert(element);
        } else if (command == "LISTSET") {
            int n_set;
            cin >> n_set;
            for (int el: sets[n_set]) {
                cout << el << " ";
            }
            if (sets[n_set].empty())
                cout << -1;
            cout << endl;
        } else if (command == "LISTSETSOF") {
            int el;
            cin >> el;
            vector<int> res;
            for (int j = 0; j < n + 1; ++j) {
                if (sets[j].find(el) != sets[j].end()) res.push_back(j);
            }
            for (int el: res) {
                cout << el << " ";
            }
            if (res.empty())
                cout << -1;
            cout << endl;
        }
    }

    return 0;
}