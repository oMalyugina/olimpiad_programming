//
// Created by Olga Malyugina on 09.04.21.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct INFO{
    vector<int> color;
    vector<int> time_in;
    vector<int> time_out;
    vector<vector<int>> edges;
    int n;
    int time_;

    INFO(int n_):n(n_){
        color.assign(n, 0);
        time_in.assign(n, -1);
        time_out.assign(n, -1);
        edges.assign(n, vector<int>());
        time_=0;
    }
};

int dfs(INFO&info, int current){
    info.color[current]=1;
    info.time_++;
    info.time_in[current]=info.time_;
    for(int neighbor:info.edges[current]){
        if (info.color[neighbor]==0)
            dfs(info, neighbor);
    }
    info.time_++;
    info.time_out[current]=info.time_;
    info.color[current]=2;
    return 0;
}

int main(){
    int n;
    cin >> n;
    vector<int> times(n, -1);
    INFO info(n);
    for (int i = 0; i < n; ++i) {
        cin >> times[i];
    }
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int tmp;
            cin >> tmp;
            tmp--;
            info.edges[i].push_back(tmp);
        }
    }
    dfs(info, 0);
    vector<int> time2vertes(info.time_+1,-1);
    for (int i = 0; i < n; ++i) {
        if (info.time_out[i]!=-1)
            time2vertes[info.time_out[i]] = i;
    }
    long long res_time=0;
    int res_n=0;
    vector<int> res_details;
    for (int i = 0; i < info.time_+1; ++i) {
        if (time2vertes[i]!=-1) {
            int det = time2vertes[i];
            res_details.push_back(det);
            res_n++;
            res_time+=times[det];
        }
    }
    cout << res_time << " "<< res_n<<endl;
    for (int d:res_details) {
        d++;
        cout << d << " ";
    }
    return 0;
}