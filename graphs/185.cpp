//
// Created by olga on 14.06.19.
//

#include <iostream>

using std::cin;
using std::cout;

#include <vector>

using std::vector;

int main() {
	int N, K;
	cin >> N >> K;

	vector<vector<int>> horses(N + 1);
	int first, second;
	cin >> first;
	while (first != 0) {
		cin >> second;
		horses[first].push_back(second);
		cin >> first;
	}

	vector<int> must_to_see;
	must_to_see.push_back(K);
	int better_than[N + 1];
	int seen[N + 1];
	for (int i = 0; i < N + 1; i++) {
		better_than[i] = 0;
		seen[i] = 0;
	}
	while (not must_to_see.empty()) {
		int cur = must_to_see[0];
		seen[cur] = 1;
		must_to_see.erase(must_to_see.begin());
		better_than[cur] = 1;
		for (auto worse:horses[cur]) {
			if (seen[worse] == 0) must_to_see.push_back(worse);
		}
	}

	for (int i = 1; i < N + 1; i++) {
		if (better_than[i] == 0) {
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}