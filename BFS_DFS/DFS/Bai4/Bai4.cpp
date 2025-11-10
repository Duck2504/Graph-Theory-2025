#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n, start;
vector<vector<int>> adj;
vector<int> visited;

void DFS_non_recursive(int start) {
    stack<int> st;
    st.push(start);
    visited[start] = 1;

    while (!st.empty()) {
        int u = st.top();
        st.pop();
        cout << u << " ";
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = 1;
                st.push(v);
            }
        }
    }
}

int main() {
    cin >> n >> start;
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

    DFS_non_recursive(start);
    return 0;
}
