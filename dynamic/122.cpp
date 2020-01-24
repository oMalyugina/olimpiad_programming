//
// Created by olga on 24.01.20.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> numbers;
    map<int, int> result;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        numbers.push_back(tmp);
    }
    int theLongest = 0;
    for (const int number:numbers) {
        int count = 1;
        for(auto seen:result){
            if(number>seen.first) count = max(count,seen.second+1);
        }
        result[number] = count;
        theLongest = max(count, theLongest);
    }

    cout << theLongest;

    return 0;
}