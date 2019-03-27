#include <iostream>
#include <queue>
using namespace std;
#define SIZE 100001

bool visit[SIZE];

int bfs(int from, int to) {
    queue<pair<int, int>> q;

    q.push(make_pair(from, 0));
    visit[from] = true;

    while (!q.empty()) {
        int now = q.front().first;
        int count = q.front().second;
        q.pop();


        if (now == to) {
            return count;
        }

        if (now + 1 < SIZE && !visit[now + 1]) {
            q.push(make_pair(now + 1, count + 1));
            visit[now + 1] = true;
        }
        if (now - 1 >= 0 && !visit[now - 1]) {
            q.push(make_pair(now - 1, count + 1));
            visit[now - 1] = true;
        }
        if (now * 2 < SIZE && !visit[now * 2]) {
            q.push(make_pair(now * 2, count + 1));
            visit[now * 2] = true;
        }
    }
}

int main() {

    int from, to;

    cin >> from >> to;

    cout << bfs(from , to) << endl;

    return 0;

}