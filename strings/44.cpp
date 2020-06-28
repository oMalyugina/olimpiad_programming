//
// Created by Olga Malyugina on 30.05.20.
//

#include <iostream>
#include <string>

using namespace std;

int main(){
    string a;
    getline(cin, a);
    int res=0;
    for (int i = 0; i < int(a.size()) - 4; ++i) {
        string b = a.substr(i, 5);
        if (b == ">>-->")
            ++res;
        if (b == "<--<<")
            ++res;
    }

    cout << res;

    return 0;
}