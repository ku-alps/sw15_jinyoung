#include <iostream>
#include <queue>
using namespace std;
typedef struct {
    int y, x;
}Dir;
Dir direction[5] = {
    {0,0},{0,1},{0,-1},{-1,0},{1,0}
};

int N, M, x, y, K;
int map[200][200];

int dice[7];
int change[5][7] = {
    {0,0,0,0,0,0,0},{0,3,2,6,1,5,4},{0,4,2,1,6,5,3},{0,2,6,3,4,1,5},{0,5,1,3,4,6,2}
};

int main() {
    for (int i = 1; i <= 6; i++) {
        dice[i] = 0;
    }
    cin >> N >> M >> x >> y >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
    int temp;
    queue<int> dir_q;
    for (int i = 1; i <= K; i++) {
        cin >> temp;
        dir_q.push(temp);
    }
    queue<pair<int, int>> q;

    q.push(make_pair(x, y));
    while (!dir_q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        int dir = dir_q.front();
        int nextY = y + direction[dir].y;
        int nextX = x + direction[dir].x;
        dir_q.pop();
        if (nextY >= 0 && nextY < N && nextX >= 0 && nextX < M) {
        q.pop();

        int dice_temp[7];
        for (int i = 1; i <= 6; i++) { //주사위 값 바꾸기
            dice_temp[change[dir][i]] = dice[i];
        }
        for (int i = 1; i <= 6; i++) { 
            dice[i] = dice_temp[i];
        }
            if (map[nextY][nextX] == 0) {
                map[nextY][nextX] = dice[1];
            }
            else {
                dice[1] = map[nextY][nextX];
                map[nextY][nextX] = 0;
            }
            q.push(make_pair(nextY, nextX));
            cout << dice[6] << endl;
        }
        else {
            continue;
        }
    }

}