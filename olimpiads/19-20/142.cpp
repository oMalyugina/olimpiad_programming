//
// Created by Olga Malyugina on 04.03.21.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct Edge{
    int v1;
    int v2;
    int w;
    Edge(int v1_, int v2_, int w_): v1(v1_), v2(v2_), w(w_){};
    Edge() = default;
};


bool dfs(int v, vector<int>& colors,  vector<vector<bool>> & edges) {
    colors[v] = 1;
    for (int i = 0; i < colors.size(); ++i) {
        if (i == v)
            continue;
        if (edges[v][i] == 0)
            continue;
        if (colors[i] == 0) {
            edges[v][i] = false;
            edges[i][v] = false;
            if (dfs(i, colors, edges)) {
                edges[v][i] = true;
                edges[i][v] = true;
                return true;
            }
            edges[v][i] = true;
            edges[i][v] = true;
        }
        if (colors[i] == 1)
            return true;
    }
    colors[v] = 2;
    return false;
}

bool operator<(Edge edge1, Edge edge2){
    if (edge1.w == edge2.w){
        if (edge1.v1 == edge2.v1){
            return edge1.v2 < edge2.v2;
        }
        return edge1.v1 < edge2.v1;
    }
    return edge1.w < edge2.w;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<bool>> chosen_edges(n, vector<bool>(n, false));
    set<Edge> all_edges;
    for (int i = 0; i < m; ++i) {
        int s,e,w;
        cin >> s >> e >> w;
        s--;
        e--;
        Edge tmp(s,e,w);
        all_edges.insert(tmp);
    }
    int res = 0;
    while (not all_edges.empty()){
        auto min_edge_p = all_edges.begin();
        Edge min_edge = *min_edge_p;
        chosen_edges[min_edge.v1][min_edge.v2] = true;
        chosen_edges[min_edge.v2][min_edge.v1] = true;
        res += min_edge.w;
        vector<int> colors(n, 0);
        if (dfs(min_edge.v1, colors, chosen_edges)){
            chosen_edges[min_edge.v1][min_edge.v2] = false;
            chosen_edges[min_edge.v2][min_edge.v1] = false;
            res -= min_edge.w;
        }
        all_edges.erase(min_edge_p);
    }
    cout << res;
    return 0;
}