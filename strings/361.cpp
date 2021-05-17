//
// Created by Olga Malyugina on 28.06.20.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> sub(vector<int> v1, vector<int> v2){
    vector<int> ans (v1.size(), 0);
    for (int i = 0; i < v1.size(); ++i) {
        ans[i] = v1[i]-v2[i];
    }
    return ans;
}

bool equal(vector<int> v1, vector<int> v2){
    for (int i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i])
            return false;
    }
    return true;
}

int main(){
    string line;
    cin >> line;
    vector<vector<int>> chars(line.size()+1, vector<int>(26, 0));
    for (int i=0; i<line.size(); i++){
        int index = int(line[i]) - int('a');
        chars[i+1] = chars[i];
        chars[i+1][index]++;
    }
    for (int l = int(line.size()-1); l > 0; --l) {
        for (int i = 0; i <= line.size()-l; ++i) {
            for (int j = i+1; j <= line.size()-l; ++j) {
                vector<int> v1 = sub(chars[i+l], chars[i]);
                vector<int> v2 = sub(chars[j+l], chars[j]);
                if( equal(v1, v2)){
                    cout << l;
                    return 0;
                }
            }
        }

    }
    cout << 0;

    return 0;
}