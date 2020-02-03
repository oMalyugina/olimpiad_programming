//
// Created by olga on 02/02/20.
//

#include <iostream>
#include <set>
#include <vector>
#include <cmath>


class Point {
public:
    double x;
    double y;

    Point(int x_ = 0, int y_ = 0) : x{x_}, y{y_} {};
};

double distance(Point a, Point b){
    return pow((a.x - b.x),2)+pow((a.y - b.y), 2);
}

using namespace std;

int main() {
    int N;
    cin >> N;
    set<double> distances;
    vector<Point> points;
    for (int i = 0; i < N; ++i) {
        double x, y;
        cin >> x >> y;
        points.emplace_back(x,y);
    }
    for (int j = 0; j < N; ++j) {
        for (int i = j+1; i < N; ++i) {
            distances.insert(distance(points[j], points[i]));
        }
    }
    cout.precision(20);
    cout << distances.size() << endl;
    for (auto d:distances){
        cout << sqrt(d) << endl;
    }
    return 0;
}