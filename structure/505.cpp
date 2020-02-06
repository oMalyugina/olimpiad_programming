//
// Created by olga on 06/02/20.
//

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    int L, M, N;
    cin >> L >> M >> N;
    unordered_map<string, int> borders;
    for (int i = 0; i < M; ++i) {
        int number;
        cin >> number;
        string border;
        for (int j = 0; j < L; ++j) {
            int tmp;
            cin >> tmp;
            border += to_string(tmp) + "_";
        }
        borders[border] = number;
    }
    int good = 0;
    int bad = 0;
    for (int i = 0; i < N; ++i) {
        string border;
        for (int j = 0; j < L; ++j) {
            int tmp;
            cin >> tmp;
            border += to_string(tmp) + "_";
        }
        if (borders.find(border) == borders.end()){
            cout << "-" << endl;
            ++bad;
        }
        else{
            cout << borders[border] << endl;
            ++good;
        }
    }
    cout << "OK=" << good << " BAD=" << bad;

    return 0;
}
