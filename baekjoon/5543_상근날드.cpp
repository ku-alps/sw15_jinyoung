#include <iostream>

using namespace std;

int burger[3];
int drink[2];

int main() {
    for (int i = 0; i < 3; i++) {
        cin >> burger[i];
    }
    for (int i = 0; i < 2; i++) {
        cin >> drink[i];
    }
    int set = 5000;
    int temp = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
             temp = burger[i] + drink[j];
            if (set > temp) {
                set = temp;
            }
        }
    }
    cout << set-50 << endl;
}