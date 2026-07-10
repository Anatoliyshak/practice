#include <bits/stdc++.h>
using namespace std;
#define all(c) c.begin(), c.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    vector<long long> d(n);
    for (long long i = 0; i < n; i++) {
        cin >> d[i];
    }
    sort(all(d));  // Сортируем опасные комнаты

    long long q;
    cin >> q;

    while (q--) {
        long long s, f;
        cin >> s >> f;

        int le = min(s, f);  // Левая граница пути
        int ri = max(s, f);  // Правая граница пути

        // Находим количество опасных комнат на отрезке [le, ri]
        int l = lower_bound(all(d), le) - d.begin();
        int r = upper_bound(all(d), ri) - d.begin();

        cout << r - l << '\n';
    }
}