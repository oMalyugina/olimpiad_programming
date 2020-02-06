//
// Created by olga on 05/02/20.
//
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long counter = 0;
    long long prev;
    cin >> prev;
    long long max_ = prev;
    for (int i = 1; i < n; ++i) {
        long long curr;
        cin >> curr;
        if (curr > prev){
            counter += curr-prev;
            prev = curr;
            max_ = max(max_, prev);
        } else if(curr < prev){
            prev = curr;
        }
    }
    counter += max_ - prev;
    cout << counter;

    return 0;
}

