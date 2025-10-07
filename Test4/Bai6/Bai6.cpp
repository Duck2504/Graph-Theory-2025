#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj; 
vector<int> visited;    
vector<int> euler;       
int n, m;             


void Nhap() {
    cin >> n >> m;
    adj.assign(n + 1, {});
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void BFS(int start) {
    visited.assign(n + 1, 0);
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = 1;
                q.push(v);
            }
        }
    }
}

bool isConnect() {
    int start = -1;
    for (int i = 1; i <= n; i++) {
        if (!adj[i].empty()) {
            start = i;
            break;
        }
    }
    if (start == -1) return true;

    BFS(start);
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && !adj[i].empty())
            return false;
    }
    return true;
}

void RemoveEdge(int u, int v) {
    auto it = find(adj[u].begin(), adj[u].end(), v);
    if (it != adj[u].end()) adj[u].erase(it);
    it = find(adj[v].begin(), adj[v].end(), u);
    if (it != adj[v].end()) adj[v].erase(it);
}

void FindEuler(int start) {
    euler.clear();
    stack<int> st;
    st.push(start);

    while (!st.empty()) {
        int u = st.top();
        if (!adj[u].empty()) {
            int v = adj[u].back();
            RemoveEdge(u, v);
            st.push(v);
        } else {
            euler.push_back(u);
            st.pop();
        }
    }
    cout << "Chu trinh Euler la:\n";
    for (int i = euler.size() - 1; i >= 0; i--) {
        cout << euler[i];
        if (i != 0) cout << " ";
    }
    cout << endl;
}

int main() {
    Nhap();

    if (!isConnect()) {
        cout << "Do thi khong lien thong!\n";
        system("pause");
        return 0;
    }

    int odd = 0;
    int start = 1;
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() % 2 == 1) {
            odd++;
            start = i;
        }
    }
    if (odd == 0)
        FindEuler(start);
    else
        cout << "Do thi khong co chu trinh Euler!\n";
    system("pause");
    return 0;
}
