#include<iostream>

using namespace std;

bool isPalindrom(string one){
    int start = 0, end = one.size()-1;
    while(start < end){
        if (one[start] != one[end])
            return false;
        start++;
        end--;
    }
    return true;
}

int main() {
    string line;
    getline(cin, line);

    string new_line = "";
    for (char l:line){
        if (isalpha(l) and ((int(l)>=65 and int(l) <=90)or (int(l)>=97 and int(l) <=122))){
            new_line+=tolower(l);
        }
    }

    int start = 0, end = new_line.size() - 1;
    while (start < end) {
        if (new_line[start] != new_line[end]) {
            if (isPalindrom(new_line.substr(start+1, end-start-1))){
                cout << "YES" << endl;
                cout << new_line.substr(0, start) << new_line[end] << new_line.substr(start+1);
                return 0;
            }
            if (isPalindrom(new_line.substr(start+1, end-start))){
                cout << "YES" << endl;
                cout << new_line.substr(0, start)<< new_line.substr(start+1);
                return 0;
            }
            if (isPalindrom(new_line.substr(start, end-start))){
                cout << "YES" << endl;
                cout << new_line.substr(0, end) << new_line.substr(end+1);
                return 0;
            }
            cout << "NO";
            return 0;
        }
        start++;
        end--;
    }
    cout << "YES" << endl;
    cout << new_line;
    return 0;
}