//
// Created by Olga Malyugina on 07.04.21.
//

#include <iostream>

using namespace std;

int main(){
    long long n, v1, v2;
    cin >> n>>v1 >>v2;
    while (v1 != v2){
        if (v1 < v2)
            swap(v1, v2);
        v1 = v1/2;
    }
    cout << v1;
    return 0;
}
