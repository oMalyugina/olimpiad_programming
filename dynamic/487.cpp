//
// Created by olga on 04/01/20.
//

#include <iostream>

using namespace std;

int main() {
    int N, K, P;
    cin >> N >> K >> P;
    for (int i = 0; i < P; ++i) {
        int step;
        cin >> step;
        if (N<=K and step == N){
            cout << "T";
            return 0;
        }
        else if (N<=K)
            cout << "F" << endl;
        else if (N % (K+1) == 0)
            cout << "T" << endl;
        else if (step == N % (K +1))
            cout << "T" << endl;
        else
            cout << "F" << endl;
        N -= step;
    }
    return 0;
}