#include<iostream>
#include<algorithm>
#include<queue>
#include<list>
using namespace std;

typedef struct {
    int y, x;
}Dir;
Dir direction[4] = { {0,1},{1,0},{-1,0},{0,-1} };

int main() {
    int N;
    int map[102][102];
    int temp[102][102];
    int result = 0;

    //init
    for (int i = 0; i < 102; i++) {
        for (int j = 0; j < 102; j++) {
            map[i][j] = 0;
            temp[i][j] = 0;
        }
    }

    //input
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    list<int> li;
    for (int h = 0; h < 101; h++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                temp[i][j] = map[i][j];
                if (temp[i][j] < h) {
                    temp[i][j] = 0; //못가게 표시
                }
            }
        }
        queue<pair<int, int>> q;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (temp[i][j] == 0) {
                    continue;
                }
                result++;
                q.push(make_pair(i, j));
                while (!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;

                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int nextY = y + direction[k].y;
                        int nextX = x + direction[k].x;

                        if (0 <= nextY && nextY < N && 0 <= nextX && nextX < N) {
                            if (temp[nextY][nextX] != 0) {
                                temp[nextY][nextX] = 0;
                                q.push(make_pair(nextY, nextX));
                            }
                        }
                    }
                }

            }
        }
        li.push_back(result);
        result = 0;

    }
    li.sort();
    cout << li.back() << endl;
}