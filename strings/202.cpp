//
// Created by Olga Malyugina on 04.07.20.
//

#include <iostream>

using namespace std;

int main(){
    string line, subline;
    cin >> line >> subline;

    int pos = line.find(subline);
    while (pos != string::npos){
        cout<< pos << " ";
        pos = line.find(subline, pos+1);
    }
    return 0;
}