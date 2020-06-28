//
// Created by Olga Malyugina on 21.06.20.
//

#include <iostream>
#include <set>
using namespace std;

int main(){
    string input;
    cin >> input;
    int prev_prev = 1;
    int prev = 2;
    cout << input.substr(0,3);
    while (prev + prev_prev <= input.size()){
        int tmp = prev_prev;
        prev_prev = prev;
        prev = prev_prev+tmp;
        cout << input[prev-1];
    }

    return 0;
}