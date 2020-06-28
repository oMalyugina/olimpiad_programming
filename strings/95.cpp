//
// Created by Olga Malyugina on 05.06.20.
//

#include <iostream>
#include <string>

using namespace std;

int main(){
    string s_line;
    cin >> s_line;
    int number_steps = 0;
    while (s_line.size() > 1){
        number_steps++;
        int number = 0;
        for(auto char_:s_line){
            number += (int)char_ - (int)'0';
        }
        s_line = to_string(number);
    }

    cout << s_line << " " << number_steps;
    return 0;
}
