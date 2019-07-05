//
// Created by olga on 05/07/19.
//

#include <iostream>
#include <queue>

using namespace std;

struct Point {
    int x = 0;
    int y = 0;
    int h = 0;

    Point(int h_ = 0, int x_ = 0, int y_ = 0) : x(x_), y(y_), h(h_) {}
};

int main() {
    int h, m, n;
    cin >> h >> m >> n;
    int field[h][m][n];
    Point start, finish;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < n; ++k) {
                char cell;
                cin >> cell;
                if (cell == 'o') field[i][j][k] = -1;
                else {
                    field[i][j][k] = 0;
                    if (cell == '1') {
                        start = Point(i, j, k);
                        field[i][j][k] = 1;
                    }
                    if (cell == '2') finish = Point(i, j, k);
                }
            }
        }
    }
    queue<Point> to_see;
    to_see.push(start);
    while (not to_see.empty() and field[finish.h][finish.x][finish.y] == 0) {
        Point cur = to_see.front();
        to_see.pop();

        if (cur.h < h - 1 and field[cur.h + 1][cur.x][cur.y] == 0) {
            field[cur.h + 1][cur.x][cur.y] = field[cur.h][cur.x][cur.y] + 1;
            to_see.push(Point(cur.h + 1, cur.x, cur.y));
        }
        if (cur.x < m - 1 and field[cur.h][cur.x + 1][cur.y] == 0) {
            field[cur.h][cur.x + 1][cur.y] = field[cur.h][cur.x][cur.y] + 1;
            to_see.push(Point(cur.h, cur.x + 1, cur.y));
        }
        if (cur.x > 0 and field[cur.h][cur.x - 1][cur.y] == 0) {
            field[cur.h][cur.x - 1][cur.y] = field[cur.h][cur.x][cur.y] + 1;
            to_see.push(Point(cur.h, cur.x - 1, cur.y));
        }
        if (cur.y < n - 1 and field[cur.h][cur.x][cur.y + 1] == 0) {
            field[cur.h][cur.x][cur.y + 1] = field[cur.h][cur.x][cur.y] + 1;
            to_see.push(Point(cur.h, cur.x, cur.y + 1));
        }
        if (cur.y > 0 and field[cur.h][cur.x][cur.y - 1] == 0) {
            field[cur.h][cur.x][cur.y - 1] = field[cur.h][cur.x][cur.y] + 1;
            to_see.push(Point(cur.h, cur.x, cur.y - 1));
        }

    }
    cout << field[finish.h][finish.x][finish.y] * 5 - 5;
    return 0;

}

