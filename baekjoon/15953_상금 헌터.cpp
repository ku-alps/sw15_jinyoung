#include <iostream>
#include <vector>

using namespace std;
#define MONEY 10000
vector<int> vec;

int first_festival[6][2] = {
    {500,1},{300,3},{200,6},{50,10},{30,15},{10,21}
};
int second_festival[5][2] = {
    {512,1},{256,3},{128,7},{64,15},{32,31}
};
int main() {
    int T;
    cin >> T;
    int a, b;

    for (int t = 0; t < T; t++) {
        cin >> a >> b;

        int a_money = 0;
        int b_money = 0;

        if (a <= 21 && a!=0) {
            for (int i = 0; i < 6; i++) {
                if (a <= first_festival[i][1]) {
                    a_money = first_festival[i][0];
                    break;
                }
            }

        }
        if(b <= 31 && b != 0) {
            for (int i = 0; i < 5; i++) {
                if (b <= second_festival[i][1]) {
                    b_money = second_festival[i][0];
                    break;
                }
            }
        }
        int result = a_money + b_money;
        vec.push_back(result);

    }
    for (int i = 0; i < vec.size(); i++) {
        cout << vec.at(i) * MONEY << endl;
    }

}