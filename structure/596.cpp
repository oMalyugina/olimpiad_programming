//
// Created by olga on 03/02/20.
//

#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

class Point {
public:
    double x;
    double y;

    Point(double x_ = 0, double y_ = 0) : x{x_}, y{y_} {};
};

double distance(Point a, Point b){
    return sqrt(pow((a.x - b.x),2)+pow((a.y - b.y), 2));
}

int main() {
    int N;
    cin >> N;
    vector<string> names;
    vector<Point> points;
    vector<int> r_s;
    for (int i = 0; i < N; ++i) {
        string name;
        cin >> name;
        names.push_back(name);
        int x,y,r;
        cin >> x >> y >> r;
        points.emplace_back(x, y);
        r_s.push_back(r);
    }
    int x,y;
    cin >> x >> y;
    Point human(x, y);
    map<string, int> counter;
    for (int i = 0; i < N; ++i) {
        counter[names[i]] = 0;
    }
    for (int i = 0; i < N; ++i) {
        if (distance(points[i], human) <=r_s[i]) counter[names[i]]++;
    }
    cout << counter.size() << endl;
    for (int i = 0; i < N; ++i) {
        if (counter.find(names[i]) == counter.end()) continue;
        cout << names[i] << " " << counter[names[i]];
        counter.erase(names[i]);
        cout << endl;
    }
    return 0;
}