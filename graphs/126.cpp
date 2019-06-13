//
// Created by olga on 13/06/19.
//

#include <iostream>
using std::cin;
using std::cout;

int main(){
    int N;
    cin >> N;
    int cost[N][N];
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            int tmp;
            cin >> tmp;
            cost[i][j] = tmp;
        }
    }
    int min=4000;
    for (int i=0; i<N; i++){
        for (int j=i+1; j<N; j++){
            for (int k=j+1; k<N; k++){
                int possible_sum = cost[i][k] + cost[i][j] + cost[k][j];
                if (min>possible_sum) min = possible_sum;
            }
        }
    }
    cout << min;
    return 0;
}