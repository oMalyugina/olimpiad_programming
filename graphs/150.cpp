//
// Created by olga on 29/06/19.
//

#include<iostream>
#include<vector>
#include <queue>
using namespace std;

int main(){
    int n_people, cur_people;
    cin >> n_people >> cur_people;
    cur_people--;
    vector<vector<bool >> friends(n_people, vector<bool >(n_people, 0));
    for (int i = 0; i < n_people; ++i) {
        for (int j = 0; j < n_people; ++j) {
            int value;
            cin >> value;
            friends[i][j] = bool(value);
        }
    }

    vector<bool> people(n_people, false);
    queue<int> to_see;
    to_see.push(cur_people);
    people[cur_people] = true;
    while (not to_see.empty()){
        cur_people = to_see.front();
        to_see.pop();
        for (int friend_i = 0; friend_i < n_people; ++friend_i) {
            if (friends[cur_people][friend_i] == true && people[friend_i] == false){
                to_see.push(friend_i);
                people[friend_i] = true;
            }
        }
    }
    int res = 0;
    for (bool is_friend  : people) {
        res += int(is_friend);

}
    cout << res-1;
}