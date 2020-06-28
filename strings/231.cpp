//
// Created by Olga Malyugina on 05.06.20.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    cin >> input;
    string prev_number = "";
    int printed = 0;
    for(auto char_:input){
        if(isdigit(char_)){
            prev_number += char_;
        }else{
            if (prev_number.empty()) {
                cout << char_;
                printed++;
                if (printed == 40){
                    cout << endl;
                    printed = 0;
                }
            }
            else{
                for (int i = 0; i < stoi(prev_number); ++i) {
                    cout << char_;
                    printed++;
                    if (printed == 40){
                        cout << endl;
                        printed = 0;
                    }
                }
                prev_number = "";
            }
        }
    }

    return 0;

}


