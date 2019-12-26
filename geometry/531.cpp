//
// Created by olga on 21/09/19.
//

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;


struct Pos{
    int x;
    int y;

    Pos (int _x, int _y): x(_x),y(_y) {}
    Pos() = default;
};

int main(){
    long long x_bottom, y_right, x_up, y_left;
    cin >> x_bottom >> y_right >> x_up >> y_left;
    if (x_bottom > x_up) swap(x_bottom, x_up);
    if (y_left > y_right) swap(y_left, y_right);

    long long x_centre, y_centre, r;
    cin >> x_centre>> y_centre >> r;

    x_bottom -= x_centre;
    x_up -= x_centre;
    y_left -= y_centre;
    y_right -= y_centre;

    long long rr = r*r;

    long long count = 0;
    long long y = 0;
    for (long long x = max(-r, x_bottom); x <= min(r, x_up); ++x){
//        double s = pow(rr-pow(x,2),1./2);
        long long circle_up = static_cast<long>(floor(pow(rr - pow(x, 2), 1. / 2)));
//        while (x*x + (y+1)*(y+1) <= rr){
//            ++y;
//        }
//        while (x*x + y*y > rr){
//            --y;
//        }
//        if (x_bottom <= x && x <= x_up ){
//            count += max(min(y_right, y) - max(y_left, -y) + 1, 0LL);
//        }
//        long a = min(y_right, circle_up);
//        long b = max(y_left, -circle_up);
        long long y = max(min(y_right, circle_up) - max(y_left, -circle_up) + 1, 0LL);
        count += y;
    }

    cout<< count;
}