//
// Created by olga on 06/02/20.
//

#include <stdio.h>
#include <vector>
#include <cmath>

using namespace std;

bool find(vector<long long> &grades, long long grade) {
    int left = 0;
    int rigth = grades.size() - 1;
    while (left <= rigth) {
        int middle = ceil((left + rigth) * 1. / 2);
        if (grades[middle] == grade)
            return true;
        if (middle == 0)
            return false;
        if (left == rigth)
            return false;
        if (grades[middle] > grade)
            rigth = middle - 1;
        else
            left = middle;
    }
    return false;
}

int main() {
    int n, k;
    scanf ("%d",&n);
    scanf ("%d",&k);
    vector<long long> grades;
    long long tmp;
    scanf ("%ld",&tmp);
    grades.push_back(tmp);
    for (int i = 1; i < n; ++i) {
        scanf ("%ld",&tmp);
        if (tmp != grades.back())
            grades.push_back(tmp);
    }
    for (int i = 0; i < k; ++i) {
        scanf ("%ld",&tmp);
        if (!find(grades, tmp))
            printf ("NO ");
        else
            printf("YES ");
    }
    return 0;
}