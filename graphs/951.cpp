//
// Created by olga on 20/06/19.
//

#include<iostream>

using std::cin;
using std::cout;

#include<vector>

using std::vector;

struct Point {
    int x;
    int y;

    Point(int x_, int y_) : x(x_), y(y_) {};
};

int main() {
    int n, m;
    cin >> n >> m;
    bool field[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            field[i][j] = true;
        }
    }
    int number_points;
    cin >> number_points;
    vector<Point> points;
    for (int i = 0; i < number_points; i++) {
        int x, y;
        cin >> x >> y;
        Point point(x - 1, y - 1);
        if (field[point.x][point.y]) {
            points.push_back(point);
            field[point.x][point.y] = false;
        }
    }
    vector<Point> new_points;
    int step = 0;
    while (!points.empty()) {
        step++;
        while (!points.empty()) {
            Point cur = points.back();
            points.pop_back();

            if (cur.x > 0 and field[cur.x - 1][cur.y]) {
                new_points.emplace_back(cur.x - 1, cur.y);
                field[cur.x - 1][cur.y] = false;
            }
            if (cur.y > 0 and field[cur.x][cur.y - 1]) {
                new_points.emplace_back(cur.x, cur.y - 1);
                field[cur.x][cur.y - 1] = false;
            }
            if (cur.x < n - 1 and field[cur.x + 1][cur.y]) {
                new_points.emplace_back(cur.x + 1, cur.y);
                field[cur.x + 1][cur.y] = false;
            }
            if (cur.y < m - 1 and field[cur.x][cur.y + 1]) {
                new_points.emplace_back(cur.x, cur.y + 1);
                field[cur.x][cur.y + 1] = false;
            }
        }
        points = new_points;
        new_points.clear();
    }
    cout << --step;
    return 0;
}