#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<pair<int,int>> treeEdges;

void SpanningTree_BFS(int n){
    queue<int> q;
    visited[n] = true;
    q.push(n);
    while (!q.empty()){
        int u = q.front();q.pop();
        for (int v:adj[u]){
            if (!visited[v]){
                visited[v] = true;
                q.push(v);
                treeEdges.push_back({u,v});
            }
        }
    }
}

void Nhap(){
    int n,m;
    cin >> n >> m;
    adj.assign(n+1,{});
    visited.assign(n+1,false);
    treeEdges.clear();
    for (int i = 1;i<=m;i++){
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());
}

int main(){
    Nhap();
    SpanningTree_BFS(1);
    cout << treeEdges.size() <<endl;
    for (auto i:treeEdges){
        cout << i.first << " "<<i.second<<endl;
    }
    system("pause");
}