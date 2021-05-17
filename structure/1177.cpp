//
// Created by Olga Malyugina on 05.04.21.
//

#include <iostream>
#include <vector>

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    int m, n, a, b, c, d;
    cin >> m >> n >> a >>b >> c >> d;
    vector<vector<int>> field(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> field[i][j];
        }
    }

    vector<vector<long long>> integral(n, vector<long long>(m, 0));

    for (int i = 0; i < n; ++i) {
        long long cur_row = 0;
        for (int j = 0; j < m; ++j) {
            cur_row += field[i][j];
            if (i == 0)
                integral[i][j] = cur_row;
            else
                integral[i][j] = integral[i-1][j]+cur_row;
        }
    }

    for (int n_i = 0; n_i < n - a; ++n_i) {
        for (int m_i = 0; m_i < m - b; ++m_i) {
            for (int a_i = n_i+2; a_i < n_i - a - c - 2; ++a_i) {
                for (int b_i = m_i; b_i < b - d - 2; ++b_i) {
                    long long big_fiels = get_rectangle(integral, n_i, m_i, a, b);
                    long long small_field = get_rectangle(integral, n_i, m_i, a, b);
                }
                
            }
            
        }
        
    }
    return 0;
}