#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> Matran;
vector<vector<int>> adj;
vector<int> visited;
vector<int> euler;
int n;

void BFS(int start){
    visited.assign(n+1, 0);
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for (int v : adj[u]){
            if (!visited[v]){
                visited[v] = 1;
                q.push(v);
            }    
        }
    }
}

bool isConnect(){
    int start = -1;
    for (int i = 1; i <= n; i++)
        if (!adj[i].empty()){ start = i; break; }
    if (start == -1) return true;
    BFS(start);
    for (int i = 1; i <= n; i++){
        if (!adj[i].empty() && !visited[i]) return false;
    }
    return true;
}

void RemoveEdge(int u, int v){
    for (auto it = adj[u].begin(); it != adj[u].end(); it++){
        if (*it == v){
            adj[u].erase(it);
            break;
        }
    }
    for (auto it = adj[v].begin(); it != adj[v].end(); it++){
        if (*it == u){
            adj[v].erase(it);
            break;
        }
    }
}

void findPath(int start){
    euler.clear();
    stack<int> st;
    st.push(start);

    while (!st.empty()){
        int u = st.top();
        if (!adj[u].empty()){
            int v = adj[u].back();
            RemoveEdge(u, v);
            st.push(v);
        } else {
            euler.push_back(u);
            st.pop();
        }
    }
    reverse(euler.begin(), euler.end());
}

void Nhap(){
    cin >> n;
    Matran.assign(n+1, vector<int>(n+1, 0));
    adj.assign(n+1, {});
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> Matran[i][j];
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = i+1; j <= n; j++){
            if (Matran[i][j] == 1){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
}

int main(){
    Nhap();

    if (!isConnect()) {
        cout << 0;
        return 0;
    }

    int oddCount = 0;
    int start = 1;
    for (int i = 1; i <= n; i++){
        if (adj[i].size() % 2 == 1){
            oddCount++;
            start = i;
        }
    }

    if (oddCount == 0 || oddCount == 2){
        cout << 1 << endl;
        findPath(start);
        for (int x : euler) cout << x << " ";
    } else {
        cout << 0;
    }
    system("pause");
    return 0;
}
