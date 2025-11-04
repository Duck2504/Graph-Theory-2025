#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<pair<int,int>> treeEdges;

void dfs(int n){ 
    visited[n] = true;
    for (int v:adj[n]){
        if (!visited[v]){
            treeEdges.push_back({n,v});
            dfs(v);
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
        cin >> u  >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end()); //sap xep lai danh sach ke
}

int main(){
    Nhap();
    dfs(1);
    cout << treeEdges.size() << endl;
    for (auto i : treeEdges){
        cout << i.first << " " << i.second<<endl;
    }
    system("pause");
}