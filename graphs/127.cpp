//
// Created by olga on 21/06/19.
//
#include <iostream>
#include <vector>
using std::vector;

int main(){
    int n;
    std::cin >> n;
    vector<vector<int>> edges;
    int seen[n];
    for (int k = 0; k < n; ++k) {
        vector<int> a;
        edges.push_back(a);
        seen[k] = 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int a;
            std::cin >> a;
            if (a == 1){
                edges[i].push_back(j);
            }
        }
    }
    int from, to;
    std::cin >> from >> to;
    from--;
    to--;
    vector<int> to_see;
    to_see.push_back(from);
    seen[from] = 1;
    int step = 0;
    while (seen[to] == 0 and not to_see.empty()){
        vector<int> new_to_see;
        step++;
        for (const auto &vertex : to_see) {
            for (const auto &adj_vertex : edges[vertex]) {
                if (seen[adj_vertex] == 0){
                    seen[adj_vertex] = 1;
                    new_to_see.push_back(adj_vertex);
                }
            }
        }
        to_see = new_to_see;
    }
    if (seen[to] == 1) std::cout << step;
    else std::cout << "-1";
    return 0;
}