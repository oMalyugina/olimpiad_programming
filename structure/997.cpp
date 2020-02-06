//
// Created by olga on 03/02/20.
//

#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    map<string, int> vocabular;
    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        std::transform(word.begin(), word.end(), word.begin(), [](unsigned char c) { return std::tolower(c); });
        vocabular[word]=0;
    }
    for (int i = 0; i < m + 1; ++i) {
        string line;
        getline(std::cin, line);

        size_t prev = 0, pos;
        while ((pos = line.find_first_of(" .,;:-'\"!?", prev)) != std::string::npos) {
            if (pos > prev) {
                string word = line.substr(prev, pos - prev);
                std::transform(word.begin(), word.end(), word.begin(), [](unsigned char c) { return std::tolower(c); });
                if (vocabular.find(word) == vocabular.end()) {
                    cout << "Some words from the text are unknown." << endl;
                    return 0;
                }
                vocabular[word] = vocabular[word] + 1;
            }
            prev = pos + 1;
        }
        if (prev < line.length()){
            string word = line.substr(prev, std::string::npos);
            std::transform(word.begin(), word.end(), word.begin(), [](unsigned char c) { return std::tolower(c); });
            if (vocabular.find(word) == vocabular.end()) {
                cout << "Some words from the text are unknown." << endl;
                return 0;
            }
            vocabular[word] = vocabular[word] + 1;
        }

    }
    for (const auto &word: vocabular) {
        if (word.second == 0) {
            cout << "The usage of the vocabulary is not perfect." << endl;
            return 0;
        }
    }
    cout << "Everything is going to be OK." << endl;
    return 0;
}
