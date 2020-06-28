//
// Created by Olga Malyugina on 04.06.20.
//


#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){
    int n;
    cin >> n;
    set<char> allowed = {'A', 'B', 'C', 'E', 'H', 'K', 'M', 'O', 'P', 'T', 'X', 'Y'};
    set<char> numbers = {'0', '1', '2', '3', '4', '5', '6', '7','8', '9'};
    for (int i = 0; i < n; ++i) {
        string number;
        cin >> number;
        bool good = true;
        if (number.size() != 6){
            cout << "No" << endl;
            continue;
        }
        for (int j = 0; j < 6; ++j) {
            if (j == 1 or j == 2 or j == 3 ){
                if(numbers.find(number[j]) == numbers.end()){
                    cout << "No" << endl;
                    good = false;
                    break;
                }
            }
            else {
                if (allowed.find(number[j]) == allowed.end()) {
                    cout << "No" << endl;
                    good = false;
                    break;
                }
            }
        }
        if (good)
            cout << "Yes"<< endl;
    }

    return 0;
}