//
// Created by Olga Malyugina on 05.06.20.
//

#include <iostream>
#include <string>

using namespace std;

int main(){
    string input;
    cin >> input;
    if (input.size() < 2){
        cout << "No";
        return 0;
    }
    int prev = 0;
    for(auto char_:input){
        if ((prev == 0 or prev == 4) and islower(char_)){
            cout << "No";
            return 0;
        }
        if (islower(char_)){
            prev++;
        }else{
            if (prev == 1){
                cout << "No";
                return 0;
            }else{
                prev = 1;
            }
        }
    }
    if (prev == 1){
        cout << "No";
        return 0;
    }
    cout << "Yes";
    return 0;
}