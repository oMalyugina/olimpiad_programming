//
// Created by Olga Malyugina on 25.04.20.
//
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;
    vector<vector<int>> crossroads(N, vector<int>());
    vector<int> dangerous(N);
    for(int i=0; i<M; ++i){
        int start, end;
        cin >> start >> end;
        start--;
        end--;
        crossroads[start].push_back(end);
        crossroads[end].push_back(start);
    }
    for (int i=0;i<N; ++i){
        dangerous[i] = crossroads[i].size();
    }
    vector<int> dangerous_list;
    int a = 0;
    for (int i=0;i<N; ++i){
        if (dangerous[i] == 0)
            if (i > 0 and dangerous[i-1] ==0 and i < N-1 and dangerous[i+1] == 0){
                cout << i+1 << " ";
                a++;
            }
        if (i > 0 and dangerous[i] <= dangerous[i-1])
            continue;
        if (i < N-1 and dangerous[i] <= dangerous[i+1])
            continue;
        cout << i+1 << " ";
        a++;
    }
    if (a == 0)
        cout << -1;

    return 0;
}