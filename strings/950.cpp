//
// Created by Olga Malyugina on 05.06.20.
//

#include <iostream>
#include <string>

using namespace std;

int main(){
    string line;
    cin >> line;
    int number_zeros = 0;
    for(auto char_:line){
        if (char_ == '0'){
            number_zeros++;
        }else{
            char l = 'a'+number_zeros;
            cout << l;
            number_zeros = 0;
        }
    }
    return 0;
}
