//
// Created by Olga Malyugina on 06.06.20.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string input;
    cin >> input;
    vector<char> input1;
    vector<char> input2;
    int deleted = 0;
    bool found = false;
    for (int i = 1; i < input.size(); ++i) {
        if (found) {
            input1.push_back(input[i]);
            continue;
        }
        if (input[i-1] < input[i]){
            found = true;
            input1.push_back(input[i]);
        }else{
            input1.push_back(input[i-1]);
        }
    }
    if (found)
        deleted++;
    else
        input1.push_back(input[input.size()-1]);

    found = false;
    for (int i = 1; i < input1.size(); ++i) {
        if (found) {
            input2.push_back(input1[i]);
            continue;
        }
        if (input1[i-1] < input1[i]){
            found = true;
            input2.push_back(input1[i]);
        }else{
            input2.push_back(input1[i-1]);
        }
    }
    if (found)
        deleted++;
    else
        input2.push_back(input1[input1.size()-1]);

    for (int j = 0; j < input2.size() - (2-deleted); ++j) {
        cout << input2[j];
    }

    return 0;
}