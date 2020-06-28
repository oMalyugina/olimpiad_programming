//
// Created by Olga Malyugina on 17.04.20.
//

//
// Created by olga on 24.01.20.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

long largestRectangle(const vector<int> &h) {
    stack<int> res;
    res.push(-1);
    int max_rectangle = 0;
    for (int i = 0; i < h.size(); ++i) {
        if (res.top() == -1) {
            res.push(i);
            continue;
        }
        int cur = h[i];
        while (res.top() != -1 and h[res.top()] > cur) {
            int prev_i = res.top();
            res.pop();
            int square = h[prev_i] * (i - res.top()-1);
            max_rectangle = max(max_rectangle, square);
        }
        res.push(i);
    }
    while ( res.size()>1) {
        int cur_i = res.top();
        res.pop();
        int square = h[cur_i] * (h.size() - res.top()-1);
        max_rectangle = max(max_rectangle, square);
    }

    return max_rectangle;

}


template <class T>
void print_matrix(const vector<vector<T>>& matrix){
    cout << "print matrix" << endl;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<bool>> map(N, vector<bool>(M, false));
    vector<vector<int>> hres(N, vector<int>(M+1, 0));
    vector<vector<int>> max_squared(N, vector<int>(M+1, 0));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            char tmp;
            cin >> tmp;
            map[i][j] = tmp == '0';
        }
    }

    for (int i = N - 1; i >= 0; --i) {
        for (int j = M; j >= 1; --j) {
            if (map[i][j-1])
                continue;
            if (i==N-1)
                hres[i][j]=1;
            else
                hres[i][j]=hres[i+1][j]+1;
        }
    }

//    print_matrix(map);
//    print_matrix(hres);

    int max_rect = 0;
    for (int i = 0; i < N; ++i) {
        int square = largestRectangle(hres[i]);
        square = max(max_rect, square);
        max_rect = max(max_rect, square);
    }

//    print_matrix(max_squared);
    cout << max_rect;

    return 0;
}
