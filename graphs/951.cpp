//
// Created by olga on 14.06.19.
//

#include <iostream>

using std::cin;
using std::cout;

#include <vector>

using std::vector;

int main(){
	int n,m, k;
	cin >> n >> m >> k;

	vector<vector<int>> viruses;
	for (int i=0; i< k; i++){
		int x,y;
		cin >> x >> y;
		vector<int> virus;
		virus.push_bach(x);
		virus.push_bach(y);
		viruses.push_back(virus);
	}


	return 0;
}