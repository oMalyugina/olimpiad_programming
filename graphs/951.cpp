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

    Point() {};

    Point(int x_, int y_) {
        x = x_;
        y = y_;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    int field[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            field[i][j] = 0;
        }
    }
    int number_healf = n * m;
    int number_points;
    cin >> number_points;
    number_healf -= number_points;
    vector<Point> points;
    for (int i = 0; i < number_points; i++) {
        int x, y;
        cin >> x >> y;
        Point point;
        point.x = x-1;
        point.y = y-1;
        points.push_back(point);
        field[point.x][point.y] = 1;
    }
    vector<Point> new_points;
    int step = 0;
    while (number_healf != 0) {
        step++;
        while (points.size() != 0) {
            Point cur = points[0];
            points.erase(points.begin());
            field[cur.x][cur.y] = 2;
            vector<Point> neigbors;
            if (cur.x > 0) neigbors.emplace_back(cur.x - 1, cur.y);
            if (cur.y > 0) neigbors.emplace_back(cur.x, cur.y - 1);
            if (cur.x < n - 1) neigbors.emplace_back(cur.x + 1, cur.y);
            if (cur.y < m - 1) neigbors.emplace_back(cur.x, cur.y + 1);
            for (auto point:neigbors) {
                if (field[point.x][point.y] == 0) {
                    field[point.x][point.y] = 1;
                    new_points.push_back(point);
                    number_healf--;
                }
            }
        }
        points = new_points;
        new_points.clear();
    }
    cout << step;
    return 0;
}