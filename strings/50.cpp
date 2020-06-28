//
// Created by Olga Malyugina on 20.06.20.
//

#include <iostream>
#include <set>

using namespace std;

int main(){
    string main;
    string pattern;
    cin >> main >> pattern;
    int counter = 0;
    set<string> used;
    for (int i = 0; i < pattern.size(); ++i) {
        string new_pattern = pattern.substr(i)+ pattern.substr(0,i);
        if (used.find(new_pattern) != used.end()){
            continue;
        }
        used.insert(new_pattern);
        size_t pos = main.find(new_pattern, 0);
        while(pos != string::npos)
        {
            counter++;
            pos = main.find(new_pattern,pos+1);
        }
    }

    cout << counter;
    return 0;
}