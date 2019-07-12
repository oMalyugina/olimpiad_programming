//
// Created by olga on 12.07.19.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> edges;
	for (int i = 0; i < m; ++i) {
		int from, to, cost;
		cin >> from >> to >> cost;
		--from;
		--to;
		vector<int> edge = {from, to, cost};
		edges.push_back(edge);
	}

	vector<int> path(n, 30000);
	path[0] = 0;
	for (int l = 0; l < n - 1; ++l) {
		for (auto edge : edges) {
			int from = edge[0];
			int to = edge[1];
			int cost = edge[2];
			if (path[from] != 30000 and path[to] > path[from] + cost) path[to] = path[from] + cost;
		}
	}
	for (int k = 0; k < n; ++k) {
		cout << path[k] << " ";
	}
}