//
// Created by olga on 04/02/20.
//

#include <iostream>
#include <list>
#include <algorithm>
#include <fstream>
#include <iterator>

using namespace std;

int main() {
    list<int> lines;
    lines.push_back(0);
    int max_line = 0;
    string line;
    getline(cin, line);
    auto it = lines.begin();
    for (char c : line) {
        if (c == '\\') {
            it = lines.insert(next(it), 0);
        } else if (c == '<') {
            if (*it > 0) {
                --(*it);
            } else {
                if (it == lines.begin())
                    continue;
                int curr = *it;
                it = prev(it);
                curr += *(it);
                *it = curr;
                lines.erase(next(it));
            }
        } else if (c == '^') {
            if (it == lines.begin())
                continue;
            it = prev(it);
        } else if (c == '|') {
            if (next(it) == lines.end())
                continue;
            it = next(it);
        } else {
            ++(*it);
            max_line = max(max_line, *it);
        }

    }
    cout << max_line;


    return 0;
}