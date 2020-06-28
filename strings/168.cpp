//
// Created by Olga Malyugina on 20.06.20.
//

#include <iostream>

using namespace std;

int main(){
    string number;
    cin >> number;

    string answer = "";
    for (int i = 1; i <= stoi(number); ++i) {
        answer += to_string(i);
    }

    cout << answer.find(number)+1;


    return 0;
}