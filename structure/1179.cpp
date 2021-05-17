//
// Created by Olga Malyugina on 16.03.21.
//
//
// Created by Olga Malyugina on 10.03.21.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> create_tree(const vector<int> & array){
    int n = array.size();
    if (n == 1){
        return array;
    }
    int depth = int(log2((n-1)*2));
    vector<int> tree (pow(2,depth+1), 1000000);
    int l = pow(2,depth);
    for (int i = 0; i < n; ++i) {
        tree[l+i] = array[i];
    }
    while (l > 0){
        l = l/2;
        for (int i = l; i < l*2; ++i) {
            tree[i] = min(tree[i*2], tree[i*2+1]);
        }
    }
    return tree;
}

int get_min(const vector<int> & tree, int l, int r, int level, int start, int end){
    if (l == start and r == end){
        if (level == 0)
            return tree[1];
        int start_i = pow(2,level-1);
        int window = tree.size()/start_i/2;
        int index = l/window;
        return tree[start_i+index];
    }
    if (l <= start+(end-start)/2 and r <= start+(end-start)/2){
        return get_min(tree, l, r, level+1, start, start+(end-start)/2);
    } else if(l > start+(end-start)/2 and r > start+(end-start)/2){
        return get_min(tree, l, r, level+1, start+(end-start)/2+1, end);
    } else{
        int min1 = get_min(tree, l, start+(end-start)/2, level+1, start, start+(end-start)/2);
        int min2 = get_min(tree, start+(end-start)/2+1, r, level+1, start+(end-start)/2+1, end);
        return min(min1, min2);
    }
}

int main(){
    int n, k;
    cin >> n>>k;
    vector<int> array(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }
    const vector<int> tree = create_tree(array);
    for (int i = 0; i < n - k + 1; ++i) {
        cout << get_min(tree, i, i+k-1, 0, 0, tree.size()-1)<< " ";
    }
    return 0;
}

