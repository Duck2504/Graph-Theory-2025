#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int n , m;
vector<int> color;

void Nhap(){
    cin >> n >> m;
    adj.assign(n+1,{});
    color.assign(n+1,0);
    for (int i = 1;i<=m;i++){
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

bool BFS(int start){
    queue<int> q;
    q.push(start);
    color[start] = 1;
    while(!q.empty()){
        int u = q.front();q.pop();
        for (int v:adj[u]){
            if (color[v]==0){
                color[v] = 3 - color[u];
                q.push(v);
            }
            else if(color[v]==color[u]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    Nhap();
    for (int i = 1;i<=n;i++){
        if (color[i]==0){
            if (!BFS(i)){
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }
    for (int i = 1;i<=n;i++) cout << color[i] << " ";
    return 0;
}
