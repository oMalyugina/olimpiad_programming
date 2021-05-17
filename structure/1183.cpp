//
// Created by Olga Malyugina on 19.03.21.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int nod(int a,int b){
    if (a < b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    if (b == 0)
        return a;
    while(a%b!=0){
        int r = a%b;
        a = b;
        b = r;
    }
    return b;
}

void build_tree(vector<int>&tree){
    int n = tree.size()/2;
    for (int i = n-1; i >0; --i) {
        tree[i] = nod(tree[2*i], tree[2*i+1]);
    }
}

int get_value(const vector<int> &tree, int l, int r, int start, int end){

    if (l == start and r == end){
        int window = end-start+1;
        int index = l/window;
        if (index == 0)
            index =1;
        return tree[index];
    }
    if (l >= start+(end-start)/2+1){
        return get_value(tree, l, r, start+(end-start)/2+1, end);
    } else if(r < start+(end-start)/2+1){
        return get_value(tree, l, r, start, start+(end-start)/2);
    } else{
        int nod1 = get_value(tree, l, start+(end-start)/2, start, start+(end-start)/2);
        int nod2 = get_value(tree, start+(end-start)/2+1, r, start+(end-start)/2+1, end);
        return nod(nod1, nod2);
    }
}

void update(vector<int> &tree, int index, int value){
    tree[index]=value;
    index = index/2;;
    while (index >=1) {
        tree[index]=nod(tree[index*2], tree[index*2+1]);
        index = index/2;
    }
}

int main(){
    int n;
    cin >> n;
    int start =pow(2,ceil(log2(n)));
    vector<int> tree(start*2, 0);
    for (int i = 0; i < n; ++i) {
        cin >> tree[start+i];
    }
    build_tree(tree);
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        string command;
        cin >> command;
        if (command=="g") {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            cout << get_value(tree, start + l, start + r, start, 2 * start - 1) << " ";
        }else{
            int index, value;
            cin >> index >> value;
            index--;
            update(tree, tree.size()/2+index, value);
        }
    }
    return 0;
}