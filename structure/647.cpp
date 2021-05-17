//
// Created by Olga Malyugina on 31.03.21.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

struct tree{
    int len;
    vector<int> data;
    int first;

    tree(int n, int m){
        n = n+m;
        len = pow(2, ceil(log2(n)));
        data.assign(len*2, 0);
        first = m;
    }

    int reccursive_sum(int s, int e, int l, int r){
        if (s == l and e == r){
            int window = r-l+1;
            return data[l/window];
        }
        int m = (l+r)/2+1;
        if(e < m){
            return reccursive_sum(s,e,l,m-1);
        } else if (s >=m){
            return reccursive_sum(s,e,m,r);
        }else{
            int res1 = reccursive_sum(s, m-1,l, m-1);
            int res2 = reccursive_sum(m, e, m, r);
            return res1+res2;
        }
    }

    int get_elements_before(int index){
        int res = reccursive_sum(len+0, len+index-1, len, 2*len-1);
        return res;
    }

    void add(int index){
        index = len+index;
        while (index>0){
            data[index]++;
            index = index/2;
        }
    }

    void update(int index){
        index = len+index;
        while (index>0){
            data[index]--;
            index = index/2;
        }
        first--;
        index = len+first;
        while (index>0){
            data[index]++;
            index = index/2;
        }
    }
};

struct SQRT{
    vector<bool> original;
    vector<int> sums;
    int len_group = 400;
    int first;

    SQRT(int n, int m){
        first = m;
        sums.assign(len_group, 0);
        original.assign(len_group*len_group, false);
    }

    void add(int index){
        index = first+index;
        original[index]=true;
        sums[index/len_group]++;
    }

    int get_elements_before(int index){
        int res = 0;
        int last_group = index/len_group;
        for (int group_i = 0; group_i < last_group; ++group_i) {
            res+=sums[group_i];
        }
        for (int i = last_group*len_group; i < index; ++i) {
            res+=original[i];
        }
        return res;
    }

    void update(int index){
        original[index]=false;
        sums[index/len_group]--;
        first--;
        original[first]=true;
        sums[first/len_group]++;
    }
};

int main(){
    int n,m;
    cin >> n >> m;
//    tree data(n,m);
    SQRT data(n,m);
    map<int, int> value2index;
    for (int j = 0; j < n; ++j) {
        value2index[j+1]=m+j;
        data.add(j);
    }
    for (int i = 0; i < m; ++i) {
        int value;
        cin >> value;
        int current_index = value2index[value];
        int res = data.get_elements_before(current_index);
        cout << res+1<< " ";
        data.update(current_index);
        value2index[value] = data.first;
    }


    return 0;
}