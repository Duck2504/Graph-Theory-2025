#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, x, y;
vector<vector<int>> adj;
vector<int> color;

bool BFS(int start) {
    queue<int> q;
    q.push(start);
    color[start] = 1;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (color[v] == 0) {
                color[v] = 3 - color[u];
                q.push(v);
            } else if (color[v] == color[u]) {
                return false; 
            }
        }
    }
    return true;
}

int main() {
    cin >> n >> x >> y;
    adj.assign(n + 1, {});
    color.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        while (true) {
            int v;
            cin >> v;
            if (v == -1) break;
            adj[i].push_back(v);
        }
    }

    bool isBipartite = true;
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            if (!BFS(i)) {
                isBipartite = false;
                break;
            }
        }
    }

    if (isBipartite) cout << "Do thi phan doi\n";
    else cout << "Do thi khong phan doi\n";

    return 0;
}
