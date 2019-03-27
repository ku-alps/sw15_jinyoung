#include<iostream>
#include<list>

using namespace std;


#define mod 1000000000


int main() {
    int N;
    long long arr[101][10];
    cin >> N;
    arr[1][0] = 0;
    for (int i = 1; i <= 9; i++) {
        arr[1][i] = 1;
    }
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {
            arr[i][j] = 0;
            if (j == 0) {
                arr[i][j] = arr[i - 1][1];
            }
            else if (j == 9) {
                arr[i][j] = arr[i - 1][8];
            }
            else {
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j + 1];
            }

            arr[i][j] %= mod;
        }
    }
    long long result = 0;
    for (int i = 0; i <= 9; i++) {
        result += arr[N][i];
    }
    cout << (result % mod) << endl;

}