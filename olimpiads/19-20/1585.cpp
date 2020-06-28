//
// Created by Olga Malyugina on 02.05.20.
//

#include<iostream>
#include<vector>
#include <queue>

using namespace std;

struct Point{
    long x;
    long y;
    Point(long x, long y){
        this->x = x;
        this->y = y;
    }
};

vector<Point> get_neighbors(const Point point, vector<vector<bool>> &seen, const vector<vector<bool>>& map) {
    vector<Point> possible_neighbors;
    possible_neighbors.emplace_back(point.x-1, point.y);
    possible_neighbors.emplace_back(point.x+1, point.y);
    possible_neighbors.emplace_back(point.x, point.y-1);
    possible_neighbors.emplace_back(point.x, point.y+1);
    vector<Point> neighbors;
    for(Point n:possible_neighbors){
        if (!map[n.x][n.y]){
            neighbors.push_back(n);
            continue;
        }
        if (seen[n.x][n.y])
            continue;
        neighbors.push_back(n);
        seen[n.x][n.y] = true;
    }
    return neighbors;
}

int main(){
    int N;
    cin >> N;
    vector<vector<long>> points(N, vector<long>(2,0));
    long min_x = 2000000000, min_y=2000000000;
    for (int i = 0; i < N; ++i) {
        cin >> points[i][0];
        cin >> points[i][1];
        min_x = min(min_x, points[i][0]);
        min_y = min(min_y, points[i][1]);
    }
    long max_x = -1, max_y=-1;
    for (int i = 0; i < N; ++i) {
        points[i][0] -= min_x-2;
        points[i][1] -= min_y-2;
        max_x = max(max_x, points[i][0]);
        max_y = max(max_y, points[i][1]);
    }
    vector<vector<bool>> map(max_x+4, vector<bool>(max_y+4, false));
    vector<vector<bool>> seen(max_x+4, vector<bool>(max_y+4, false));
    for (int i = 0; i < N; ++i) {
        map[points[i][0]][points[i][1]] = true;
    }
    long long number_boards = 0;
    queue<Point> to_see;
    to_see.emplace(points[0][0], points[0][1]);
    seen[to_see.back().x][to_see.back().y]=true;
    while (! to_see.empty()){
        Point current = to_see.front();
        to_see.pop();
        vector<Point> neighbors = get_neighbors(current, seen, map);
        for (Point neighbor: neighbors) {
            if (!map[neighbor.x][neighbor.y])
                number_boards++;
            else
                to_see.push(neighbor);
        }
    }
    cout << number_boards;
    return 0;
}

