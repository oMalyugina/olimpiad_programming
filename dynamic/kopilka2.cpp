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
	int array[weight + 1];
	array[0] = 0;
	for (int weight_i = 1; weight_i <= weight; ++weight_i) {
		array[weight_i] = -1;
	}

	for (int weight_i = 1; weight_i <= weight; ++weight_i) {
		int max = -1;
		for (const auto &coin : coins) {
			if (weight_i < coin.weight)
				continue;
			if (array[weight_i - coin.weight] == -1)
				continue;
			int curr_cost = array[weight_i - coin.weight] + coin.cost;
			if (curr_cost > max)
				max = curr_cost;
		}
		array[weight_i] = max;
	}

//	cout << "array" << endl;
//	for (int weight_i = 0; weight_i <= weight; ++weight_i) {
//		cout << array[weight_i] << " ";
//	}
//	cout << "res" << endl;

	int max = array[weight];

	array[0] = 0;
	for (int weight_i = 1; weight_i <= weight; ++weight_i) {
		array[weight_i] = max_int;
	}

	for (int weight_i = 1; weight_i <= weight; ++weight_i) {
		int min = max_int;
		for (const auto &coin : coins) {
			if (weight_i < coin.weight)
				continue;
			if (array[weight_i - coin.weight] == max_int)
				continue;
			int curr_cost = array[weight_i - coin.weight] + coin.cost;
			if (curr_cost < min)
				min = curr_cost;
		}
		array[weight_i] = min;
	}
	int min = array[weight];

//	cout << "array" << endl;
//	for (int weight_i = 0; weight_i <= weight; ++weight_i) {
//		cout << array[weight_i] << " ";
//	}
//	cout << "res" << endl;

	if (min == -1 or max == -1) {
		cout << "This is impossible." << endl;
	} else {
		cout << min << " " << max << endl;
	}
	return 0;
}
