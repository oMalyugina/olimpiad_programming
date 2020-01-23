//
// Created by olga on 21/01/20.
//

#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main() {

    int N;
    cin >> N;

    set<unsigned long long> seen;
    seen.insert(1);
    unsigned long long count = 1;
    set<unsigned long long> to_see;
    to_see.insert(2);
    to_see.insert(3);
    to_see.insert(5);
    unsigned long long last_number = 1;
    while (not to_see.empty() and count < N) {
        auto cur = min_element(to_see.begin(), to_see.end());
        unsigned long long value = *cur;
        seen.insert(value);
        to_see.erase(value);
        last_number = value;
        ++count;
        to_see.insert(value*2);
        to_see.insert(value*3);
        to_see.insert(value*5);
    }
    cout << last_number;
    return 0;
}