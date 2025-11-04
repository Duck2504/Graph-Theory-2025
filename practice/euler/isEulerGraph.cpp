#include <iostream>
#include <queue>
using namespace std;

vector<vector<int>> adj;
vector<int> visited;
int n;

void BFS(int n){
    queue<int> q;
    visited[n] = 1;
    q.push(n);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for (int v : adj[u]){
            if(!visited[v]){
                visited[v] = 1;
                q.push(v);
            }
        }
    }
}

bool isConnect(){
    BFS(1);
    for (int i = 0;i<=n;i++){
        if (!adj.empty() && !visited[i]) return false;
    }
    return true;
}

void isEulerGraph(){
    if (!isConnect()) {
        cout << "khong phai do thi euler!";
    }
    int odd = 0;
    for (int i = 1;i<=n;i++){
        if (adj[i].size()%2==1) odd++; 
    }
    if (odd % 2 ==0) cout << "la do thi euler";
    else if (odd == 0) cout <<"la chu trinh euler";
    else cout << "Khong la do thi euler";
}

void Nhap(){
    cin >> n;
    adj.resize(n+1,{});
    visited.assign(n+1,0);
    for (int i = 1;i<=n;i++){
        while (true){
            int u;
            cin >> u;
            if (u==-1) break;
            adj[i].push_back(u);
        }
    }
}

int main(){
    Nhap();
    isEulerGraph();
    return 0;
}