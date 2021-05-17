//
// Created by Olga Malyugina on 20.03.21.
//

#include <iostream>
#include <vector>

using namespace std;

void build_tree(vector<int>&tree){
    int n = tree.size()/2;

}

int main(){
int n;
cin >> n;
vector<int> tree(2*n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> tree[i];
    }
    build_tree(tree);
    int m;
    for (int j = 0; j < m; ++j) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

    }
    return 0;
}