#include <iostream>
#include <vector>
using namespace std;

long long int N;
vector<long long int> vec;

int main() {
    cin >> N;

    int max = 1;
    int count = 1;
    while (1) {
        if (max < N) {
            max += 6 * count;
            count += 1;
        }
        else {
            break;
        }
    }
    cout << count << endl;
}