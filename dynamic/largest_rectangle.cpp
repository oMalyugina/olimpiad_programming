//
// Created by Olga Malyugina on 21.03.20.
//
#include <vector>
#include <stack>
#include <iostream>
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


int main(){
    vector<int> h = {1, 1, 4, 4, 5, 5, 3, 3, 2, 2};
    cout << largestRectangle(h);
    return 0;
}
