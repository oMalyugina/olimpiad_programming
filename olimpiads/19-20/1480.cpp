//
// Created by Olga Malyugina on 30.05.20.
//

#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    int max_value = 0;
    map<string, int> name2count;
    set<string> names;
    for (int i = 0; i < n; ++i) {
        string name;
        cin >> name;
        names.insert(name);
        if (name2count.find(name) == name2count.end())
            name2count[name] = 1;
        else
            ++name2count[name];
        max_value = max(max_value, name2count[name]);
    }

    vector<vector<bool>> answer(max_value, vector<bool>(names.size(), true));
    int i = 0;
    for (const string & name:names){
        int value = name2count[name];
        for (int j = 0; j < max_value-value; ++j)
            answer[j][i] = false;
        ++i;
    }

    for (int i = 0; i < max_value; ++i) {
        for (int j = 0; j < names.size(); ++j) {
            if (answer[i][j])
                cout << "X";
            else
                cout << ".";
        }
        cout << endl;
    }



    return 0;
}