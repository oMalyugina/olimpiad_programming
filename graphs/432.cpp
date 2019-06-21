//
// Created by olga on 21/06/19.
//

#include <iostream>
#include<vector>

using std::vector;

struct Point {
    int x;
    int y;

    Point(int x_, int y_) : x(x_), y(y_) {};
};


int main() {
    int n, m;
    std::cin >> n >> m;
    int field[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            std::cin >> c;
            if (c == '#') field[i][j] = 1;
            if (c == '.') field[i][j] = 0;
        }
    }
    int step = 0;
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            if (field[x][y] != 1) continue;
            step++;
            vector<Point> in_one_link;
            in_one_link.emplace_back(x, y);
            while (not in_one_link.empty()) {
                Point cur = in_one_link.back();
                in_one_link.pop_back();
                if (x > 0 and field[x - 1][y] == 1) {
                    in_one_link.emplace_back(cur.x - 1, cur.y);
                    field[cur.x - 1][cur.y] = 2;
                }
                if (cur.y > 0 and field[cur.x][cur.y - 1] == 1) {
                    in_one_link.emplace_back(cur.x, cur.y - 1);
                    field[cur.x][cur.y - 1] = 2;
                }
                if (cur.x < n - 1 and field[cur.x + 1][cur.y] == 1) {
                    in_one_link.emplace_back(cur.x + 1, cur.y);
                    field[cur.x + 1][cur.y] = 2;
                }
                if (cur.y < m - 1 and field[cur.x][cur.y + 1] == 1) {
                    in_one_link.emplace_back(cur.x, cur.y + 1);
                    field[cur.x][cur.y + 1] = 2;
                }
            }
        }
    }
    std::cout << step;
    return 0;
}