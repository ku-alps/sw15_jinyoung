#include <iostream>
#include <vector>
using namespace std;

long long int D, K;

int DFS(int first, int second) {
    vector<int> vec;
    for (int i = 0; i < D; i++) {
        if (vec.size() == 0) {
            vec.push_back(first);
            continue;
        }
        else if (vec.size() == 1) {
            vec.push_back(second);
            continue;
        }
        else {
            int temp = vec.at(i - 2) + vec.at(i - 1);
            vec.push_back(temp);
        }
    }
    return vec.at(vec.size() - 1);
}
int main() {
    cin >> D >> K;

    bool result = false;
    for (int i = 1; i < 100000; i++) {
        for (int j = i; j < 100000; j++) {
            if (K == DFS(i, j) && result == false) {
                cout << i << endl;
                cout << j << endl;
                result = true;
            }
        }
        if (result == true) {
            break;
        }
    }
}