#include <iostream>

using namespace std;
#define SIZE 100001

int main() {
    int n;
    int arr[SIZE];
    long long int max_count = -1000;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long long int result = 0;
    for (int i = 0; i < n; i++) {
            result += arr[i];

            if (max_count < result) {
                max_count = result;
            }
            if (result < 0) {
                result = 0;
            }
    }
    cout << max_count << endl;
}