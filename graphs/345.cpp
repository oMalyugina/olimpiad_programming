//
// Created by olga on 04.07.19.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>


using namespace std;


bool dfs(vector<int> &seen, vector<vector<bool>> &edges, int cur, vector<int> &local_res, int start) {
	seen[cur] = 1;
	for (int i = 0; i < edges.size(); ++i) {
		if (edges[cur][i] == false) continue;
		if (seen[i] == 1 and i == start) {
			local_res.push_back(cur);
			return true;
		}
		if (seen[i] != 0) continue;
		if (dfs(seen, edges, i, local_res, start)) {
			local_res.push_back(cur);
			return true;
		}
	}
	seen[cur] = 2;
	return false;
}

int main() {
	int n;
	cin >> n;
	vector<vector<bool>> edges(n, vector<bool>(n, false));
	unordered_map<string, int> name2index;
	vector<string> names;
	for (int progpam = 0; progpam < n; ++progpam) {
		string name;
		cin >> name;
		names.push_back(name);
		if (name2index.find(name) == name2index.end()) {
			int index = name2index.size();
			name2index[name] = index;
		}
		int from = name2index[name];
		int number_calls;
		cin >> number_calls;
		for (int call = 0; call < number_calls; ++call) {
			string prog_call;
			cin >> prog_call;
			if (name2index.find(prog_call) == name2index.end()) {
				int index = name2index.size();
				name2index[prog_call] = index;
			}
			int to = name2index[prog_call];
			edges[from][to] = true;
		}
		string stars;
		cin >> stars;
	}
	vector<bool> res(n, false);
	for (auto obj: name2index) {
		if (res[obj.second] == true) continue;
		vector<int> for_dfs(n, 0);
		vector<int> local_res;
		dfs(for_dfs, edges, obj.second, local_res, obj.second);
		for (auto point_in_circle  : local_res) {
			res[point_in_circle] = true;

		}
	}
	for (auto name : names) {
		if (res[name2index[name]]) cout << "YES"<< endl;
		else cout << "NO" << endl;
	}
}
