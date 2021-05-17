//
// Created by Olga Malyugina on 08.08.20.
//

#include <iostream>
#include <vector>

using namespace std;

int main(){
    string line;
    cin >> line;
    vector<int> z_fun(line.size(), 0);
    int l = 0, r = 0;
    for (int i = 1; i < line.size(); ++i) {
        int possible_z = 0;
        if (r > i)
            possible_z = min(z_fun[i-l], r-i);
        while (i+possible_z<line.size() and line[possible_z] == line[i+possible_z])
            possible_z++;
        z_fun[i] = possible_z;
        if (i+possible_z > r){
            l = i;
            r = i+possible_z;
        }
    }
    for (int j = 0; j < line.size(); ++j) {
        cout << z_fun[j] << " ";
    }
    return 0;
}