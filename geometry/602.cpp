#include<iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> points;
    for (int j = 0; j < n; ++j) {
        int point;
        cin >> point;
        points.push_back(point);
    }
    int max_ = points[1]-points[0];
    int res = 1;
    for (int i=2; i<n; ++i){
        if (points[i] - points[i-1] < max_) {
            max_ = points[i] - points[i-1];
            res = i;
        }
    }

    cout << points[res-1] << " " << points[res];


}