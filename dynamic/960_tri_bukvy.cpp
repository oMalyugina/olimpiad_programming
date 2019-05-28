//
// Created by olga on 24/05/19.
//
#include <iostream>

using std::cin;
using std::cout;


int main(){
    char char_;
    long long a = 0;
    long long ab = 0;
    long long abc = 0;

    while (cin >> char_){
        if (char_ == 'a')
            ++a;
        if (char_ == 'b')
            ab += a;
        if (char_ == 'c')
            abc += ab;
    }

    cout << abc;
    return 0;
}