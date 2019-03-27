#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    char second[3];
    int num_first = 0;
    int num_Second = 0;
    int a, b, c, d = 0;

    cin >> num_first;
    for (int i = 0; i < 3; i++) {
        cin >> second[i];
    }
    a = num_first * (second[2] - 48);
    b = num_first * (second[1] - 48);
    c = num_first * (second[0] - 48);

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;

    b = b * 10;
    c = c * 100;
    d = a + b + c;

    cout << d << endl;

}