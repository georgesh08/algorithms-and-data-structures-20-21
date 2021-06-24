#include <iostream>
#include <vector>
using namespace std;

double garland(vector<double> &a, int n) {
    double l = a[0], r = 0;
    while (l - r > 0.0000001) {
        a[1] = (l + r) / 2;
        bool isUp = true;
        for (int i = 2; i < n; i++) {
            a[i] = 2 * a[i - 1] - a[i - 2] + 2;
            if (a[i] < 0) {
                isUp = false;
                break;
            }
        }
        if (isUp) {
            l = a[1];
        } else {
            r = a[1];
        }
    }
    return a[n - 1];
}

int main() {
    freopen("garland.in", "r", stdin);
    freopen("garland.out", "w", stdout);
    int n;
    cin >> n;
    vector<double> a(n);
    cin >> a[0];
    double k = garland(a, n);
    cout << fixed;
    cout.precision(2);
    cout << k;
    return 0;
}