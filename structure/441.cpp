//
// Created by Olga Malyugina on 30.03.21.
//

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

struct tree{
    int len;
    vector<int> data;

    tree(int n_){
        len = pow(2, ceil(log2(n_)));
        data.assign(2*len, 0);
    }

    void update(int index){
        index = len+index;
        while(index>0){
            data[index]++;
            index = index/2;
        }
    }

    int recursive_sum(int s, int e, int l, int r){
        if (l==s and e == r){
            int window = r-l+1;
            return data[l/window];
        }
        int m = (l+r)/2+1;
        if (e < m){
            int res = recursive_sum(s, e, l, m-1);
            return res;
        }else if(s >= m){
            int res = recursive_sum(s, e, m, r);
            return res;
        }else{
            int res1 = recursive_sum(s,m-1, l, m-1);
            int res2 = recursive_sum(m, e, m, r);
            return res1+res2;
        }
    }

    int sum(int index){
        int res = recursive_sum(len+index, 2*len-1, len, 2*len-1);
        return res;
    }
};

int main(){
    int n;
    cin >> n;

    tree data(n);
    map<int, vector<int>> original;
    for (int j = 0; j < n; ++j) {
        int tmp;
        cin >> tmp;
        if (original.find(tmp)==original.end()){
            vector<int> places;
            places.push_back(j);
            original[tmp]=places;
        }else{
            original[tmp].push_back(j);
        }
    }
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        int cur_number;
        cin >> cur_number;
        if (original.find(cur_number)==original.end()){
            cout << -1;
            return 0;
        }
        long long original_place = original[cur_number][0];
        original[cur_number].erase(original[cur_number].begin());
        if (original[cur_number].empty()){
            original.erase(cur_number);
        }
        long long shift = data.sum(original_place);
        data.update(original_place);
        long long moves = original_place+shift-i;
        res+=moves;
    }
    cout << res;
    return 0;
}