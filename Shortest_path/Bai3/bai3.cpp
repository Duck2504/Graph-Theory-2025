#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, m;
vector<vector<int>> a, d, p;

void Nhap() {
    cin >> n >> m;
    a.assign(n + 1, vector<int>(n + 1, INF));
    d.assign(n + 1, vector<int>(n + 1, INF));
    p.assign(n + 1, vector<int>(n + 1, -1));

    for (int i = 1; i <= n; i++) a[i][i] = 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        a[u][v] = w;
        a[v][u] = w;
    }
}

void KhoiTao() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            d[i][j] = a[i][j];
            if (i != j && a[i][j] < INF) p[i][j] = i;
        }
    }
}

void Floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][k] < INF && d[k][j] < INF && d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    p[i][j] = p[k][j];
                }
            }
        }
    }
}

void Xuat() {
    cout << "Ma tran do dai duong di ngan nhat:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (d[i][j] == INF) cout << "0 ";
            else cout << d[i][j] << " ";
        }
        cout << "\n";
    }
}

void DuongDi(int u, int v) {
    if (p[u][v] == -1) {
        cout << "Khong co duong di tu " << u << " den " << v << "\n";
        return;
    }
    vector<int> path;
    path.push_back(v);
    while (v != u) {
        v = p[u][v];
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    cout << "Duong di ngan nhat: ";
    for (int i = 0; i < (int)path.size(); i++) {
        cout << path[i];
        if (i < (int)path.size() - 1) cout << " -> ";
    }
    cout << "\nDo dai = " << d[u][path.back()] << "\n";
}

// === Chương trình chính ===
int main() {
    Nhap();
    KhoiTao();
    Floyd();
    Xuat();
    int u, v;
    cout << "\nNhap 2 dinh u v de xem duong di ngan nhat: ";
    cin >> u >> v;
    DuongDi(u, v);
    return 0;
}
