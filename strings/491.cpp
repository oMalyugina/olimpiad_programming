//
// Created by Olga Malyugina on 20.06.20.
//

#include <iostream>
#include <string>
#include <set>

using namespace std;

using namespace std;

bool eqchar(string s) {     // Проверка, является ли строка множеством одинаковых символов
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != s[0]) return false;
    }
    return true;
}

bool ispal(string s) {      // Проверка, является ли строка палиндромом
    for (int i = 0; i < s.length()/2; i++) {
        if (s[i] != s[s.length() - i - 1])  return false;
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    if (eqchar(s)) cout << "NO SOLUTION";
    else {
        if (!ispal(s))  cout << s;
        else {
            if (s[0] < s[1]) cout << s.substr(0, s.length() - 1);
            else cout << s.substr(1, s.length());
        }
    }
    return 0;
}