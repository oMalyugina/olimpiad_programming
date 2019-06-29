//
// Created by olga on 21/06/19.
//

#include<iostream>
#include<vector>
using  std::vector;

bool dfs(int prec, vector<int> & crossroads, const vector<vector<int>> & roads, vector<int> &seen, int n){
    int cur = seen.back();
    seen.pop_back();
    for (int i=0; i<n; i++){
        if (roads[cur][i] == 1){
            if (i ==  prec) continue;
            if (crossroads[i] == 1) return true;
            seen.push_back(i);
            crossroads[i] = 1;
            bool res = dfs(cur, crossroads, roads, seen, n);
            if (res){ return true;}
        }
    }
    crossroads[cur] = 2;
    return false;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> roads;
    std::vector<int> crossroads;
    for (int i = 0; i < n; i++) {
        crossroads.push_back(0);
        vector<int> road;
        for (int j = 0; j < n; j++) {
            road.push_back(0);
        }
        roads.push_back(road);
    }

    for (int i = 0; i < m; i++) {
        int crossroad1, crossroad2;
        std::cin >> crossroad1 >> crossroad2;
        roads[crossroad1-1][crossroad2-1] = 1;
        roads[crossroad2-1][crossroad1-1] = 1;
    }
    vector<int> seen;
    seen.push_back(0);
    crossroads[0] = 1;
    if (dfs(0, crossroads, roads, seen, n)){
        std::cout << "YES";
    }else{
        std::cout << "NO";
    }
    return 0;
}