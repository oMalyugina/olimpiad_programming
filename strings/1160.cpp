//
// Created by Olga Malyugina on 29.07.20.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main(){
    string line;
    cin >> line;
    vector<int> prefix(line.size()+1, 0);
    int p = 0;
    for (int i = 1; i < line.size(); ++i) {
        while (true){
            if (line[i] == line[p]){
                p++;
                break;
            }
            if (p == 0)
                break;
            p = prefix[p];
        }
        prefix[i+1]=p;
    }
    for (int j = 1; j < line.size()+1; ++j) {
       cout << prefix[j] << " ";
    }
    return 0;
}