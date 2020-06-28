//
// Created by Olga Malyugina on 07.06.20.
//


#include <iostream>
#include <string>
#include <set>

using namespace std;

int  compute_root(string number){
    int answer = 0;
    for(char char_:number)
        answer += int(char_) - int('0');
    while(answer > 9){
        number = to_string(answer);
        answer = 0;
        for(char char_:number)
            answer += int(char_) - int('0');
    }
    return answer;
}

int main(){
    string number;
    cin >> number;

    for (int i = 1; i < number.size(); ++i) {
        string first = number.substr(0, i);
        string second = number.substr(i);
        if (compute_root(first) == compute_root(second)){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";

    return 0;
}