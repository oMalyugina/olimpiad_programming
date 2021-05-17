//
// Created by Olga Malyugina on 04.07.20.
//

#include <iostream>
#include <stack>
using namespace std;

bool check(const string& line){
    int open = 0;
    for (char l:line) {
        if (l == '(' or l == '[')
            open++;
        else
            open--;
        if (open < 0)
            return false;
    }
    return open == 0;
}

int main(){
    string line;
    cin >> line;
    if (not check(line)){
        cout << "-1";
        return 0;
    }

    stack<char> seen;
    int counter = 0;
    for (char l:line) {
        if (l == '(' or l == '[') {
            seen.push(l);
        }
        else{
            char prev = seen.top();
            seen.pop();
            if (prev == '(' and l == ']'){
                counter++;
            }
            else if (prev == '[' and l == ')') {
                counter++;
            }
        }

    }
    cout << counter;
    return 0;
}