#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, x, y;
vector<vector<int>> adj;
vector<int> parent;
vector<int> visited;

void BFS(int start) {
    queue<int> q;
    visited[start] = 1;
    q.push(start);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = 1;
                parent[v] = u;
                q.push(v);
                if (v == y) return;
            }
        }
    }
}

int main() {
    cin >> n >> x >> y;
    adj.assign(n + 1, {});
    parent.assign(n + 1, -1);
    visited.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        while (true) {
            int v;
            cin >> v;
            if (v == -1) break;
            adj[i].push_back(v);
        }
    }
    BFS(x);
    if (!visited[y]) {
        cout << 0 << "\n";
    } else {
        vector<int> path;
        for (int cur = y; cur != -1; cur = parent[cur]) {
            path.push_back(cur);
        }
        reverse(path.begin(), path.end());
        cout << path.size() << "\n";
        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}
