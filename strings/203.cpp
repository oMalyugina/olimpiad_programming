//
// Created by Olga Malyugina on 28.06.20.
//

#include <iostream>

using namespace std;

int main(){
    string line1, line2;
    cin >> line1 >> line2;

    for (int i = 0; i < line1.size(); ++i) {
        string new_line = line2.substr(i) + line2.substr(0, i);
        if (new_line == line1){
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}