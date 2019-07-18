//
// Created by olga on 18.07.19.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct Point {
	int x;
	int y;

	Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}


	bool operator==(Point point) {
		return (point.x == this->x and point.y == this->y);
	}

	bool operator!=(Point point) {
		return (!this->operator==(point));
	}
};

vector<Point> get_neighbors(Point point, int n) {
	vector<Point> possible_neighbors;
	possible_neighbors.emplace_back(point.x, point.y - 1);
	possible_neighbors.emplace_back(point.x + 1, point.y);
	possible_neighbors.emplace_back(point.x, point.y + 1);
	possible_neighbors.emplace_back(point.x - 1, point.y);
	return possible_neighbors;
}

char get_direction(Point from, Point to) {
	if (from.x == to.x + 1) return 'W';
	if (from.x == to.x - 1) return 'E';
	if (from.y == to.y + 1) return 'N';
	if (from.y == to.y - 1) return 'S';
	return 'A';
}

int main() {
	string path;
	cin >> path;
	int n = path.size() * 4 + 20;
	vector<vector<int>> field(n, vector<int>(n, -1));
	int start_x = n / 2;
	int start_y = n / 2;
	int cur_x = start_x;
	int cur_y = start_y;
	field[cur_x][cur_y] = 1;
	for (auto step : path) {
		if (step == 'N') cur_y -= 1;
		if (step == 'E') cur_x += 1;
		if (step == 'W') cur_x -= 1;
		if (step == 'S') cur_y += 1;
		field[cur_x][cur_y] = 0;
		if (step == 'N') cur_y -= 1;
		if (step == 'E') cur_x += 1;
		if (step == 'W') cur_x -= 1;
		if (step == 'S') cur_y += 1;
		field[cur_x][cur_y] = 0;
	}

	int finish_x = cur_x;
	int finish_y = cur_y;

	queue<Point> to_see;
	to_see.emplace(start_x, start_y);
	field[start_x][start_y] = 1;
	while (not to_see.empty()) {
		Point cur = to_see.front();
		to_see.pop();
		vector<Point> neighbors = get_neighbors(cur, n);

		for (auto neighbor  : neighbors) {
			if (field[neighbor.x][neighbor.y] != 0) continue;
			field[neighbor.x][neighbor.y] = field[cur.x][cur.y] + 1;
			to_see.push(neighbor);
		}
	}

	Point cur(finish_x, finish_y);
	while (cur != Point(start_x, start_y)) {
		vector<Point> neighbors = get_neighbors(cur, n);

		for (auto neighbor  : neighbors) {
			if (field[neighbor.x][neighbor.y] == field[cur.x][cur.y] - 1) {
				char direction = get_direction(cur, neighbor);
				cout << direction;
				if (direction == 'N') cur = Point(neighbor.x, neighbor.y - 1);
				if (direction == 'E') cur = Point(neighbor.x + 1, neighbor.y);
				if (direction == 'W') cur = Point(neighbor.x - 1, neighbor.y);
				if (direction == 'S') cur = Point(neighbor.x, neighbor.y + 1);
				break;
			}
		}

	}
	return 0;

}



