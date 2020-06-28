//
// Created by Olga Malyugina on 28.06.20.
//

#include <iostream>
#include <set>
#include <map>

using namespace std;

int main(){
    int n;
    cin >> n;
    set<string> words;
    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        words.insert(word);
    }
    string chars;
    cin >> chars;
    int counter = 0;
    map<char, int> char2int;
    for (char l:chars){
        if (char2int.find(l)==char2int.end())
            char2int[l] = 1;
        else
            char2int[l] += 1;
    }
    for (string word:words){
        bool good = true;
        map<char, int> char_in_words;
        for (char l:word){
            if (char_in_words.find(l)==char_in_words.end())
                char_in_words[l] = 1;
            else
                char_in_words[l] += 1;
        }
        for (auto pair:char_in_words){
            if (char2int.find(pair.first) == char2int.end()){
                good = false;
                break;
            }
            if (char2int[pair.first] < pair.second){
                    good = false;
                    break;
                }
        }
        if (good)
            counter++;
    }

    cout << counter;

    return 0;
}