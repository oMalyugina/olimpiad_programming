//
// Created by olga on 22/08/19.
//

#include <iostream>
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
    int start = 0, end = 1;
    double l_m = (points[end] - points[start])*1./2;
    double min_l_m = l_m;
    int min_first = 0, min_end = 1;
    for (int i = 2; i < n; ++i) {
        double possible_l_m = (points[i] - points[start])*1./(i-start+1);
        double new_l_m = (points[i] - points[end])*1./2;
        if (possible_l_m <= new_l_m and possible_l_m <= l_m){
            l_m = possible_l_m;
            end = i;
        } else {
            l_m = new_l_m;
            start = end;
            end = i;
        }
        if (l_m < min_l_m){
            min_l_m = l_m;
            min_first = start;
            min_end = end;
        }
    }
    cout << points[min_first] << " " << points[min_end];
}