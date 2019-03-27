#include <iostream>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int map[1001];
    map[0] = 0;
    map[1] = 1;
    map[2] = 3;
    for (int i = 3; i < 1001; i++) {
        map[i] = (map[i - 2] * 2 + map[i-1]) % 10007;
    }

    int n;
    cin >> n;

    cout << map[n] << endl;
}