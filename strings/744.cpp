//
// Created by Olga Malyugina on 15.08.20.
//

#include <iostream>
#include <stack>

using namespace std;

char get_opposit(char l){
    if (l == '(')
        return ')';
    if (l == '[')
        return ']';
    if (l == '{')
        return '}';
    return 'a';
}

bool isGood(const string & line){
    stack<char> opened;
    for (char l: line){
        if (l == '[' or l == '{' or l == '(')
            opened.push(l);
        else{
            if (opened.empty())
                return false;
            char last = opened.top();
            opened.pop();
            if (get_opposit(last) != l)
                return false;
        }
    }
    return opened.empty();
}

int main(){
    string line;
    cin >> line;
    if(line.empty()){
        cout << "YES";
        return 0;
    }

    for (int i = 0; i < line.size(); ++i) {
        string new_line = line.substr(i) + line.substr(0, i);
        if (isGood(new_line)){
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
    return 0;
}