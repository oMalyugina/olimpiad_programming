//
// Created by Olga Malyugina on 28.06.20.
//

#include <iostream>
#include <vector>


using namespace std;

int main(){
    setlocale(LC_ALL,"Rus");

    int k, n;
    cin >> k >> n;
    vector<string> res;
    string line;
    getline(cin, line);
    for (int i = 0; i < n; ++i) {
        getline(cin, line);
        if (line.size() > k){
            cout << "Impossible.";
            return 0;
        }
        int start = 0, end = 0;
        bool isstart = true;
        int number_char = 0;
        for (auto j : line) {
            number_char++;
            if (isstart){
                if (j == ' ')
                    start++;
                else
                    isstart = false;
            }else{
                if(j == ' ')
                    end++;
                else
                    end = 0;
            }
        }
        number_char = int(line.size()) - start - end;
        int add_start = (k-number_char)/2;
        int add_end = (k-number_char)/2;
        if (k-number_char%2)
             add_end++;
        string good_line = "";
        for (int l = 0; l < add_start; ++l) {
            good_line+= ' ';
        }
        good_line += line;
        for (int l = 0; l < add_end; ++l) {
            good_line+= ' ';
        }
        res.push_back(good_line);
    }
    for (const string& line:res){
        cout << line << endl;
    }
    return 0;
}