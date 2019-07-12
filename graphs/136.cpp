//
// Created by olga on 12.07.19.
//

#include <iostream>

using namespace std;
int main(){
	int n;
	cin >> n;
	int edges[n][n];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> edges[i][j];
			if (edges[i][j] == -1) edges[i][j] = 1000000;
		}
	}
	for (int vertex = 0; vertex < n; ++vertex) {
		for (int from = 0; from < n; ++from) {
			for (int to = 0; to < n; ++to) {
				if (edges[from][to] > edges[from][vertex] + edges[vertex][to])
					edges[from][to] = edges[from][vertex] + edges[vertex][to];
			}
		}
	}
	int max = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (edges[i][j] !=1000000 and edges[i][j] > max) max = edges[i][j];
		}
	}
	cout << max;

}