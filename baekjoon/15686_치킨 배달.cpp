#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;
typedef struct {
	int y, x;
}Dir;
Dir direction[4] = {
	{-1,0},{0,-1},{1,0},{0,1}
};
int N, M;
int map[51][51];
vector<pair<int, int>> v;
int min_distance = 100000;
int arr[14];
int visit[51][51];

void find_short(int y,int x) {
	int result = 0;
	for (int i = 1; i <= N; i++) { 
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == 1) {
				visit[i][j] = min(abs(i - y) + abs(j - x),visit[i][j]);
				result += visit[i][j];
			}
		}
	}
	if (result < min_distance) {
		min_distance = result;
	}
}

void BF(int start, int depth) {
	if (depth == M) {
		for (int i = 1; i <= N; i++) { 
			for (int j = 1; j <= N; j++) {
				visit[i][j] = 10000;
			}
		}
		for (int i = 0; i < M; i++) {
			find_short(v.at(arr[i]).first, v.at(arr[i]).second);
		}
	}
	for (int i = start; i < v.size(); i++) {
		if (depth <= M - 1) {
			arr[depth] = i;
			BF(i + 1, depth + 1);
		}
	}
}


int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) { //1부터 시작
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				v.push_back(make_pair(i, j));
				map[i][j] = 0;
			}
		}
	}
	BF(0, 0);
	cout << min_distance << endl;

}