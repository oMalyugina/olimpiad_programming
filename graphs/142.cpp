//
// Created by Olga Malyugina on 12.02.21.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

struct Edge {
    int v1;
    int v2;
    int w;

    Edge(int _v1, int _v2, int _w) : v1(_v1), v2(_v2), w(_w) {};

    Edge() = default;

};

inline bool operator<(const Edge& lhs, const Edge& rhs)
{
    if (lhs.w == rhs.w){
        if (lhs.v1 == rhs.v1){
            return lhs.v2 < rhs.v2;
        }
        return lhs.v1 < rhs.v1;
    }
    return lhs.w < rhs.w;
}

int main(){
    int n, m;
    cin >> n >> m;
    set<Edge> edges;
    for (int i = 0; i < m; ++i) {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        Edge tmp1(v1, v2, w);
        edges.insert(tmp1);
    }
    set<int> choosen_vertexis;
    set<set<int>> in_process;
    map<int, int> vertex2set_number;
    while (choosen_vertexis.size()<n and not edges.empty()){
        auto next_edge_p = edges.begin();
        edges.erase(next_edge_p);
        Edge next_edge = *next_edge_p;
        bool is_found = false;
        int v1_set = -1;
        int v2_set = -1;
        for (int i = 0; i < in_process.size(); ++i) {
            set<int> vertex_set = in_process[i];
            if (vertex_set.find(next_edge.v1) != vertex_set.end() and vertex_set.find(next_edge.v1) != vertex_set.end()){
                is_found = true;
                break;
            }
            if (vertex_set.find(next_edge.v1) == vertex_set.end() and vertex_set.find(next_edge.v1) == vertex_set.end()){
                continue;
            }
            if (vertex_set.find(next_edge.v1) != vertex_set.end()){
                v1_set = i;
            }
            if (vertex_set.find(next_edge.v2) != vertex_set.end()){
                v2_set = i;
            }
        }
        if (is_found == false and v1_set == -1 and v2_set == -1){
            set<int> tmp;
            tmp.insert(next_edge.v1);
            tmp.insert(next_edge.v2);
            in_process.push_back(tmp);
        }


    }

    return 0;
}


//int main() {
//    int n, m;
//    cin >> n >> m;
//    vector<set<Edge>> edges(n + 1, set<Edge>());
//    for (int i = 0; i < m; ++i) {
//        int v1, v2, w;
//        cin >> v1 >> v2 >> w;
//        Edge tmp1(v1, v2, w);
//        Edge tmp2(v2, v1, w);
//        edges[v1].insert(tmp1);
//        edges[v2].insert(tmp2);
//    }
//
//
//    set<Edge> current_edges;
//    vector<Edge> choosen;
//    int res = 0;
//    set<int> seen;
//    seen.insert(1);
//    for (Edge edge:edges[1]) {
//        current_edges.insert(edge);
//    }
//    while (not current_edges.empty()) {
//        bool found = false;
//        Edge next_edge{};
//        while (not current_edges.empty() and not found) {
//            auto next_edge_p = current_edges.begin();
//            current_edges.erase(next_edge_p);
//            next_edge = *next_edge_p;
//            int next_vertex = next_edge.v2;
//            if (seen.find(next_vertex) == seen.end()) {
//                found = true;
//                choosen.push_back(next_edge);
//                res += next_edge.w;
//                seen.insert(next_vertex);
//                for (Edge edge:edges[next_vertex]) {
//                    if (seen.find(edge.v2) == seen.end())
//                        current_edges.insert(edge);
//                }
//            }
//        }
//    }
//
//    cout << res;
//
//    return 0;
//}