//
// Created by Olga Malyugina on 30.05.20.
//

#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){
    string a,b;
    cin >> a >> b;
    set<char> a1;
    set<char> b1;
    int res1 = 0;
    int res2 = 0;
    for (int i = 0; i < 4; ++i){
        if (a[i] == b[i])
            ++res1;
        a1.insert(a[i]);
        b1.insert(b[i]);
    }

    for (const char & a_i:a){
        if(b1.find(a_i) != b1.end())
            ++res2;
    }

    cout << res1 << " " << res2-res1;


    return 0;
}