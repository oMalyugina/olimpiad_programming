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
    int number_not_null = 0;
    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < m; ++x) {
            int number;
            cin >> number;
            if (number != 0) ++number_not_null;
            if (rectangles.find(number) == rectangles.end()) {
                rectangles[number] = {x, y};
            } else
                rectangles[number].update(x, y);
        }
    }
    if (number_not_null == 1) {
        int number = 0;
        for (auto rect: rectangles) {
            if (rect.first != 0)
                number = rect.first;
        }
        for (int i = 1; i < k + 1; ++i) {
            cout << rectangles[number].left << " " << n - rectangles[number].up << " " << rectangles[number].rigth
                 << " " << n - rectangles[number].bottom << endl;
        }
    } else {
        for (int i = 1; i < k + 1; ++i) {
            cout << rectangles[i].left << " " << n - rectangles[i].up << " " << rectangles[i].rigth << " "
                 << n - rectangles[i].bottom << endl;
        }
    }
    return 0;
}

