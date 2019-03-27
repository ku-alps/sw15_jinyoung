#include <iostream>
#include <list>
using namespace std;

int arr[9];
int real[7];
int total = 0;

void back_track(int start, int depth) {

    if (depth == 7) {
        for (int i = 0; i < 7; i++) {
            total += real[i];
        }
        if (total == 100) {
            for (int i = 0; i < 7; i++) {
                cout << real[i] << endl;
            }
            return;
        }
        total = 0;
    }
    for (int i = start; i < 9; i++) {
        real[depth] = arr[i];
        back_track(i + 1, depth + 1);
    }
}

int main() {

    list<int> li;
    int temp;
    for (int i = 0; i < 9; i++) {
        cin >> temp;
        li.push_back(temp);
    }
    li.sort();
    list<int>::iterator iter;
    int idx = 0;
    for (iter = li.begin(); iter != li.end(); iter++) {
        arr[idx] = *iter;
        idx += 1;
    }

    back_track(0, 0);
}