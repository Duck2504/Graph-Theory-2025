#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, m, s, t;
vector<vector<pair<int,int>>> adj;
vector<int> dist, pre;

void Nhap() {
    cin >> n >> m >> s >> t;
    adj.assign(n + 1, {});
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
}

void Dijkstra(int s) {
    dist.assign(n + 1, INF);
    pre.assign(n + 1, -1);
    vector<bool> visited(n + 1, false);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pre[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

vector<int> TruyVetDuongDi(int s, int t) {
    vector<int> path;
    if (dist[t] == INF) return path;
    for (int v = t; v != -1; v = pre[v]) path.push_back(v);
    reverse(path.begin(), path.end());
    return path;
}

void Xuat() {
    if (dist[t] == INF) {
        cout << "Khong co duong di tu " << s << " den " << t << "\n";
        return;
    }
    cout << dist[t] << "\n";
    vector<int> path = TruyVetDuongDi(s, t);
    for (int i = 0; i < (int)path.size(); i++) {
        cout << path[i];
        if (i < (int)path.size() - 1) cout << " ";
    }
    cout << "\n";
}

int main() {
    Nhap();
    Dijkstra(s);
    Xuat();

    return 0;
}
