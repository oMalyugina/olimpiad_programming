//
// Created by olga on 05/02/20.
//

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string line;
    while (cin >> line) {
        stack<int> brackets;
        int flag = 0;
        for (char c : line) {
            if (c == '{') brackets.push(0);
            if (c == '[') brackets.push(1);
            if (c == '(') brackets.push(2);
            if (c == '}') {
                if (brackets.empty() or 0 != brackets.top()) {
                    flag = 1;
                    cout << 1;
                    break;
                } else
                    brackets.pop();
            }
            if (c == ']') {
                if (brackets.empty() or 1 != brackets.top()) {
                    flag = 1;
                    cout << 1;
                    break;
                } else
                    brackets.pop();
            }
            if (c == ')') {
                if (brackets.empty() or 2 != brackets.top()) {
                    flag = 1;
                    cout << 1;
                    break;
                } else
                    brackets.pop();
            }


        }
        if (flag) continue;
        if (brackets.empty())
            cout << 0;
        else
            cout << 1;
    }

    return 0;
}