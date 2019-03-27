#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int day;
    cin >> day;

    int temp;
    int count = 0;

    for (int i = 0; i < 5; i++) {
        cin >> temp;
        if (temp == day) {
            count++;
        }
    }
    cout << count << endl;
}