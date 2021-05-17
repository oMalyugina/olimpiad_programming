//
// Created by Olga Malyugina on 12.04.21.
//

#include <iostream>
#include <vector>
#include <list>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    string model;
    cin >> model;

    vector<int> number_bad_places(n, 0);
    vector<vector<int>> bad_cards_with_place(m, vector<int>());
    vector<list<int>> good_places(n, list<int>());

    vector<bool> closed(m, false);
    vector<int> res;
    vector<int> good;
    vector<bool> is_good(n, false);

    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        if (k == 0) {
            res.push_back(i);
            continue;
        }
        list<int> bad_current_cards;
        list<int> good_current_cards;
        for (int j = 0; j < k; ++j) {
            int place;
            char c;
            cin >> place >> c;
            place--;
            if (c == model[place])
                good_current_cards.push_back(place);
            else
                bad_current_cards.push_back(place);
        }
        for (int place:bad_current_cards) {
            bad_cards_with_place[place].push_back(i);
        }
        good_places[i] = good_current_cards;
        number_bad_places[i] = bad_current_cards.size();
        if (bad_current_cards.empty()) {
            good.push_back(i);
        }
    }

    while (not good.empty()) {
        int card_i = good.back();
        res.push_back(card_i);
        good.pop_back();
        for (int place: good_places[card_i]) {
            if (closed[place])
                continue;
            closed[place]=true;
            for (int cars_with_bad:bad_cards_with_place[place]) {
                number_bad_places[cars_with_bad]--;
                if (number_bad_places[cars_with_bad] == 0) {
                    good.push_back(cars_with_bad);
                }
            }
        }
    }
    for (bool c:closed) {
        if (c == false) {
            cout << -1;
            return 0;
        }
    }

    for (int i :res) {
        is_good[i]=true;
    }
    for (int l = 0; l < n; ++l) {
        if(is_good[l]==false)
            res.push_back(l);
    }
    for (int i :res) {
        cout << ++i << " ";
    }


    return 0;
}