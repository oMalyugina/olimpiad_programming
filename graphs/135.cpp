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
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << edges[i][j] << " ";
		}
		cout << endl;
	}
}