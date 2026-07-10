#include <bits/stdc++.h>
using namespace std;
#define all(c) c.begin(), c.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> list(n);
        for (int i = 0; i < n; i++) {
            cin >> list[i];
        }

        int l = 0;  // левая граница окна
        int mx = 0;  // максимальная длина
        map<long long, int> lp;  // последняя позиция каждого числа

        for (int r = 0; r < n; r++) {
            // если число уже встречалось в текущем окне
            if (lp.find(list[r]) != lp.end() and lp[list[r]] >= l) {
                l = lp[list[r]] + 1;  // сдвигаем левую границу
            }

            lp[list[r]] = r;  // обновляем последнюю позицию
            mx = max(mx, r - l + 1);  // обновляем максимум
        }

        cout << mx << '\n';
    }

}