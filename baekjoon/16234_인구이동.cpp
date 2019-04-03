#include <iostream>
#include<queue>
#include<math.h>
using namespace std;
typedef struct {
	int y, x;
}Dir;
Dir direction[4] = {
	{-1,0},{1,0},{0,-1},{0,1}
};

int N, L, R;
int map[50][50];
int visit[50][50];
int result = 0;


bool check() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			for (int k = 0; k < 4; k++) {
				int nextY = i + direction[k].y;
				int nextX = j + direction[k].x;

				if (nextY >= 0 && nextY < N && nextX >= 0 && nextX < N) {
					int diff = abs(map[i][j] - map[nextY][nextX]);
					if (diff >= L && diff <= R) {
						return true;
					}
				}
			}

		}
	}
	return false;
}
int main() {

	cin >> N >> L >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			visit[i][j] = -1;
		}
	}
	while (1) {
		if (check() == false) {
			break;
		}
		result += 1;
		int count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visit[i][j] == -1) {
					queue<pair<int, int>> q;

					q.push(make_pair(i, j));
					visit[i][j] = count;
					int people = 0;
					int country_num = 0;
					while (!q.empty()) {
						int y = q.front().first;
						int x = q.front().second;
						q.pop();

						country_num += 1;
						people += map[y][x];

						for (int k = 0; k < 4; k++) {
							int nextY = y + direction[k].y;
							int nextX = x + direction[k].x;

							if (nextY >= 0 && nextY < N && nextX >= 0 && nextX < N) {
								int diff = abs(map[y][x] - map[nextY][nextX]);

								if (diff >= L && diff <= R && visit[nextY][nextX] == -1) {
									q.push(make_pair(nextY, nextX));
									visit[nextY][nextX] = count;
								}
							}
						}
					}
					if (country_num > 1) {
						people = people / country_num;

						for (int i = 0; i < N; i++) {
							for (int j = 0; j < N; j++) {
								if (visit[i][j] == count) {
									map[i][j] = people;
								}
							}
						}
					}
					count += 1;
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visit[i][j] = -1;
			}
		}
	}
	cout << result << endl;
}