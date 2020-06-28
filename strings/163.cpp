//
// Created by Olga Malyugina on 07.06.20.
//


#include <iostream>
#include <string>
using namespace std;

int main(){
    string input;
    cin >> input;

    if ('x' == input[0]){
        if (input[1] == '-'){
            cout << int(input[4]) + int(input[2]) - int('0') - int('0');
        }else{
            cout << int(input[4]) - int(input[2]);
        }
    }else if ('x' == input[2]){
        if (input[1] == '-'){
            cout << int(input[0]) - int(input[4]);
        }else{
            cout << int(input[4]) - int(input[0]);
        }
    }else    if ('x' == input[4]){
        if (input[1] == '-'){
            cout << int(input[0]) - int(input[2]);
        }else{
            cout << int(input[0]) + int(input[2]) - int('0') - int('0');
        }
    }

    return 0;
}