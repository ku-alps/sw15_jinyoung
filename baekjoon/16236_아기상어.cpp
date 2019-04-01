#include <iostream>
#include <queue>
using namespace std;
typedef struct {
	int y, x;
}Dir;
Dir direction[4] = {
	{-1,0},{0,-1},{0,1},{1,0}
};

int N;
int map[20][20];
int visit[20][20];
int result = 0;
pair<int, int> find_point(int size, int y, int x) {
	pair<int, int> p = (make_pair(-1, -1));
	queue<pair<int, int>> _q;
	int _min = 10000;
	int temp[20][20] = { 0, };
	_q.push(make_pair(y, x));


	while (!_q.empty()) {
		int _y = _q.front().first;
		int _x = _q.front().second;
		_q.pop();
		if (_min > temp[_y][_x] && temp[_y][_x] != 0 && map[_y][_x] < size && map[_y][_x] != 0) {
			_min = temp[_y][_x];
			p = make_pair(_y, _x);
		}
		if (_min == temp[_y][_x] && map[_y][_x] < size && map[_y][_x] != 0) {
			if (_y < p.first) {
				p = make_pair(_y, _x);
			}
			else if (_y == p.first) {
				if (_x < p.second) {
					p = make_pair(_y, _x);
				}
			}
		}

	for (int k = 0; k < 4; k++) {
		int nextY = _y + direction[k].y;
		int nextX = _x + direction[k].x;

		if (nextY >= 0 && nextY < N && nextX >= 0 && nextX < N) {
			if (map[nextY][nextX] <= size && temp[nextY][nextX] == 0) {
				_q.push(make_pair(nextY, nextX));
				temp[nextY][nextX] = temp[_y][_x] + 1;
			}
		}
	}
}
return p;
}

int main() {
	cin >> N;

	queue<pair<int, int>> q;
	int size = 2;
	pair<int, int> f_point;
	int first_y, first_x = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			visit[i][j] = 0;
			if (map[i][j] == 9) {
				q.push(make_pair(i, j));
				first_y = i;
				first_x = j;
				map[i][j] = 0;
			}
		}
	}
	int eat_count = 0;
	f_point = find_point(size, first_y, first_x);
	while (!q.empty()) {

		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if (f_point.first == -1 || f_point.second == -1) {
			break;
		}

		if (f_point.first == y && f_point.second == x) {
			eat_count += 1;
			map[y][x] = 0; //¸ÔÀº ÈÄ ºó Ä­ÀÌ µÊ
			result += visit[y][x];
			while (!q.empty()) {
				q.pop();
			}
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					visit[i][j] = 0; //¹æ¹®¹è¿­ ¸®¼Â
				}
			}
			if (eat_count == size) {
				size += 1;
				eat_count = 0;
			}
			f_point = find_point(size, y, x);
		}

		for (int i = 0; i < 4; i++) {
			int nextY = y + direction[i].y;
			int nextX = x + direction[i].x;


			if (nextY >= 0 && nextY < N && nextX >= 0 && nextX < N) {
				if (visit[nextY][nextX] == 0 && map[nextY][nextX] <= size) {
					q.push(make_pair(nextY, nextX));
					visit[nextY][nextX] = visit[y][x] + 1;
				}
			}
		}
	}
	cout << result << endl;
}