//
// Created by Olga Malyugina on 27.01.21.
//

#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <set>
#include <string>
#include <fstream>
#include <streambuf>
#include <sstream>


using namespace std;

int find_vertex_with_odd_edges(map<int, set<int>> &edges) {
    for (const auto &vertex2edges:edges) {
        if (vertex2edges.second.size() % 2 == 1)
            return vertex2edges.first;
    }
    return -1;
}

int one_edge(map<int, set<int>> &edges) {
    for (const auto &vertex2edges:edges) {
        if (not vertex2edges.second.empty())
            return vertex2edges.first;
    }
    return -1;
}

vector<int> find_euler_path(map<int, set<int>> &edges, int start) {
    vector<int> path;
    stack<int> seen;
    seen.push(start);
    while (not seen.empty()) {
        if (edges[seen.top()].empty()) {
            path.push_back(seen.top());
            seen.pop();
        } else{
            int next_vertex = * edges[seen.top()].begin();
            edges[seen.top()].erase(next_vertex);
            edges[next_vertex].erase(seen.top());
            seen.push(next_vertex);
        }
    }
    return path;
}




int main() {

//    fstream file_input("test1.txt", fstream::in );
//    string input;
//    getline( file_input, input, '\0');
//    stringstream ss;
//    ss.str(input);
    int n, m;
    cin >> n >> m;
    map<int, set<int>> edges;
    for (int i = 0; i < n; ++i) {
        set<int> tmp;
        edges[i] = tmp;
    }
    for (int j = 0; j < m; ++j) {
        int s, e;
        cin >> s >> e;
        s--;
        e--;
        edges[s].insert(e);
        edges[e].insert(s);
    }
    if (m == 0) {
        cout << 0;
        return 0;
    }
    int res = 0;
    while (one_edge(edges) >= 0) {
        res++;
        int vertex_with_odd_edges = find_vertex_with_odd_edges(edges);
        if (vertex_with_odd_edges>=0) {
            vector<int> edges_in_path = find_euler_path(edges, vertex_with_odd_edges);
        }
        else{
            int random_edge = one_edge(edges);
            vector<int> edges_in_path = find_euler_path(edges, random_edge);
        }
    }
    cout << res;
}


