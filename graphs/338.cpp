//
// Created by olga on 28.06.19.
//

#include <iostream>
using std::cin;

#include <vector>
using std::vector;


void dfs(vector<vector<bool>> &field, int i, int j){
	auto n = field.size();
	auto m = field[0].size();
	if (i > 0 and field[i-1][j] == false){
		field[i-1][j] = true;
		dfs(field, i-1, j);
	}
	if (j > 0 and field[i][j-1] == false){
		field[i][j-1] = true;
		dfs(field, i, j-1);
	}
	if (i < n-1 and field[i+1][j] == false){
		field[i+1][j] = true;
		dfs(field, i+1, j);
	}
	if (i < m-1 and field[i][j+1] == false){
		field[i][j+1] = true;
		dfs(field, i, j+1);
	}
}

int main(){
	int n,m;
	cin >> n >> m;
	vector<vector<bool >> field;
	for (int i = 0; i < n; ++i) {
		vector<bool> raw;
		for (int j = 0; j < m; ++j) {
			int x;
			cin >> x;
			raw.push_back(bool(x));
		}
		field.push_back(raw);
	}

	int step = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (field[i][j] == false) {
				++step;
				dfs(field, i, j);
			}
		}
	}
	std::cout << step;

	return 0;
}
