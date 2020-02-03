//
// Created by olga on 03/02/20.
//

#include <iostream>
#include <map>

using namespace std;

class Rectangle {
public:
    int left;
    int rigth;
    int bottom;
    int up;
    Rectangle() = default;

    Rectangle(int x, int y) {
        left = x;
        rigth = x + 1;
        bottom = y;
        up = y + 1;
    }

    void update(int x, int y) {
        if (x + 1 > rigth) rigth = x + 1;
        if (x < left) left = x;
        if (y < bottom) bottom = y;
        if (y + 1 > up) up = y + 1;
    }
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    map<int, Rectangle> rectangles;
    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < m; ++x) {
            int number;
            cin >> number;
            if (rectangles.find(number) == rectangles.end()) {
                rectangles[number] = {x,y};
            } else
                rectangles[number].update(x, y);
        }
    }
    for (int i = 1; i < k + 1; ++i) {
        if (rectangles.find(i) == rectangles.end())
            continue;
        cout << rectangles[i].left << " " << n - rectangles[i].up << " " << rectangles[i].rigth << " "
             << n - rectangles[i].bottom;
        cout << endl;
    }
    return 0;
}

