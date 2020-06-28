//
// Created by Olga Malyugina on 21.06.20.
//

#include <iostream>

using namespace std;

int main(){
    string input;
    int power;
    cin >> input >> power;
    if (power > 0) {
        int len_ = 0;
        for (int i = 0; i < power and len_ < 1023; ++i) {
            cout << input.substr(0, 1023 - len_);
            len_ += input.size();
        }
        return 0;
    }
    power = -power;
    if (input.size() % power){
        cout << "NO SOLUTION";
        return 0;
    }
    int answer_size = int(input.size())/power;
    string possible_answer = input.substr(0, answer_size);
    for (int j = 1; j < power; ++j) {
        string substring = input.substr(answer_size*j, answer_size);
        if (substring != possible_answer){
            cout << "NO SOLUTION";
            return 0;
        }
    }
    cout << possible_answer;

    return 0;
}