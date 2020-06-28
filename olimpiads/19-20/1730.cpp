#include<iostream>

using namespace std;

int solution1(int number){
    for (int i = 9999; i > 999; --i) {
        int tmp = i/100;
        int first = tmp/10 + tmp%10;
        tmp = i%100;
        int second = tmp/10 + tmp%10;
        int max_ = max(second, first);
        int min_ = min(second, first);
        int probnumber;
        if (min_ < 10)
            probnumber = max_*10+min_;
        else
            probnumber = max_*100+min_;
        if (probnumber == number){
            return i;
        }

    }
    return 0;
}

int solution2(int number){
    int first, second, third, forth;
    if (number < 10) {
        return 0;
    }
    if (number > 999) {
        int tmp1 = number / 100;
        if (tmp1 > 18) {
            return 0;
        }
        first = 9;
        second = tmp1 - 9;
        int tmp2 = number % 100;
        if (tmp2 > 18) {
            return 0;
        }
        if (tmp2 < 10) {
            return 0;
        }
        if (tmp2 > tmp1) {
            return 0;
        }
        third = 9;
        forth = tmp2 - 9;
    } else if (number < 100) {
        int tmp1 = number / 10;
        first = tmp1;
        second = 0;
        int tmp2 = number % 10;
        if (tmp2 > tmp1) {
            return 0;
        }
        third = tmp2;
        forth = 0;
    } else {
        int tmp = number / 10;
        if (tmp > 18) {
            return 0;
        }
        first = 9;
        second = tmp - 9;
        tmp = number % 10;
        third = tmp;
        forth = 0;
    }

    return first*1000+ second*100+ third*10+ forth;
}


int main(){
    for (int i = 0; i < 10000; ++i) {
        if (solution1(i) != solution2(i)){
            cout << i << " "  << solution1(i) << " " << solution2(i) << endl;
        }
    }
}
