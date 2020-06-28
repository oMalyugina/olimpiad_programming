//
// Created by Olga Malyugina on 21.06.20.
//

#include <iostream>
#include <map>

using namespace std;

int main() {
    string line;
    int counter = 0;
    map<char, int> char2number{
            {'a', 1},
            {'b', 2},
            {'c', 3},
            {'d', 4},
            {'e', 5},
            {'f', 6},
            {'g', 7},
            {'h', 8},
            {'i', 9},
            {'j', 1},
            {'k', 2},
            {'l', 3},
            {'m', 4},
            {'n', 5},
            {'o', 6},
            {'p', 7},
            {'q', 8},
            {'r', 9},
            {'s', 10},
            {'t', 11},
            {'u', 12},
            {'v', 13},
            {'w', 14},
            {'x', 15},
            {'y', 16},
            {'z', 17},
            {'0', 0},
            {'1', 1},
            {'2', 2},
            {'3', 3},
            {'4', 4},
            {'5', 5},
            {'6', 6},
            {'7', 7},
            {'8', 8},
            {'9', 9}
    };
    while (getline(cin, line)) {
        for (char letter:line) {
            if (letter == ' ')
                counter += 4;
            else if (isdigit(letter))
                counter += 13 - char2number[letter];
            else if (letter == '.')
                counter += 5;
            else if (letter == ';')
                counter += 7;
            else if (letter == ',')
                counter += 2;
            else if (letter == '=' or letter == '+' or letter == '-' or letter == '"' or letter == '\'')
                counter += 3;
            else if (letter == ')' or letter == '(')
                counter += 1;
            else if (letter == '[' or letter == ']' or letter == '{' or letter == '}' or letter == '<' or letter == '>')
                counter += 8;
            else if (isalpha(letter)) {
                if (islower(letter))
                    counter += char2number[letter];
                else
                    counter += char2number[tolower(letter)] + 10;
            } else {
                cout << counter;
                return 0;
            }
        }
    }
    cout << counter;
    return 0;
}