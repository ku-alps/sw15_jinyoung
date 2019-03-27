#include <iostream>
#include <math.h>
using namespace std;


int main()
{
    char first[3];
    char second[3];
    int first_num = 0;
    int second_num = 0;

    for (int i = 0; i < 3; i++) {
        cin >> first[i];
    }
    for (int i = 0; i < 3; i++) {
        cin >> second[i];
    }
    for (int i = 2; i >= 0; i--) {
        first_num += (first[i]-48)*pow(10,i);
        second_num += (second[i] - 48)*pow(10, i);
    }
    if (first_num > second_num) {
        cout << first_num << endl;
    }
    else {
        cout << second_num << endl;
    }
}