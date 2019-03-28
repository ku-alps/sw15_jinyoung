#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long int lli;

struct Nation {
    int index;
    lli gold;
    lli silver;
    lli bronze;
    int grade = 0;
    Nation(int i, lli g, lli s, lli b) :index(i), gold(g), silver(s), bronze(b) {};
};

vector<Nation> v;
int N, K;
int i;
lli g, s, b;

bool compare(Nation a, Nation b) {
    if (a.gold != b.gold) {
        return a.gold > b.gold;
    }
    if (a.silver != b.silver) {
        return a.silver > b.silver;
    }
    return a.bronze > b.bronze;
}
bool is_same_grade(Nation a, Nation b) {
    if (a.gold != b.gold || a.silver != b.silver || a.bronze != b.bronze) {
        return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    for (int n = 0; n < N; n++) {
        cin >> i >> g >> s >> b;
        v.push_back(Nation(i, g, s, b));
    }

    sort(v.begin(), v.end(), compare);
    v.at(0).grade = 1;

    for (int i = 1; i < N; i++) {
        v.at(i).grade = v.at(i - 1).grade + 1;
    }

    for (int i = 1; i < N; i++) {
        if (is_same_grade(v.at(i), v.at(i - 1))) {
            v.at(i).grade = v.at(i - 1).grade;
        }
    }
    for (int i = 0; i < N; i++) {
        if (v.at(i).index == K) {
            cout << v.at(i).grade << endl;
        }
    }
}