//
// Created by Olga Malyugina on 06.04.21.
//

#include <iostream>
#include <set>

using namespace std;

int main(){
    int n;
    cin >> n;
    multiset<long long> numbers;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        numbers.insert(tmp);
    }
    long long res = 0;
    while (numbers.size()>1){
        long long v1 = *numbers.begin();
        numbers.erase(numbers.begin());
        long long v2 = *numbers.begin();
        numbers.erase(numbers.begin());
        res += v1+v2;
        numbers.insert(v1+v2);
    }
    res = res*5;
    cout << res/100 << ".";
    int next_res = res%100;
    if (next_res < 10){
        cout << "0";
    }
    cout << next_res;
    return 0;
}