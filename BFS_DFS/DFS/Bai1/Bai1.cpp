#include <iostream>
#include <vector>
using namespace std;

int n, x;
vector<vector<int>> adj;
vector<int> visited;
vector<int> result;

void DFS(int u) {
    visited[u] = 1;
    result.push_back(u);
    for (int v : adj[u]) {
        if (!visited[v]) {
            DFS(v);
        }
    }
}

int main() {
    cin >> n >> x;
    adj.assign(n + 1, {});
    visited.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        while (true) {
            int v;
            cin >> v;
            if (v == -1) break;
            adj[i].push_back(v);
        }
    }
    DFS(x);
    cout << result.size() << "\n";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << " ";
    }
    cout << "\n";

    return 0;
}
