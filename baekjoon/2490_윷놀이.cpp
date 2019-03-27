#include <iostream>
using namespace std;

int map[3][4];
int main() {
    int zero_num;
    for (int i = 0; i < 3; i++) {
        zero_num = 0;
        for (int j = 0; j < 4; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0) {
                zero_num += 1;
            }
        }
        if (zero_num == 1) {
            cout << "A" << endl;
        }
        else if (zero_num == 2) {
            cout << "B" << endl;
        }
        else if (zero_num == 3) {
            cout << "C" << endl;
        }
        else if (zero_num == 4) {
            cout << "D" << endl;
        }
        else {
            cout << "E" << endl;
        }
    }
}