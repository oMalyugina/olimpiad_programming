//
// Created by olga on 16.07.19.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
	int x;
	int y;

	Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

	bool is_bad(int n) {
		return this->x < 0 or this->x >= n or this->y < 0 or this->y >= n;

	}

	bool operator==(Point point) {
		return (point.x == this->x and point.y == this->y);
	}

	bool operator!=(Point point) {
		return (! this->operator==(point));
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
	queue<Point> to_see;
	vector<vector<int>> field(n, vector<int>(n, 0));
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < n; ++y) {
			char c;
			cin >> c;
			if (c == '#') field[x][y] = -1;
			if (c == '@') {
				to_see.emplace(x, y);
			}
		}
	}

	Point finish = to_see.front();
	to_see.pop();
	Point start = to_see.front();
	field[start.x][start.y] = 1;

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

	if (field[finish.x][finish.y] == 0) {
		cout << "Impossible";
		return 0;
	}

	Point cur = finish;
	while (cur != start) {
		vector<Point> neighbors = get_neighbors(cur, n);

		for (auto neighbor  : neighbors) {
			if (field[neighbor.x][neighbor.y] == field[cur.x][cur.y] - 1) {
				field[cur.x][cur.y] = -5;
				cur = neighbor;
				break;
			}
		}

	}
	field[cur.x][cur.y] = -5;
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y <n ; ++y) {
			if (field[x][y] == -1) cout << "#";
			else if (field[x][y] == -5) cout << "@";
			else cout << ".";
		}
		cout << endl;
	}
	return 0;

}
