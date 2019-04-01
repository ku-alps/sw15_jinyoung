#include <iostream>
#include <queue>
using namespace std;
typedef struct {
    int y, x;
}Dir;
Dir direction[4] = {
    {0,1},{1,0},{0,-1},{-1,0}
};

int N;
int map[101][101];
int K;
int L;
queue<pair<int, char>> que;
int dir_num = 0;

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            map[i][j] = 0;
        }
    }

    cin >> K;
    int from, to;
    for (int i = 0; i < K; i++) {
        cin >> from >> to;
        map[from][to] = 1; //»ç°ú
    }
    int time;
    char dir;
    cin >> L;
    for (int i = 0; i < L; i++) {
        cin >> time >> dir;
        que.push(make_pair(time, dir));
    }

    queue<pair<int, int>> q;
    queue<pair<int, int>> tail_q;

    q.push(make_pair(1, 1));
    int now = que.front().first;
    char now_dir = que.front().second;
    que.pop();
    int count = 0;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if (y > N || y < 1 || x > N || x < 1 || map[y][x] == 2) {
            break;
        }


        if (map[y][x] == 0 && count > 0) {//²¿¸®À§Ä¡ ºñ¿öÁÜ
            map[tail_q.front().first][tail_q.front().second] = 0;
            tail_q.pop();
        }
        else if (map[y][x] == 1) {
            map[y][x] = 0; //»ç°ú ¾ø¾Ú
        }
        map[y][x] = 2;
        tail_q.push(make_pair(y, x));

        if (count == now) {
            if (now_dir == 'L') {
                dir_num -= 1;
                int nextY = y + direction[(dir_num + 4) % 4].y;
                int nextX = x + direction[(dir_num + 4) % 4].x;

                q.push(make_pair(nextY, nextX));
                dir_num = (dir_num + 4) % 4;
            }
            else{
                dir_num += 1;
                int nextY = y + direction[(dir_num + 4) % 4].y;
                int nextX = x + direction[(dir_num + 4) % 4].x;

                q.push(make_pair(nextY, nextX));
                dir_num = (dir_num + 4) % 4;
            }
            if (que.size()) {
                now = que.front().first;
                now_dir = que.front().second;
                que.pop();
            }
        }
        else {
            int nextY = y + direction[(dir_num + 4) % 4].y;
            int nextX = x + direction[(dir_num + 4) % 4].x;

            q.push(make_pair(nextY, nextX));
        }
        count += 1;

    }
    cout << count << endl;
}