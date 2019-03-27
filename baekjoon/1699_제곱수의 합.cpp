#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
#define SIZE 100001
int arr[SIZE];

void find(int n) {
    int i = (int)sqrt(n);
    for (; i >= 1; i--) {
        arr[n] = min(arr[n], arr[n - i * i] + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    arr[0] = 0;
    for (int i = 1; i < SIZE; i++) {
        arr[i] = i;
        find(i);
    }
    cout << arr[n] << endl;

}