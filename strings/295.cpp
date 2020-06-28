//
// Created by Olga Malyugina on 20.06.20.
//

#include <iostream>
#include <string>

using namespace std;

string convert_word(string word, int add){
    for (char & i : word) {
        int char_ = (int)i - (int)'A';
        char_ += add;
        char_ = char_ % 26;
        char_ = (int)'A' + char_;
        i = (char)char_;
    }
    return word;
}

int main(){
    string message, word;
    cin >> message >> word;

    for (int i = 0; i <=25; ++i) {
        string new_word = convert_word(word, i);
        if (message.find(new_word) != string::npos){
            cout << convert_word(message, 26-i);
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}