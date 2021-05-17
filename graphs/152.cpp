//
// Created by Olga Malyugina on 09.04.21.
//

#include <iostream>
#include <vector>

using namespace std;

struct DFS {
    vector<int> color;
    int n;

    DFS(int n_) : n(n_) {
        color.assign(n, 0);
    }
};

bool dfs(DFS &info, const vector<vector<int>> &edges, int current, int parent) {
    info.color[current] = 1;
    for (int neightbor:edges[current]) {
        if (info.color[neightbor] == 1)
            return true;
        if (info.color[neightbor] == 2)
            continue;
        if (info.color[neightbor] == 0) {
            bool res = dfs(info, edges, neightbor, current);
            if (res)
                return true;
        }
    }
    info.color[current] = 2;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n, vector<int>());
    DFS info(n);
    for (int i = 0; i < m; ++i) {
        int s, e;
        cin >> s >> e;
        s--;
        e--;
        edges[s].push_back(e);
    }
    for (int j = 0; j < n; ++j) {
        if (info.color[j] == 0) {
            bool res = dfs(info, edges, j, -1);
            if (res) {
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes";
    return 0;
}