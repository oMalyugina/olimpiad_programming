//
// Created by olga on 03/07/19.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int number_vertex;
    cin >> number_vertex;
    vector<vector<int>> edges(number_vertex, vector<int>(number_vertex, 0));
    int sum = 0;
    for (int i = 0; i < number_vertex; ++i) {
        for (int j = 0; j < number_vertex; ++j) {
            int x;
            cin >> x;
            edges[i][j] = x;
            sum += x;
        }
    }
    vector<int> vertices(number_vertex, 0);
    vector<int> to_see;
    to_see.push_back(0);
    vertices[0] = 1;
    while (not to_see.empty()) {
        int cur = to_see.back();
        int count_seen = 0;
        for (int i = 0; i < number_vertex; ++i) {
            if (edges[cur][i] == 1) {
                if (vertices[i] != 0) continue;
                to_see.push_back(i);
                vertices[i] = 1;
                ++count_seen;
            }
        }
        if (count_seen == 0) {
            to_see.pop_back();
            vertices[cur] = 2;
        }
    }
    for (auto vertex  : vertices) {
        if (vertex == 0) {
            cout << "NO";
            return 0;
        }
    }
    if (vertices.size() -1 != sum/2) cout << "NO";
    else cout << "YES";
    return 0;
}

