//
// Created by olga on 11.07.19.
//

#include <iostream>
#include <queue>

using namespace std;

struct Point {
	int x = 0;
	int y = 0;

	Point(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
};


int main() {
	int m, n;
	cin >> n >> m;
	int field[n][m];
	int obstacle = -1;
	Point tiger_pose;
	Point start = Point(1, 1);
	Point finish = Point(n - 2, m - 2);
	for (int j = 0; j < n; ++j) {
		for (int k = 0; k < m; ++k) {
			char cell;
			cin >> cell;
			if (cell == '#') field[j][k] = obstacle;
			else {
				field[j][k] = 0;
				if (cell == 'T') {
					tiger_pose = Point(j, k);
				}
			}
		}
	}
	queue<Point> to_see;
	to_see.push(start);
	field[start.x][start.y] = 1;
	while (not to_see.empty() and field[finish.x][finish.y] == 0) {

		Point cur = to_see.front();
		to_see.pop();

		if (cur.x < n - 1 and field[cur.x + 1][cur.y] == 0) {
			field[cur.x + 1][cur.y] = field[cur.x][cur.y] + 1;
			to_see.push(Point(cur.x + 1, cur.y));
		}
		if (cur.x > 0 and field[cur.x - 1][cur.y] == 0) {
			field[cur.x - 1][cur.y] = field[cur.x][cur.y] + 1;
			to_see.push(Point(cur.x - 1, cur.y));
		}
		if (cur.y < m - 1 and field[cur.x][cur.y + 1] == 0) {
			field[cur.x][cur.y + 1] = field[cur.x][cur.y] + 1;
			to_see.push(Point(cur.x, cur.y + 1));
		}
		if (cur.y > 0 and field[cur.x][cur.y - 1] == 0) {
			field[cur.x][cur.y - 1] = field[cur.x][cur.y] + 1;
			to_see.push(Point(cur.x, cur.y - 1));
		}

	}
	int shortest_path = field[finish.x][finish.y] - 1;
	cout << shortest_path << endl;

//	cout << "man step"  << endl;
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < m; ++j) {
//			cout << field[i][j] << " ";
//		}
//		cout << endl;
//	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (field[i][j] >= 0) field[i][j] = 0;
		}
	}

	queue<Point> tiger_step;
	tiger_step.push(tiger_pose);
	field[tiger_pose.x][tiger_pose.y] = 1;

	while (not tiger_step.empty()) {
		Point tiger = tiger_step.front();
		tiger_step.pop();

		if (tiger.x < n - 1 and field[tiger.x + 1][tiger.y] == 0) {
			field[tiger.x + 1][tiger.y] = field[tiger.x][tiger.y] +1 ;
			tiger_step.push(Point(tiger.x + 1, tiger.y));
		}
		if (tiger.x > 0 and field[tiger.x - 1][tiger.y] == 0) {
			field[tiger.x - 1][tiger.y] = field[tiger.x][tiger.y] + 1;
			tiger_step.push(Point(tiger.x - 1, tiger.y));
		}
		if (tiger.y < m - 1 and field[tiger.x][tiger.y + 1] == 0) {
			field[tiger.x][tiger.y + 1] = field[tiger.x][tiger.y] + 1;
			tiger_step.push(Point(tiger.x, tiger.y + 1));
		}
		if (tiger.y > 0 and field[tiger.x][tiger.y - 1] == 0) {
			field[tiger.x][tiger.y - 1] = field[tiger.x][tiger.y] + 1;
			tiger_step.push(Point(tiger.x, tiger.y - 1));
		}
	}

//	cout << "tiger step"  << endl;
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < m; ++j) {
//			cout << field[i][j] << " ";
//		}
//		cout << endl;
//	}

	if (field[finish.x][finish.y] != 0  and field[finish.x][finish.y] -1 <= shortest_path ) cout << "No";
	else cout << "Yes";

	return 0;

}


