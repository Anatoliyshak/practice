#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(c) c.begin(), c.end()

vector<vector<int>> g;    // список смежности графа
vector<bool> vis;         // массив посещённых вершин
int n, m;

// поиск в глубину: отмечает все вершины, достижимые из v
void dfs(int v) {
    vis[v] = true;

    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];

        if (!vis[to]) {
            dfs(to);
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    g.resize(n + 1);
    vis.resize(n + 1, false);

    // чтение графа и построение списка смежности
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);  // граф неориентированный
    }

    int comps = 0;

    // подсчёт компонент связности
    for (int v = 1; v <= n; v++) {
        if (!vis[v]) {
            comps++;      // найдена новая компонента
            dfs(v);       // отмечаем все её вершины
        }
    }

    cout << comps << "\n";
}