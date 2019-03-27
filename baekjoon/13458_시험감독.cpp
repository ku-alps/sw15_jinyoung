#include <iostream>
using namespace std;

long long N;
long long room[1000001] = { 0, };
long long person[1000001] = { 0, };
long long B, C;
int main() {
    //input
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> room[i];
    }
    cin >> B >> C;
    for (int i = 1; i <= N; i++) {
        int temp = room[i] - B;
        person[i] += 1;  //ÃÑ°¨µ¶°ü
        if (temp <= 0) {
            continue;
        }
        else {
            if (temp % C == 0) {
                person[i] += (temp / C);
            }
            else if (temp % C != 0) {
                person[i] += (temp / C);
                person[i] += 1;
            }
        }
    }
    long long int result = 0;
    for (int i = 1; i <= N; i++) {
            result = result + person[i];
    }
    cout << result << endl;
}