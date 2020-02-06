//
// Created by olga on 04/02/20.
//

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main(){
    int p,n,k;
    cin >> p >> n >> k;
    vector<string> commands(p, "");
    map<string, int> counter;
    for (int i = 0; i <= p; ++i) {
        string name;
        getline(std::cin, name);
        if (i == 0) continue;
        commands[i-1] = name;
        counter[name] = 0;
    }
    vector<int> numbers(p,0);
    for (int i = 0; i < p; ++i) {
        int tmp;
        cin >> tmp;
        numbers[i] = tmp;
    }
    int number = 0;
    for (int i = 0; i < p; ++i) {
        if (number == n){
            break;
        }
        if (counter[commands[i]] >= k)
            continue;
        cout << commands[i] << " #" << numbers[i] << endl;
        counter[commands[i]] = counter[commands[i]] + 1;
        number++;
    }

    return 0;
}