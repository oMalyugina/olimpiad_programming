//
// Created by Olga Malyugina on 05.02.21.
//

#include <iostream>
#include <time.h>
#include <random>
#include <vector>
using namespace std;

void print(const vector<vector<int>> & map){
    for (int i = 0; i < map.size(); ++i) {
        for (int j = 0; j < map[0].size(); ++j) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

int how_bad(const vector<vector<int>> & map){
    int res = 0;
    for (int l = 0; l < map.size() - 1; ++l) {
        for (int r = l+1; r < map.size(); ++r) {
            for (int down = 0; down < map[0].size()-1; ++down) {
                for (int up = down+1; up < map[0].size(); ++up) {
                    if(map[r][down] == map[r][up] and map[r][down] == map[l][down] and map[r][down] == map[l][up])
                        res++;
                }
            }
        }
    }
    return res;
}

vector<vector<int>> change(const vector<vector<int>> & map, int c, float ratio = 0.3){
    vector<vector<int>> res = map;
    for (int k = 0; k < int(map.size()*map[0].size()*ratio)+1; ++k) {
        int i = rand() %map.size();
        int j = rand() %map[0].size();
        res[i][j] = rand()%c+1;
    }

    return res;
}

vector<vector<int>> generate(int n, int m, int c){
    vector<vector<int>> res (n, vector<int>(m, 0));
    for (int i = 0; i < 1; ++i) {
        for (int j = 0; j < res[0].size(); ++j) {
            int c_i = rand()%c+1;
            res[i][j] = c_i;
        }
    }
    return res;
}

void solve(int n, int m, int c){
    cout << "n" << n << "m" << m << "c" << c << endl;
    int max_iter = 1000;
    int iter = 0;
    vector<vector<int>> map = generate(n, m, c);
    int current_bad = how_bad(map);
    while(current_bad > 0) {
        if (iter >= max_iter){
            vector<vector<int>> map = generate(n, m, c);
            current_bad = how_bad(map);
            iter = 0;
            cout << "change" << endl;
        }
        int new_bad = current_bad;
        vector<vector<int>> possible_map(n, vector<int>(m, 0));
        while (new_bad >= current_bad) {
            iter++;
            possible_map = change(map, c, 0.03);
            new_bad = how_bad(possible_map);
        }
        current_bad = new_bad;
        map = possible_map;
    }

    print(map);
}

int main(){
    srand(time(nullptr));
    int n,m,c;
//    n = 2, m = 10, c = 2;
//    solve(n, m, c);
//    n = 3, m = 6, c = 2;
//    solve(n, m, c);
//    n = 4, m = 4, c = 2;
//    solve(n, m, c);
//    n = 4, m = 6, c = 2;
//    solve(n, m, c);
//    n = 5, m = 4, c = 2;
//    solve(n, m, c);
//    n = 2, m = 10, c = 3;
//    solve(n, m, c);
//    n = 3, m = 10, c = 3;
//    solve(n, m, c);
//    n = 4, m = 4, c = 3;
//    solve(n, m, c);
//    n = 4, m = 6, c = 3;
//    solve(n, m, c);
//    n = 4, m = 7, c = 3;
//    solve(n, m, c);
//    n = 4, m = 10, c = 3;
//    solve(n, m, c);
//    n = 5, m = 6, c = 3;
//    solve(n, m, c);
//    n = 5, m = 10, c = 3;
//    solve(n, m, c);
//    n = 6, m = 7, c = 3;
//    solve(n, m, c);
//    n = 6, m = 10, c = 3;
//    solve(n, m, c);
//    n = 7, m = 10, c = 3;
//    solve(n, m, c);
//    n = 8, m = 10, c = 3;
//    solve(n, m, c);
    n = 9, m = 10, c = 3;
    solve(n, m, c);
    n = 10, m = 10, c = 3;
    solve(n, m, c);
    return 0;
}