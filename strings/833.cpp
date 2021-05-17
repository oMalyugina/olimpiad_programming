//
// Created by Olga Malyugina on 04.07.20.
//

#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

void shift(string& line, int r, int l){
    string middle = line.substr(r, l-r+1);
    reverse(middle.begin(), middle.end());
    for (int i = r; i <= l; ++i) {
        line[i] = middle[i-r];
    }
}

int main(){
    string dnk1, dnk2;
    cin >> dnk1 >> dnk2;
    vector<vector<int>> transformation;

    for (int i = 0; i < dnk1.size(); ++i) {
        if (dnk1[i] == dnk2[i])
            continue;
        for (int j = i+1; j < dnk1.size(); ++j) {
            if (dnk1[j] == dnk2[i]) {
                shift(dnk1, i, j);
                vector<int> t = {i, j};
                transformation.push_back(t);
                break;
            }
        }
    }
    cout << transformation.size() << endl;
    for (int k = 0; k < transformation.size(); ++k) {
        cout << transformation[k][0]+1 << " " << transformation[k][1]+1 << endl;
    }
}