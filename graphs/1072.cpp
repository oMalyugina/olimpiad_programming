//
// Created by Olga Malyugina on 07.04.21.
//

#include <iostream>
#include <vector>

using namespace std;

struct V{
    vector<int> time_in;
    vector<int> time_out;
    vector<int> color;
    vector<int> ret;
    vector<bool> is_sharnir;
    int n;
    int time=0;

    V(int n_): n(n_){
        time_in.assign(n, -1);
        time_out.assign(n, -1);
        color.assign(n, 0);
        ret.assign(n, -1);
        is_sharnir.assign(n, false);
    }
};

void dfs(V &vertexies, const vector<vector<int>> &edges, int current, int parent){
    vertexies.time++;
    vertexies.color[current]=1;
    vertexies.time_in[current]=vertexies.time;
    vertexies.ret[current] = vertexies.time_in[current];
    int children = 0;
    for (int neighbor:edges[current]){
        if (neighbor==parent)
            continue;
        children++;
        if (vertexies.color[neighbor]!=0){
            vertexies.ret[current] = min(vertexies.ret[current], vertexies.ret[neighbor]);
            if (vertexies.ret[current] <= vertexies.time_in[neighbor])
                vertexies.is_sharnir[current]=true;
        }
        else{
            dfs(vertexies,edges, neighbor, current);
            if (parent == -1){
                if (children>1)
                    vertexies.is_sharnir[current]=true;
            }else{
                vertexies.ret[current] = min(vertexies.ret[current], vertexies.ret[neighbor]);
                if (vertexies.ret[current] <= vertexies.time_in[neighbor])
                    vertexies.is_sharnir[current]=true;
            }
        }

    }
    vertexies.time++;
    vertexies.color[current]=2;
    vertexies.time_out[current]=vertexies.time;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> edges(n, vector<int>());
    V vertexies(n);
    for (int i = 0; i < n - 1; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        v1--;
        v2--;
        edges[v1].push_back(v2);
        edges[v2].push_back(v1);
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (vertexies.color[i] == 0){
            dfs(vertexies, edges, i, -1);
        }
        if (vertexies.is_sharnir[i])
            res++;
    }
    cout << res;
    
    return 0;
}
