//
// Created by Olga Malyugina on 20.06.20.
//

#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string input;
        cin >> input;
        int nuls=0, ones=0, twos=0;
        bool written = false;
        for (char char_:input){
            if (char_ == '0'){
                if (ones > 0 or twos > 0){
                    cout << "NO" << endl;
                    written = true;
                    break;
                }
                nuls++;
            }
            if (char_ == '1'){
                if (twos > 0 or ones >= nuls){
                    cout << "NO" << endl;
                    written = true;
                    break;
                }
                ones++;
            }
            if (char_ == '2'){
                if (twos >= ones){
                    cout << "NO" << endl;
                    written = true;
                    break;
                }
                twos++;
            }
        }
        if (!written) {
            if (ones == nuls and ones == twos) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}