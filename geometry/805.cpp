//
// Created by olga on 24/08/19.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Plane {
    long long x, y, s;
};

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<Plane> planes;
    long long max_x = -1000000, max_y = -1000000;
    for (int i = 0; i < n; ++i) {
        Plane tmp{};
        cin >> tmp.x >> tmp.y >> tmp.s;
        planes.push_back(tmp);
        if (tmp.x > max_x) max_x = tmp.x;
        if (tmp.y > max_y) max_y = tmp.y;
    }
    long long min_x = 10000000000;
    for (auto plane  : planes) {
        long long x_k = plane.x - max_y + plane.y + plane.s;
        if (x_k < max_x){
            min_x = max_x;
            break;
        }
        min_x = min(min_x, x_k);
    }
    double min_square = (min_x - max_x)*1. / 2 * (min_x - max_x);

    cout << fixed << setprecision(3);

    cout << min_square;
}