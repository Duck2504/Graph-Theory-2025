#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, x, y, z;
vector<vector<int>> adj;
vector<int> checked;

void Nhap() {
    cin >> n >> x >> y >> z;
    adj.assign(n+1, {});
    for (int i = 1; i <= n; i++) {
        while (true) {
            int v;
            cin >> v;
            if (v == -1) break;
            adj[i].push_back(v);
        }
    }
}

void BFS(int start, int skipNode, int skipU, int skipV) {
    queue<int> q;
    q.push(start);
    checked[start] = 1;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (v == skipNode || u == skipNode) continue;
            if ((u == skipU && v == skipV) || (u == skipV && v == skipU)) continue;
            if (!checked[v]) {
                checked[v] = 1;
                q.push(v);
            }
        }
    }
}

int countComponents(int skipNode, int skipU, int skipV) {
    checked.assign(n+1, 0);
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!checked[i] && i != skipNode) {
            BFS(i, skipNode, skipU, skipV);
            count++;
        }
    }
    return count;
}

int main() {
    Nhap();
    int base = countComponents(-1, -1, -1);
    int afterRemoveEdge = countComponents(-1, x, y);
    if (afterRemoveEdge > base) cout << "canh cau\n";
    else cout << "khong la canh cau\n";
    int afterRemoveNode = countComponents(z, -1, -1);
    if (afterRemoveNode > base) cout << "dinh khop\n";
    else cout << "khong la dinh khop\n";
    system("pause");
    return 0;
}
