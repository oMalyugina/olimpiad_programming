//
// Created by Olga Malyugina on 18.03.21.
//

#include <iostream>
#include <vector>

using namespace std;

void update(vector<vector<int>> &fenvic, int x_start, int y_start) {
    for (int x = x_start; x < fenvic.size(); x = x | (x + 1)) {
        for (int y=y_start; y < fenvic.size(); y = y | (y + 1)) {
            fenvic[x][y]++;
        }
    }
}

int summ(vector<vector<int>> &fenvic, int r_start, int down_start) {
    int res = 0;
    for (int r = r_start; r >= 0; r = (r & (r + 1)) - 1) {
        for (int down = down_start; down >= 0; down = (down & (down + 1)) - 1) {
            res += fenvic[r][down];
        }
    }
    return res;
}

int summ(vector<vector<int>> &fenvic, int l, int up, int r, int down) {
    return summ(fenvic, r, down) - summ(fenvic, l - 1, down) -
           summ(fenvic, r, up - 1) + summ(fenvic, l - 1, up - 1);
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> fenvic(n, vector<int>(n, 0));
    for (int i = 0; i < k; ++i) {
        string command;
        cin >> command;
        if (command == "add") {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            update(fenvic,x,y);
        } else {
            int l, up, r, down;
            cin >> l >> up >> r >> down;
            l--;
            up--;
            r--;
            down--;
            cout << summ(fenvic, l, up, r, down) << endl;
        }
    }
    return 0;
}