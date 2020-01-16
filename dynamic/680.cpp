//
// Created by olga on 15/01/20.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    unsigned long long N;
    cin >> N;
    unsigned long long res = pow(2, (N-1));
    cout << res*3;
    return 0;
}
