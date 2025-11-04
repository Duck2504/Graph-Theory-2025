#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int n,m,s,t;
vector<vector<pair<int,int>>> adj;
vector<int> dist , pre;
vector<bool> label;

void Dijkstra(int s){
    dist.assign(n+1,INF);
    pre.assign(n+1,-1);
    label.assign(n+1,false);
    dist[s] = 0;

    for (int k = 1;k<=n;k++){
        int u = -1;
        int minDist=INF;
        for (int i = 1;i<=n;i++){
            if (!label[i]&& dist[i]<minDist){
                minDist=dist[i];
                u = i;
            }
        }

        if (u == -1) break;
        label[u] = true;

        for (auto[v,w]:adj[u]){
            if (!label[v] && dist[v] > dist[u] +w){
                dist[v] = dist[u] + w;
                pre[v] = u;
            }
        }
    }
}

int main() {
    cin >> n >> m >> s >> t;
    adj.assign(n + 1, {});

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    Dijkstra(s);
    vector<int> path;
    for (int v = t; v != -1; v = pre[v]) path.push_back(v);
    reverse(path.begin(), path.end());

    cout << path.size() << " " << dist[t] << "\n";
    for (int v : path) cout << v << " ";
    cout << "\n";

    return 0;
}