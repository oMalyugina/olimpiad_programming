//
// Created by olga on 02/02/20.
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> monk(N, 0);
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        monk[i] = tmp;
    }
    int m;
    cin >> m;
    map<int, int> changes;
    for (int i = 0; i < m; ++i) {
        int from, to;
        cin >> from >> to;
        changes[from] = to;
    }
    for (int i = 0; i < N; ++i) {
        if (changes.find(monk[i]) == changes.end())
            cout << monk[i] << " ";
        else
            cout << changes[monk[i]] << " ";
    }
    return 0;
}