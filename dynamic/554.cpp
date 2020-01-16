//
// Created by olga on 15/01/20.
//

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<long> res(N+1, 0);
    res[0] = 1;
    for (int i = 1; i <= N; ++i) {
        res[i] = res[i-1] + i;
    }
    cout << res[N];
    return 0;
}