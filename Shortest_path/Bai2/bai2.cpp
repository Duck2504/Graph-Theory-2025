#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int n, m, s, t, x;
vector<vector<pair<int,int>>> adj;

vector<int> Dijkstra(int start, vector<int> &dist, vector<int> &pre) {
    dist.assign(n + 1, INF);
    pre.assign(n + 1, -1);
    vector<bool> label(n + 1, false);
    dist[start] = 0;

    for (int k = 1; k <= n; k++) {
        int u = -1, minDist = INF;
        for (int i = 1; i <= n; i++) {
            if (!label[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }
        if (u == -1) break;
        label[u] = true;

        for (auto [v, w] : adj[u]) {
            if (!label[v] && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pre[v] = u;
            }
        }
    }
    return dist;
}

vector<int> getPath(int start, int end, const vector<int> &pre) {
    vector<int> path;
    for (int v = end; v != -1; v = pre[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    cin >> n >> m >> s >> t >> x;
    adj.assign(n + 1, {});

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<int> dist1, pre1, dist2, pre2;
    Dijkstra(s, dist1, pre1);
    Dijkstra(x, dist2, pre2);

    int total = dist1[x] + dist2[t];

    vector<int> path1 = getPath(s, x, pre1);
    vector<int> path2 = getPath(x, t, pre2);
    path2.erase(path2.begin());

    vector<int> path = path1;
    path.insert(path.end(), path2.begin(), path2.end());

    cout << path.size() << " " << total << "\n";
    for (int v : path) cout << v << " ";
    cout << "\n";

    return 0;
}
