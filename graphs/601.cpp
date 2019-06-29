//
// Created by olga on 28/06/19.
//

#include <iostream>
#include <vector>

using namespace std;

struct Corridor {
    int destination;
    int color;

    Corridor(int dest_, int color_) {
        destination = dest_;
        color = color_;
    }
};

int main() {

    int n_room, n_corridor;
    cin >> n_room >> n_corridor;
    vector<vector<Corridor>> corridors;
    for (int i = 0; i <= n_room; ++i) {
        vector<Corridor> tmp;
        corridors.push_back(tmp);
    }
    for (int corridor = 0; corridor < n_corridor; ++corridor) {
        int from, to, color;
        cin >> from >> to >> color;

        corridors[from].push_back(Corridor(to, color));
        corridors[to].push_back(Corridor(from, color));
    }
    int len_way;
    cin >> len_way;
    int cur_room = 1;
    for (int step = 0; step < len_way; ++step) {
        int cur_color;
        bool find = false;
        cin >> cur_color;
        for (auto corridor  : corridors[cur_room]) {
            if (corridor.color == cur_color) {
                cur_room = corridor.destination;
                find = true;
                break;
            }
        }
        if (not find){
                    cout << "INCORRECT";
                    return 0;
        }
    }
    cout << cur_room;
    return 0;
}