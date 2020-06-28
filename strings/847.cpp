//
// Created by Olga Malyugina on 20.06.20.
//


#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    string name1;
    cin >> name1;
    string name2;
    cin >> name2;
    map<char, int> set1;
    map<char, int> set2;
//    transform(name1.begin(), name1.end(), name1.begin(), ::tolower);
//    transform(name2.begin(), name2.end(), name2.begin(), ::tolower);
    if (name1.size() != name2.size()){
        cout << "NO";
        return 0;
    }
    for (auto char_:name1)
        if (set1.find(char_) == set1.end())
            set1[char_] = 0;
        else
            set1[char_]++;
    for (auto char_:name2)
        if (set2.find(char_) == set2.end())
            set2[char_] = 0;
        else
            set2[char_]++;

    for (auto el:set1) {
        if (set2.find(el.first) == set2.end()) {
            cout << "NO";
            return 0;
        }
        if (set2[el.first] != el.second) {
            cout << "NO";
            return 0;
        }
    }
    for (auto el:set2) {
        if (set1.find(el.first) == set1.end()) {
            cout << "NO";
            return 0;
        }
        if (set1[el.first] != el.second) {
            cout << "NO";
            return 0;
        }
    }
    for (int i = 0; i < name1.size(); ++i) {
        if (name1[i] == name2[i]){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;

}
