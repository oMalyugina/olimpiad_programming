//
// Created by Olga Malyugina on 07.04.21.
//

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    int o1, o2;
    cin >> o1 >> o2;
    o1--;
    o2--;
    vector<int> edges(n, 0);
    for (int i = 0; i < n - 1; ++i) {
        int tmp;
        cin >> tmp;
        tmp--;
        edges[i+1]=tmp;
    }
    while (o1 != o2){
        if (o1 < o2)
            swap(o1, o2);
        o1 = edges[o1];
    }
    o1++;
    cout << o1;
    return 0;
}