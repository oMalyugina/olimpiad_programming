//
// Created by olga on 11.07.19.
//

//
// Created by olga on 05/07/19.
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
	cin >> m >> n;
	int field[m][n];
	int obstacle = 5000000;
	Point tiger_pose;
	Point start = Point(1,1);
	Point finish = Point(m-2, n-2);
	for (int j = 0; j < m; ++j) {
		for (int k = 0; k < n; ++k) {
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
	while (not to_see.empty() and field[finish.x][finish.y] == 0) {

		Point cur = to_see.front();
		to_see.pop();

		if (cur.x < m - 1 and field[cur.x + 1][cur.y] == 0) {
			field[cur.x + 1][cur.y] = field[cur.x][cur.y] + 1;
			to_see.push(Point(cur.x + 1, cur.y));
		}
		if (cur.x > 0 and field[cur.x - 1][cur.y] == 0) {
			field[cur.x - 1][cur.y] = field[cur.x][cur.y] + 1;
			to_see.push(Point(cur.x - 1, cur.y));
		}
		if (cur.y < n - 1 and field[cur.x][cur.y + 1] == 0) {
			field[cur.x][cur.y + 1] = field[cur.x][cur.y] + 1;
			to_see.push(Point(cur.x, cur.y + 1));
		}
		if (cur.y > 0 and field[cur.x][cur.y - 1] == 0) {
			field[cur.x][cur.y - 1] = field[cur.x][cur.y] + 1;
			to_see.push(Point(cur.x, cur.y - 1));
		}

	}
	cout << field[finish.x][finish.y] << endl;

	queue<Point> tiger_step;
	tiger_step.push(tiger_pose);
	field[tiger_pose.x][tiger_pose.y] = 0;

	while (not tiger_step.empty()) {
		Point tiger = tiger_step.front();
		tiger_step.pop();

		if (tiger.x < m - 1 and field[tiger.x + 1][tiger.y] != obstacle and field[tiger.x + 1][tiger.y] + (field[tiger.x][tiger.y] -1) >= 0) {
			field[tiger.x + 1][tiger.y] = field[tiger.x][tiger.y] -1;
			tiger_step.push(Point(tiger.x + 1, tiger.y));
		}
		if (tiger.x > 0 and field[tiger.x - 1][tiger.y] != obstacle and field[tiger.x - 1][tiger.y]  + (field[tiger.x][tiger.y] -1) >= 0) {
			field[tiger.x - 1][tiger.y] = field[tiger.x][tiger.y]-1;
			tiger_step.push(Point(tiger.x - 1, tiger.y));
		}
		if (tiger.y < n - 1 and field[tiger.x][tiger.y+1] != obstacle and field[tiger.x][tiger.y + 1]  + (field[tiger.x][tiger.y] -1) >= 0) {
			field[tiger.x][tiger.y + 1] = field[tiger.x][tiger.y]-1;
			tiger_step.push(Point(tiger.x, tiger.y + 1));
		}
		if (tiger.y > 0 and field[tiger.x][tiger.y-1] != obstacle and field[tiger.x][tiger.y - 1]  + (field[tiger.x][tiger.y] -1) >= 0) {
			field[tiger.x][tiger.y - 1] = field[tiger.x][tiger.y]-1;
			tiger_step.push(Point(tiger.x, tiger.y - 1));
		}
	}

	if (field[finish.x][finish.y] > 0) cout << "YES";
	else cout << "NO";



	return 0;

}

