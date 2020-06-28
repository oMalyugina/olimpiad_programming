//
// Created by Olga Malyugina on 07.06.20.
//


#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main(){
    int number_gods;
    cin >> number_gods;
    vector<string> names;
    vector<int> counter;
    for (int i = 0; i < number_gods; ++i) {
        string name;
        cin >> name;
        names.push_back(name);
        counter.push_back(0);
    }
    int number_lines;
    cin >> number_lines;
    for (int j = 0; j < number_lines; ++j) {
        string line;
        cin >> line;
        for (int name_i = 0; name_i < names.size(); ++name_i) {
            string name = names[name_i];
            if (name.size() != line.size())
                continue;
            int error = 0;
            for (int char_i = 0; char_i < name.size(); ++char_i) {
                if (name[char_i] != line[char_i])
                    error++;
                if (error > 1)
                    break;
            }
            if (error == 1)
                counter[name_i]++;
        }
    }

    for (int name_i = 0; name_i < names.size(); ++name_i){
        cout << counter[name_i] << " ";
    }



    return 0;
}