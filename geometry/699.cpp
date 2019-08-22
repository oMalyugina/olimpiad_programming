//
// Created by olga on 22/08/19.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point{
    int x;
    int y;
    int r;
};

double distance(Point p1, Point p2){
    double free_space = sqrt(pow((p1.x-p2.x),2) + pow((p1.y-p2.y),2)) - (p1.r+p2.r);
    return free_space/2;
}

int main(){
    int k, t;
    cin >> k >> t;
    vector<Point> points;
    for (int i = 0; i < k; ++i) {
        Point tmp;
        cin >> tmp.x >> tmp.y >> tmp.r;
        points.push_back(tmp);
    }

    double min_time = t;
    for (int j = 0; j < k; ++j) {
        for (int i = j+1; i < k; ++i) {
            double d = distance(points[i], points[j]);
            if (d < min_time){
                min_time = d;
            }
        }
    }
    cout << min_time;
}