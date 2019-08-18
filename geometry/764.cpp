//
// Created by olga on 09/08/19.
//


#include <iostream>
#include <map>
#include <cmath>
using namespace std;


struct Point{
    int x;
    int y;
    float tg;
    bool upDown;

    Point(int x_=0, int y_=0): x(x_), y(y_){
        if (y == 0) tg = 200;
        else tg = x*1./y;
        upDown = x>=0;
    }
};

bool operator!=(Point first, Point second){
    if (first.tg != second.tg) return true;
    return first.upDown != second.upDown;
}

bool operator<(Point first, Point second){
    if (first.upDown == second.upDown) return first.tg < second.tg;
    return first.upDown;
}

int main(){
    int n;
    cin >> n;
    map<Point, int> targets;
    for (int i = 0; i < n; ++i) {
        int x,y;
        cin >> x >> y;
        Point tmp(x,y);
        if (targets.find(tmp) != targets.end()) targets[tmp] += 1;
        else targets[tmp] = 1;
    }
    int max = 0;
    for (const auto &item : targets) {
        if (item.second > max) max = item.second;
    }
    cout << max;
}
