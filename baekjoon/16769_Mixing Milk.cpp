#include <iostream>
using namespace std;

int _max[3];
int milk[3];

int main() {
    int a, b;
    for (int i = 0; i < 3; i++) {
        cin >> a >> b;
        _max[i] = a;
        milk[i] = b;
    }

    int temp;
    for (int i = 0; i < 100; i++) {
        temp = i % 3;

        milk[(temp + 1) % 3] += milk[temp];
        milk[temp] = 0;
        if (_max[(temp + 1) % 3] < milk[(temp + 1) % 3]) {
            int rest = milk[(temp + 1) % 3] - _max[(temp + 1) % 3];
            milk[(temp + 1) % 3] -= rest;
            milk[temp] += rest;
        }
    }

    for (int i = 0; i < 3; i++) {
        cout << milk[i] << endl;
    }
}