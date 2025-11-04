#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
    int w;
};

int findSet(vector<int>& parent, int u) {
    if (u == parent[u]) return u;
    return parent[u] = findSet(parent, parent[u]);
}

bool unionSet(vector<int>& parent, vector<int>& rank, int u, int v) {
    int pu = findSet(parent, u);
    int pv = findSet(parent, v);
    if (pu == pv) return false;
    if (rank[pu] < rank[pv]) parent[pu] = pv;
    else if (rank[pu] > rank[pv]) parent[pv] = pu;
    else {
        parent[pv] = pu;
        rank[pu]++;
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);

    for (int i = 0; i < m; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });

    vector<int> parent(n + 1), rank(n + 1, 0);
    iota(parent.begin(), parent.end(), 0);

    vector<Edge> mst;
    int total_weight = 0;

    for (auto &e : edges) {
        if (unionSet(parent, rank, e.u, e.v)) {
            mst.push_back(e);
            total_weight += e.w;
        }
        if ((int)mst.size() == n - 1) break;
    }

    cout << mst.size() << " " << total_weight << "\n";
    for (auto &e : mst)
        cout << e.u << " " << e.v << " " << e.w << "\n";

    return 0;
}
