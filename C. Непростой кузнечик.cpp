#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c = 1e9+7;  // модуль для ответа
    int l, r;
    cin >> l >> r;

    // dang[i] - количество способов добраться до точки i
    vector<long long> dang(r+1, 0);
    dang[1] = 1;  // начальная позиция кузнечика

    // для каждой точки i обновляем все кратные ей точки
    for (int i = 1; i <= r; ++i) {
        if (dang[i] == 0) {
            continue;  // если до i нельзя добраться, пропускаем
        }

        // из точки i можно прыгнуть в 2i, 3i, 4i и т.д.
        for (int m = 2*i; m <= r; m += i) {
            dang[m] = (dang[m] + dang[i]) % c;
        }
    }

    // суммируем количество способов для всех точек [l, r]
    long long x = 0;
    for (int i = l; i <= r; i++) {
        x = (x + dang[i]) % c;
    }

    cout << x << "\n";
}