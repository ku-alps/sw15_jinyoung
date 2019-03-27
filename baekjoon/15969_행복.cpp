#include <iostream>
#include <list>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int student;
    list<int> li;
    cin >> student;

    int temp;
    for (int i = 0; i < student; i++) {
        cin >> temp;

        li.push_back(temp);
    }
    li.sort();

    list<int>::iterator iter;

    iter = li.begin();
    int min = *iter;
    int max;
    for (; iter != li.end(); iter++) {
        max = *iter;
    }
    cout << max - min << endl;

}