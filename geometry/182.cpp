//
// Created by olga on 18/08/19.
//

#include <iostream>
#include <cmath>

using namespace std;

struct Point{
    int x;
    int y;

    explicit Point(int x_=0, int y_=0): x(x_), y(y_){}
};

double distance(Point first, Point second){
    return sqrt(pow((first.x - second.x),2) + pow((first.y - second.y), 2));
}

int main(){
    Point points[3];
    for (auto &point : points) {
        int x, y;
        cin >> x >> y;
        point = Point(x,y);
    }

    double max_ = 0;
    int max_index;
    for (int i = 0; i < 3; ++i) {
        int second_index = i==0?2:i-1;
        double distance_i = distance(points[i], points[second_index]);
        if (distance_i > max_){
            max_index = (i+1)%3;
            max_ = distance_i;
        }
    }
    swap(points[0], points[max_index]);
    float centre_x = (points[1].x + points[2].x)*1./2;
    float centre_y = (points[1].y + points[2].y)*1./2;
    int new_x = 2*centre_x - points[0].x;
    int new_y = 2*centre_y - points[0].y;
    cout << new_x << " " << new_y;
}