#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

vector<vector<pair<int,int>>> adj;
vector<bool> visited;
vector<int> pre,disk;
int n,m,s,t;

void dijkstra(int s){
    visited.assign(n+1,false);
    pre.assign(n+1,-1);
    disk.assign(n+1,INF);
    disk[s] = 0;
    for (int k = 1;k<=n;k++){
        int u = -1;
        int mindisk = INF;
        for (int i = 1;i<=n;i++){
            if (!visited[i]&&disk[i]<mindisk){
                mindisk = disk[i];
                u=i;
            }
        }

        if (u==-1) break;
        visited[u] = true;
        
        for (auto [v,w]:adj[u]){
            if (!visited[v]&&disk[v]>disk[u]+w){
                disk[v]=disk[u]+w;
                pre[v] = u;
            }
        }
    }
}

void Nhap(){
    cin >> n >> m >> s >> t;
    adj.assign(n+1,{});
    for (int i = 1;i<=m;i++){
        int u , v ,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        //adj[v].push_back({u,w});
    }   
}

int main(){
    Nhap();
    dijkstra(s);
    vector<int> path;
    for (int i = t ; i!=-1;i=pre[i]) path.push_back(i);
    reverse(path.begin(),path.end());
    cout << path.size() << " " << disk[t] << endl;
    for (int x:path) cout << x << " " ;
    cout <<endl;
    system("pause");
    return 0;
}
