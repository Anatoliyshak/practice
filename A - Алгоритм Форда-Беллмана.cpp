#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// структура для хранения ребра графа
struct Rebro {
    int u, v, w;
};

int main() {
    int n, m, s;
    cin >> n >> m >> s;

    vector<Rebro> reb(m);
    for (int i = 0; i < m; i++) {
        cin >> reb[i].u >> reb[i].v >> reb[i].w;
    }

    ll INF = 1e18;  // большое число для обозначения недостижимости
    vector<ll> d(n + 1, INF);
    d[s] = 0;

    // основная часть алгоритма Форда-Беллмана
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (d[reb[j].u] < INF) {
                if (d[reb[j].v] > d[reb[j].u] + reb[j].w) {
                    d[reb[j].v] = d[reb[j].u] + reb[j].w;
                }
            }
        }
    }

    // поиск вершин, затронутых отрицательным циклом
    vector<bool> bad(n + 1, false);
    for (int j = 0; j < m; j++) {
        if (d[reb[j].u] < INF && d[reb[j].v] > d[reb[j].u] + reb[j].w) {
            bad[reb[j].v] = true;
        }
    }

    // распространение метки "bad" на все достижимые вершины
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (bad[reb[j].u]) {
                bad[reb[j].v] = true;
            }
        }
    }

    // проверка на наличие отрицательного цикла
    for (int i = 1; i <= n; i++) {
        if (bad[i]) {
            cout << "Negative cycle" << endl;
            return 0;
        }
    }

    // вывод расстояний
    for (int i = 1; i <= n; i++) {
        if (d[i] == INF) {
            cout << "inf ";
        } else {
            cout << d[i] << " ";
        }
    }
    cout << endl;

    return 0;
}