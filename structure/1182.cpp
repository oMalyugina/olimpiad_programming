//
// Created by Olga Malyugina on 16.03.21.
//

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool is_available_places(const vector<int> &seats,const vector<int> &adds, const vector<int> &maxs, int part, int s, int e){
    int group_left = s/part;
    int group_right = e/part;
    int res = seats[s];
    if (group_left==group_right){
        for (int i = s; i <= e; ++i) {
            res = min(res, seats[i]-adds[i/part]);
        }
    }else{
        for (int i = s; i < (group_left+1)*part; ++i) {
            res = min(res, seats[i]-adds[i/part]);
        }
        for (int i = group_left+1; i < group_right; ++i) {
            res = min(res, maxs[i]);
        }
        for (int i = group_right*part; i <= e; ++i) {
            res = min(res, seats[i]-adds[i/part]);
        }
    }
    return res > 0;
}

void add(vector<int> &seats, vector<int> &adds, vector<int> &maxs, int part, int s, int e){
    int group_left = s/part;
    int group_right = e/part;
    if (group_left==group_right){
        for (int i = s; i <= e; ++i) {
            seats[i]--;
            maxs[group_right] = min(maxs[group_right], seats[i]-adds[group_right]);
        }
    }else{
        for (int i = s; i < (group_left+1)*part; ++i) {
            seats[i]--;
            maxs[i/part] = min(maxs[i/part], seats[i]-adds[i/part]);
        }
        for (int i = group_left+1; i < group_right; ++i) {
            maxs[i]--;
            adds[i]++;
        }
        for (int i = group_right*part; i <= e; ++i) {
            seats[i]--;
            maxs[i/part] = min(maxs[i/part], seats[i]-adds[i/part]);
        }
    }
}

int main(){
    int n,max_seat,m;
    cin >> n >> max_seat >> m;
    vector<int> seats(n-1,max_seat);
    int part = sqrt(n);
    vector<int> maxs(ceil((n-1)*1.0/part),max_seat);
    vector<int> adds(ceil((n-1)*1.0/part),0);
    for (int i = 0; i < m; ++i) {
        int s,e;
        cin >> s >> e;
        e--;
        if (is_available_places(seats, adds, maxs,part, s, e)){
            add(seats, adds, maxs,part, s, e);
            cout << "Yes"<< endl;
        }else{
            cout << "No" << endl;
        }

    }

    return 0;
}