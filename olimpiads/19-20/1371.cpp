//
// Created by Olga Malyugina on 04.03.21.
//

#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

bool dfs(int v, vector<int>& colors, const vector<vector<bool>> & edges) {
    colors[v] = 1;
    for (int i = 0; i < colors.size(); ++i) {
        if (edges[v][i] == 0)
            continue;
        if (colors[i] == 0)
            if (dfs(i, colors, edges)){
                return true;
            }
        if (colors[i] == 1)
            return true;
    }
    colors[v] = 2;
    return false;
}

int first_zero(const vector<int>&colors){
    for (int i = 0; i < colors.size(); ++i) {
        if (colors[i]==0)
            return i;
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    vector<vector<bool>> edges(n, vector<bool>(n,false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int tmp;
            cin >> tmp;
            edges[i][j] = tmp;
        }
    }
    vector<int> colors(n, 0);
    int v = 0;
    while(v != -1){
        if (dfs(v, colors, edges)){
            cout << "Yes";
            return 0;
        }
        v = first_zero(colors);
    }
    cout << "No";
    return 0;

}
