//
// Created by olga on 18/08/19.
//

#include <iostream>
#include <map>
#include <cmath>
using namespace std;


struct Point{
    int x;
    int y;
    float tg;
    int virtel;

    Point(int x_=0, int y_=0): x(x_), y(y_){
        if (y == 0) tg = 200;
        else tg = x*1./y;
        if (x >= 0 and y >= 0) virtel = 1;
        else if (x < 0 and y >= 0) virtel = 2;
        else if (x < 0 and y < 0) virtel = 3;
        else if (x >= 0 and y < 0) virtel = 4;
        else virtel = 0;
    }
};

bool operator!=(Point first, Point second){
    if (first.tg != second.tg) return true;
    return first.virtel != second.virtel;
}

bool operator<(Point first, Point second){
    if (first.virtel == second.virtel) return first.tg < second.tg;
    return first.virtel < second.virtel;
}

int main(){
    int n;
    cin >> n;
    map<Point, int> targets;
    for (int i = 0; i < n; ++i) {
        int x,y;
        cin >> x >> y;
        if (x == 0 and y == 0) continue;
        Point tmp(x,y);
        if (targets.find(tmp) != targets.end()) targets[tmp] += 1;
        else targets[tmp] = 1;
    }
    cout << targets.size();
}
