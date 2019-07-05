//
// Created by olga on 05/07/19.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;


int main() {
    int n, from, to;
    cin >> n >> from >> to;
    --from;
    --to;
    vector<vector<pair<int ,int>>> edge;
    for (int i = 0; i < n; ++i) {
        vector<pair<int ,int>> raw;
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            if (i == j) continue;
            if (x != -1){
                pair<int, int> tmp2(j, x);
                raw.push_back(tmp2);
            }
        }
        edge.push_back(raw);
    }
    int max_cost = 5000000;
    vector<int> cost_for_path(n, max_cost);
    map<int, int> to_seen; // numbert: cost
    to_seen[from] = 0;
    cost_for_path[from] = 0;
    while (not to_seen.empty()) {
        int curr = -1;
        int min = max_cost;
        for (auto vertex : to_seen) {
            if (vertex.second < min) curr = vertex.first;
        }

        to_seen.erase(curr);
        for(auto neigbor: edge[curr]){
            if (cost_for_path[neigbor.first] > cost_for_path[curr] + neigbor.second) {
                cost_for_path[neigbor.first] = cost_for_path[curr] + neigbor.second;
                to_seen[neigbor.first] = cost_for_path[neigbor.first];
            }
        }
    }
    if (cost_for_path[to] == max_cost) cout << "-1";
    else cout << cost_for_path[to];
    return 0;
}