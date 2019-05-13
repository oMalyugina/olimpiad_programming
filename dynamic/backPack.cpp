//
// Created by olga on 04/03/19.
//


#include <iostream>
#include <vector>
#include <map>
#include <algorithm>    // std::sort


using std::cout;
using std::endl;
using std::cin;
using std::map;
using std::vector;
using std::sort;

struct PossibleSet {
    long long int cost = 0;
    long long int weight = 0;
    vector<int> things_id;
};

PossibleSet chose_set(PossibleSet set1, PossibleSet set2){
    if (set1.cost > set2.cost)
        return set1;
    if (set1.cost < set2.cost)
        return set2;
    if (set1.things_id.size() < set2.things_id.size())
        return set1;
    if (set1.things_id.size() > set2.things_id.size())
        return set2;
    for (int j = 0; j < set1.things_id.size(); ++j) {
        if (set1.things_id[j] < set2.things_id[j])
            return set1;
        if (set1.things_id[j] > set2.things_id[j])
            return set2;
    }
}

int main() {
    int n;
    cin >> n;
    long long int W;
    cin >> W;
    long long int weight, cost;

    map<long long int, PossibleSet> all_possible_sets;
    PossibleSet empty_set = PossibleSet();
    all_possible_sets[0] = empty_set;

    for (int i = 0; i < n; i++) {
        cin >> weight >> cost;

        map<long long int, PossibleSet> sets_for_adding;
        for (const auto &existedSet : all_possible_sets) {
            if (existedSet.first + weight> W)
                continue;

            PossibleSet set;
            set.weight = existedSet.first + weight;
            set.cost = existedSet.second.cost + cost;
            set.things_id = existedSet.second.things_id;
            set.things_id.push_back(i);
            sort(set.things_id.begin(), set.things_id.end());
            if (all_possible_sets.count(set.weight)) {
                all_possible_sets[set.weight] = chose_set(set, all_possible_sets[set.weight]);
            } else {
                sets_for_adding[set.weight] = set;
            }

        }
        for (const auto &set : sets_for_adding) {
            all_possible_sets[set.first] = set.second;
        }
    }

    int max_cost = 0;
    PossibleSet best_set = PossibleSet();
    for (const auto &item : all_possible_sets) {
        if (item.second.cost > max_cost) {
            best_set = item.second;
        }
    }
    cout << best_set.things_id.size() << " ";
    cout << best_set.cost << endl;

    for (const auto &thing : best_set.things_id) {
        cout << thing + 1 << " ";
    }

    return 0;
}


