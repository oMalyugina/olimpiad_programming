//
// Created by olga on 21/06/19.
//

#include<iostream>
#include<vector>

bool dfs(int * const crossroads, int ** const roads, int cur, int n){
    crossroads[cur] = 2;
    for (int i=0; i<n; i++){
        if (roads[cur][i] == 1){
            if (crossroads[i] == 2) return true;
            crossroads[i] = 1;
            bool res = dfs(crossroads, roads, i, n);
            if (res){ return true;}
        }
    }
    return false;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> roads;
    std::vector<int> crossroads;
    for (int i = 0; i < n; i++) {
        crossroads.push_back(0);
        for (int j = 0; j < n; j++) {
            roads[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int crossroad1, crossroad2;
        std::cin >> crossroad1 >> crossroad2;
        roads[crossroad1][crossroad2] = 1;
        roads[crossroad2][crossroad1] = 1;
    }
    if (dfs(crossroads, roads, 0, n)){
        std::cout << "YES";
    }else{
        std::cout << "NO";
    }
    return 0;
}