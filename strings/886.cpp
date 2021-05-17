//
// Created by Olga Malyugina on 19.07.20.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> prefix_fun(const string &line){
    vector<int> prefix(line.size(), 0);
    for (int i = 1; i < line.size(); ++i) {
        int value_pref = prefix[i-1];
        while( value_pref > 0 and line[i] != line[value_pref]){
            value_pref = prefix[value_pref-1];
        }

        if (line[i] != line[value_pref])
            prefix[i] = 0;
        else
            prefix[i] = value_pref+1;
    }
    return prefix;
}

int main(){
    string line;
    cin >> line;
    vector<int>res = prefix_fun(line);
    int last_prefix = res[res.size()-1];
    if (last_prefix < line.size()*1./2){
        cout << 1;
        return 0;
    }
    int period = line.size()-last_prefix;
    if (last_prefix%period != 0){
        cout << 1;
        return 0;
    }
    cout << int(last_prefix/period)+1;

    return 0;
}