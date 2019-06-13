//
// Created by olga on 13/06/19.
//

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> links(n);
    for (int i = 0; i < m; i++) {
        int first, second;
        cin >> first >> second;
        links[first-1].push_back(second-1);
        links[second-1].push_back(first-1);

    }

    for (auto& link : links) {
        cout << link.size() << " ";
    }
    return 0;
}