//
// Created by olga on 15.07.19.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Point {
	int x;
	int y;

	Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

	bool is_bad(int n) {
		return this->x < 0 or this->x >= n or this->y < 0 or this->y >= n;

	}
};


vector<Point> get_neighbors(Point point, int n) {
	vector<Point> possible_neighbors;
	possible_neighbors.emplace_back(point.x + 2, point.y + 1);
	possible_neighbors.emplace_back(point.x - 2, point.y + 1);
	possible_neighbors.emplace_back(point.x + 2, point.y - 1);
	possible_neighbors.emplace_back(point.x - 2, point.y - 1);
	possible_neighbors.emplace_back(point.x + 1, point.y + 2);
	possible_neighbors.emplace_back(point.x + 1, point.y - 2);
	possible_neighbors.emplace_back(point.x - 1, point.y + 2);
	possible_neighbors.emplace_back(point.x - 1, point.y - 2);
	vector<Point> good_neighbors;
	for (auto neighbor : possible_neighbors) {
		if (neighbor.is_bad(n)) continue;
		good_neighbors.push_back(neighbor);
	}
	return good_neighbors;
}

int main() {
	int n;
	cin >> n;
	int x, y;
	cin >> x >> y;
	Point start(--x, --y);
	cin >> x >> y;
	Point finish(--x, --y);

	vector<vector<int>> field(n, vector<int>(n, 0));
	field[start.x][start.y] = 1;
	queue<Point> to_see;
	to_see.push(start);
	while (not to_see.empty() and field[finish.x][finish.y] == 0) {
		Point cur = to_see.front();
		to_see.pop();
		vector<Point> neighbors = get_neighbors(cur, n);

		for (auto neighbor  : neighbors) {
			if (field[neighbor.x][neighbor.y] != 0) continue;
			field[neighbor.x][neighbor.y] = field[cur.x][cur.y] + 1;
			to_see.push(neighbor);
		}
	}

	cout << field[finish.x][finish.y] -1;

}
