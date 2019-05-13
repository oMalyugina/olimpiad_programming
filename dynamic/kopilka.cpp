//
// Created by olga on 11/05/19.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

static const int max_int = std::numeric_limits<int>::max();
using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Coin {
    int cost;
    int weight;
};

int main() {
    int E, F;
    cin >> E >> F;
    int weight = F - E;
    int N;
    cin >> N;
    vector<Coin> coins;
    for (int i = 0; i < N; ++i) {
        Coin coin;
        cin >> coin.cost >> coin.weight;
        coins.push_back(coin);
    }
    if (weight == 0) {
        cout << 0 << " " << 0;
        return 0;
    }
    int array[N][weight + 1];
    for (int weight_i = 0; weight_i <= weight; ++weight_i) {
        for (int object_i = 0; object_i < N; ++object_i) {
            array[object_i][weight_i] = 0;
        }
        if (weight_i % coins[0].weight == 0) {
            array[0][weight_i] = weight_i / coins[0].weight * coins[0].cost;
        }
    }

    for (int object_i = 1; object_i < N; ++object_i) {
        for (int weight_i = 1; weight_i < weight + 1; ++weight_i) {
            if (weight_i == coins[object_i].weight) {
                array[object_i][weight_i] = std::max(
                        array[object_i][weight_i - coins[object_i].weight] + coins[object_i].cost,
                        array[object_i - 1][weight_i]);
            } else if (weight_i > coins[object_i].weight and array[object_i][weight_i - coins[object_i].weight] != 0) {
                array[object_i][weight_i] = std::max(
                        array[object_i][weight_i - coins[object_i].weight] + coins[object_i].cost,
                        array[object_i - 1][weight_i]);
            } else {
                array[object_i][weight_i] = array[object_i - 1][weight_i];
            }
        }
    }
//    cout << "array" << endl;
//    for (int weight_i = 0; weight_i <= weight; ++weight_i) {
//        for (int object_i = 0; object_i < N; ++object_i) {
//            cout << array[object_i][weight_i] << " ";
//        }
//        cout << endl;
//    }

    int max = array[N - 1][weight];

    for (int weight_i = 0; weight_i <= weight; ++weight_i) {
        for (int object_i = 0; object_i < N; ++object_i) {
            array[object_i][weight_i] = max_int;
            array[object_i][0] = 0;
        }
        if (weight_i % coins[0].weight == 0) {
            array[0][weight_i] = weight_i / coins[0].weight * coins[0].cost;
        }
    }

    for (int object_i = 1; object_i < N; ++object_i) {
        for (int weight_i = 1; weight_i < weight + 1; ++weight_i) {
            if (weight_i >= coins[object_i].weight and
                array[object_i][weight_i - coins[object_i].weight] != max_int) {
                array[object_i][weight_i] = std::min(
                        array[object_i][weight_i - coins[object_i].weight] + coins[object_i].cost,
                        array[object_i - 1][weight_i]);
            } else {
                array[object_i][weight_i] = array[object_i - 1][weight_i];
            }
        }
    }
    int min = array[N - 1][weight];

//    cout << "array" << endl;
//    for (int weight_i = 0; weight_i <= weight; ++weight_i) {
//        for (int object_i = 0; object_i < N; ++object_i) {
//            cout << array[object_i][weight_i] << " ";
//        }
//        cout << endl;
//    }
//    cout << "res" << endl;

    if (min == max_int or max == 0) {
        cout << "This is impossible." << endl;
    } else {
        cout << min << " " << max << endl;
    }
    return 0;
}
