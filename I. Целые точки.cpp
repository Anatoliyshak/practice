#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(c) c.begin(), c.end()

// функция для вычисления НОД (наибольший общий делитель)
long long nod(ll a, ll b) {
    while (b > 0) {
        ll с = b;
        b = a % b;
        a = с;
    }
    return a;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        // количество целых точек = НОД(|dx|, |dy|) + 1
        ll num = nod(abs(x2 - x1), abs(y2 - y1)) + 1;

        cout << num << "\n";
    }

}