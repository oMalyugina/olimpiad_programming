//
// Created by olga on 02/01/20.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    long long N;
    cin >> N;

    if (N==1) {
        cout << "WIN";
        return 0;
    }

    long long bad_number = 2;
    int k = 2;
    while (bad_number<N){
        bad_number+=k;
        if (k<=(int)sqrt(bad_number)){
            ++k;
            ++bad_number;
        }
    }
    if (bad_number != N)
        cout << "WIN";
    else
        cout << "LOSE";
    return 0;
}