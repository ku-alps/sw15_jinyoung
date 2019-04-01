#include <iostream>
#include <queue>
using namespace std;
typedef struct {
    int y, x;
}Dir;
Dir direction[4] = {
    {0,1},{1,0},{0,-1},{-1,0}
};

int M, N;
int map[1000][1000];
int visit[1000][1000];
int result_max = 0;

int main() {
    cin >> M >> N;
    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            visit[i][j] = -1;
            if (map[i][j] == 1) {
                q.push(make_pair(i, j));
                visit[i][j] = 0;
            }
        }
    }
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        map[y][x] = 1;
        if (result_max < visit[y][x]) {
            result_max = visit[y][x];
        }

        for (int i = 0; i < 4; i++) {
            int nextY = y + direction[i].y;
            int nextX = x + direction[i].x;

            if (nextY >= 0 && nextY < N && nextX >= 0 && nextX < M) {
                if (map[nextY][nextX] == 0 && visit[nextY][nextX] == -1) {
                    q.push(make_pair(nextY, nextX));
                    visit[nextY][nextX] = visit[y][x]+1;
                }
            }
        }
    }
    bool check = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0) {
                cout << -1 << endl;
                check = true;
            }
        }
        if (check == true) {
            break;
        }
    }
    if (check == false) {
        cout << result_max << endl;
    }
}