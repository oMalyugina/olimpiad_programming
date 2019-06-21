//
// Created by olga on 21/06/19.
//

#include <iostream>
#include<vector>

using std::vector;


void fill(vector<vector<int>> &field, int x, int y){
    if (x < 0 or y < 0 or x >= field.size() or y >= field[0].size()) return;
    if (field[x][y] != 0) return;
    field[x][y]=1;
    fill(field, x-1, y);
    fill(field, x, y-1);
    fill(field, x, y+1);
    fill(field, x+1, y);
}

int main() {
    int n,m;
    vector<vector<int>> field;
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        vector<int> raw;
        for (int j = 0; j < m; ++j) {
            char c;
            std::cin >> c;
            if (c == '#') raw.push_back(0);
            if (c == '.') raw.push_back(1);
        }
        field.push_back(raw);
    }
    int step = 0;
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            if (field[x][y] == 1) continue;
            step++;
            fill(field, x, y);
        }
    }
    std::cout << step;
    return 0;
}