//
// Created by Olga Malyugina on 18.03.21.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct SQRT_decom {
    vector<int> data;
    vector<int> summs;
    int group_len = 317;
    int n = 100001;

    SQRT_decom() {
        data.assign(n, 0);
        summs.assign(n / group_len + 1, 0);
    }

    int sum_(int heigh) {
        int first_group = heigh / this->group_len;
        int last_element_in_first_group = min((first_group + 1) * this->group_len - 1, this->n - 1);
        int res = 0;
        for (int h = heigh + 1; h <= last_element_in_first_group; h++) {
            res += data[h];
        }
        for (int group_i = first_group + 1; group_i < summs.size(); ++group_i) {
            res += summs[group_i];
        }
        return res;
    }

    void update(int height) {
        data[height]++;
        summs[height / group_len]++;
    }

    void go_out(int index) {
        int people_before = 0;
        int group_i = summs.size() - 1;
        while (people_before + summs[group_i] < index) {
            people_before += summs[group_i];
            group_i--;
        }
        int last_element_in_current_group = min((group_i + 1) * group_len - 1, n - 1);
        for (int h = last_element_in_current_group;; h--) {
            people_before += data[h];
            if (people_before == index) {
                data[h] = 0;
                summs[h / group_len]--;
                return;
            }
        }
    }

};

struct FENVIC {
    vector<int> fenvic;
    int n = 100001;

    FENVIC() {
        fenvic.assign(n, 0);
    }

    int sum_(int height) {
        int inverse_height = n - height;
        int res = 0;
        for (; inverse_height >= 0; inverse_height = (inverse_height & (inverse_height + 1)) - 1) {
            res += fenvic[inverse_height];
        }
        return res;

    }

    void update(int height) {
        int inverse_height = n - height;
        for (; inverse_height < fenvic.size(); inverse_height = inverse_height | (inverse_height + 1)) {
            fenvic[inverse_height]++;
        }

    }

    int get_height_from_index(int index) {
        int l = 0;
        int r = fenvic.size() - 1;
        while (l < r) {
            int h = (l + r + 1) / 2;
            int cur_index = sum_(n-h);
            if (cur_index >= index) {
                r = h;
            } else {
                l = h;
            }
            if (l == r - 1)
                return r;
        }
    }

    void go_out(int index) {
        int inverse_height = get_height_from_index(index);
        for (; inverse_height < fenvic.size(); inverse_height = inverse_height | (inverse_height + 1)) {
            fenvic[inverse_height]--;
        }
    }
};

struct ARRAY_TREE {
    int n=pow(2,17);
    vector<int> tree;


    ARRAY_TREE() {
        tree.assign(n*2,0);

    }

    int reccursive_sum(int start, int end, int l, int r){
        int window = r-l+1;
        if (start == l and end == r){
            int index = l/window;
            return tree[index];
        }
        int half_wind = window/2;
        int res = -1;
        if (start >= l+half_wind){
            res = reccursive_sum(start, end, l+half_wind, r);
        }else if(end < l+half_wind){
            res = reccursive_sum(start, end, l, l+half_wind-1);
        }else{
            int res1 = reccursive_sum(start, l+half_wind-1, l, l+half_wind-1);
            int res2  = reccursive_sum(l+half_wind, end, l+half_wind, r);
            res = res1+res2;
        }
        return res;
    }

    int sum_(int heigh) {
        int answer = reccursive_sum(n+heigh, n+n-1, n, n+n-1);
        return answer;
    }

    void update(int height) {
        height = n+height;
        while (height > 0){
            tree[height]++;
            height = height/2;
        }
    }

    void decrease(int height){
        height = height;
        while (height > 0){
            tree[height]--;
            height = height/2;
        }
    }

    int compute_height(int index, int l, int r){
        if (l+1 == r){
            if (index == 1){
                if (tree[r] == 1)
                    return r;
                else
                    return l;
            }
            if (index == 2)
                return l;
        }
        int window = r-l+1;
        int half_window = window/2;
        int sum_in_left_subtree = tree[l/half_window];
        int sum_in_right_subtree = tree[l/half_window+1];
        if (index > sum_in_right_subtree){
            int res = compute_height(index-sum_in_right_subtree, l, l+half_window-1);
            return res;
        }else{
            int res = compute_height(index, l+half_window, r);
            return res;
        }

    }

    void go_out(int index) {
        int height = compute_height(index, n, n+n-1);
        decrease(height);
    }

};


int main() {
//    SQRT_decom data;
//    FENVIC data;
    ARRAY_TREE data;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int command;
        cin >> command;
        if (command == 1) {
            int height;
            cin >> height;
            cout << data.sum_(height) << endl;
            data.update(height);

        } else {
            int index;
            cin >> index;
            index++;
            data.go_out(index);
        }
    }
    return 0;
}