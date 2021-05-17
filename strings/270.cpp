//
// Created by Olga Malyugina on 03.07.20.
//

#include <iostream>

using namespace std;

int main(){
    string name;
    cin >> name;

    bool isC = true;
    bool isJava = true;

    bool prev_char = false;
    for (char l:name) {
        if (l == '_' and not prev_char){
            cout << "Error!";
            return 0;
        }
        if (l == '_')
            prev_char = false;
        else
            prev_char = true;
    }
    if (name[name.size()-1] == '_'){
        cout << "Error!";
        return 0;
    }

    if (isupper(name[0])){
        cout << "Error!";
        return 0;
    }

    for (char l:name) {
        if (l == '_')
            isJava = false;
        if (isalpha(l) and isupper(l))
            isC = false;
    }
    if (not isC and not isJava){
        cout << "Error!";
        return 0;
    }
    else if (isC and isJava){
        cout << name;
        return 0;
    }
    else if (isC){
        bool next_char_up = false;
        for (char l:name) {
            if (l == '_') {
                next_char_up = true;
            }
            else if (next_char_up){
                cout << char(toupper(l));
                next_char_up = false;
            }
            else{
                cout << l;
            }

        }
    }
    else{
        for (char l:name) {
            if (isupper(l)){
                cout << '_' << char(tolower(l));
            }
            else{
                cout << l;
            }
        }
    }
    return 0;
}