#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Fraction {
    int x, y;
};

bool compare(Fraction a, Fraction b) {
    return a.x > b.x || (a.x == b.x && a.y > b.y);
}

int main() {
    int k;
    while (cin >> k) {
        vector<Fraction> fractions;
        for (int y = k + 1; y <= 2 * k; y++) {
            if ((k * y) % (y - k) == 0) {
                int x = (k * y) / (y - k);
                Fraction f;
                f.x = x;
                f.y = y;
                fractions.push_back(f);
            }
        }
        sort(fractions.begin(), fractions.end(), compare);
        cout << fractions.size() << endl;
        for (auto fraction : fractions) {
            cout << "1/" << k << " = 1/" << fraction.x << " + 1/" << fraction.y << endl;
        }
    }
    return 0;
}
