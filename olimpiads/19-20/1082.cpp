//
// Created by Olga Malyugina on 24.02.21.
//

#include <iostream>
#include <vector>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<long long>> array(n, vector<long long>(m,0));
    for (int i = 0; i < n; ++i) {
        long long cur = 0;
        for (int j = 0; j < m; ++j) {
            int tmp;
            cin >> tmp;
            cur += tmp;
            if (i==0){
                array[i][j]=cur;
            }else{
                array[i][j]= array[i-1][j]+cur;
            }
        }
    }
    for (int l = 0; l < k; ++l) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1>>y2>>x2;
        if (y1 == 1 and x1 == 1) {
            cout << array[y2 - 1][x2 - 1] << endl;
        }else if (y1 == 1) {
            cout << array[y2 - 1][x2 - 1] - array[y2 - 1][x1 - 2] << endl;
        }else if (x1 == 1) {
            cout << array[y2 - 1][x2 - 1] - array[y1 - 2][x2 - 1] << endl;
        }else {
            cout << array[y2 - 1][x2 - 1] - array[y2 - 1][x1 - 2] - array[y1 - 2][x2 - 1] + array[y1 - 2][x1 - 2] << endl;
        }

    }
    return 0;
}