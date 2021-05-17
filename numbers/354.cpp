//
// Created by Olga Malyugina on 11.11.20.
//

#include<iostream>
#include<vector>

using namespace std;

int main(){
    long long n;
    cin >> n;

    vector<int> res;
    int m = n;
    for (int i=2; i<=m; ++i){
        while (m%i==0){
            res.push_back(i);
            m = m / i;
        }
        if (m==1)
            break;
    }
    if (res.size() == 0){
        cout << n;
        return 0;
    }
    cout << res[0];
    for (int i=1; i<res.size(); ++i){
        cout << "*" << res[i];
    }
    return 0;
}