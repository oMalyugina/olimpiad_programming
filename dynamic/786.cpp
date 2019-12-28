//
// Created by olga on 26/12/19.
//

#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    int k = 1;

    while (2*k<=n){
        k = 2*k;
    }
    if (k==n) cout << 0;
    else cout << n-k;
    return 0;
}
