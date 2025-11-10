#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> visited;
vector<int> euler;
int n;

void Nhap(){
    cin >> n;
    adj.assign(7,{});
    for (int i = 1;i<=n;i++){
        int u ,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void BFS(int start){
    visited.assign(7,0);
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    while (!q.empty()){
        int u = q.front();q.pop();
        for (int v:adj[u]) {
            if (!visited[v]){
                visited[v] = 1;
                q.push(v);
            }
        }
    }
}

bool isConnect(){
    int start = -1;
    for (int i = 1;i<7;i++){
        if(!adj[i].empty()){
            start = i;
        }
    }
    if (start == -1) return true;
    BFS(start);
    for (int i = 1;i<7;i++){
        if (!visited[i] && !adj[i].empty()) return false;
    }
    return true;
}

void RemoveEdge(int u ,int v){
    for (auto it = adj[u].begin();it!=adj[u].end();it++){
        if (*it==v){
            adj[u].erase(it);
            break;
        }
    }
    for (auto it = adj[v].begin();it!=adj[v].end();it++){
        if (*it==u){
            adj[v].erase(it);
            break;
        }
    }
}

void FindPath(int start){
    euler.clear();
    stack<int> q;
    q.push(start);
    while (!q.empty()){
        int u = q.top();
        if (!adj[u].empty()){
            int v = adj[u].back();
            RemoveEdge(u,v);
            q.push(v);
        }
        else{
            euler.push_back(u);
            q.pop();
        }
    }
    cout <<"Duong di co the la: ";
    cout << "1\n";
    for (int i = 0;i<euler.size()-1;i++) cout << euler[i] << " " << euler[i+1]<<endl;
    cout <<endl;
}

int main(){
    Nhap();
    if (!isConnect()) {
        cout << "Khong co cach xep!";
        return 0;
    }
    else{
        int odd = 0;
        int start = 1;
        for (int i = 1;i<7;i++){
            if (adj[i].size()%2==1){
                odd++;
                start = i;
            } 
        }
        if (odd ==0) FindPath(start);
        else cout <<"khong co duong di";
    }
    system("pause");
    return 0;
}