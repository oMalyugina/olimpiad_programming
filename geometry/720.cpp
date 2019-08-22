//
// Created by olga on 22/08/19.
//

#include <iostream>
#include <cmath>

using namespace std;

double c(int a, int b){
    return sqrt(a*a*1. + b*b*1.);
}

int main(){
    double r, l;
    cin >> r >> l;
    r = r/l;
    int sum = 0;
    int prev_h = 0, h = 0;
    for (int i = floor(r); i > 0; --i) {
        while (c(i, h) <= r){
            ++h;
        }
        sum += (h-1-prev_h)*i;
        prev_h = h-1;
    }
    cout << sum*4;
}