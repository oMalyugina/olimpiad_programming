//
// Created by Olga Malyugina on 28.06.20.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool compare(string word1, string word2){
    if (word1.size() != word2.size())
        return false;
    for (int j = 0; j < word1.size(); ++j) {
        if (word1[j] == ' ' and word2[j] == ' ')
            continue;
        if (word1[j] != ' ' and word2[j] != ' ')
            continue;
        return false;
    }
    return true;
}

bool get_clue(string line, string pattern, map<char,char>& clue){
    for (int i = 0; i < line.size();++i) {
        if (line[i] == ' ')
            continue;
        if (clue.find(line[i]) == clue.end())
            clue[line[i]] = pattern[i];
        else{
            if (clue[line[i]] != pattern[i]) {
                clue.clear();
                return false;
            }
        }
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    vector<string> input;
    string pattern = "the quick brown fox jumps over the lazy dog";
    bool decoded = false;
    map<char, char> clue;
    for (int i = 0; i < n+1; ++i) {
        string line;
        getline(cin, line);
        input.push_back(line);
        if (decoded)
            continue;
        if (!compare(line, pattern))
            continue;
        if (get_clue(line, pattern, clue))
            decoded = true;

    }
    if (!decoded){
        cout << "No solution";
        return 0;
    }

    for(const string& line: input){
        for(char i:line){
            if (i == ' ')
                cout << i;
            else
                cout << clue[i];
        }
        cout << endl;
    }
    return 0;
}