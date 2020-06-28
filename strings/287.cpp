//
// Created by Olga Malyugina on 07.06.20.
//


#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(){
    int len_text, len_word;
    cin >> len_text >> len_word;
    string text;
    cin >> text;
    set<string> words;
    for (int char_i = 0; char_i < text.size() - len_word + 1; ++char_i) {
        words.insert(text.substr(char_i, len_word));
    }
    cout << words.size();
    return 0;
}