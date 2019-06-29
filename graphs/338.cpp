//
// Created by olga on 28.06.19.
//

#include <iostream>
using std::cin;

#include <vector>
using std::vector;

int n, m;


void dfs(vector<vector<bool>> &field, int i, int j){
	field[i][j] = true;
	if (i > 0 && field[i-1][j] == false){
		dfs(field, i-1, j);
	}
	if (j > 0 && field[i][j-1] == false){
		dfs(field, i, j-1);
	}
	if (i < n-1 && field[i+1][j] == false){
		dfs(field, i+1, j);
	}
	if (j < m-1 && field[i][j+1] == false){
		dfs(field, i, j+1);
	}
}


int main(){
//	int /n,m;
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
//				field[i][j] = true;
				++step;
				dfs(field, i, j);
			}
		}
	}
	std::cout << step;

	return 0;
}
