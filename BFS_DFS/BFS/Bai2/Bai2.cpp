#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> Matran;
queue<int> q;
vector<int> parent;
vector<int> checked;
vector<int> path;
int n , x , y;

void Nhap(){
    cin >> n >> x >> y;
    Matran.assign(n+1,{});
    for (int i = 1;i<=n; i++){
        while(true){
            int v;
            cin >>v;
            if (v==-1) break;
            Matran[i].push_back(v);
        }
    }
}

void BFS(){
    parent.assign(n+1,-1);
    checked.assign(n+1,0);
    checked[x] = 1;
    q.push(x);
    while (!q.empty()){
     int u = q.front(); q.pop();
     for (int v: Matran[u]){
        if (!checked[v]){
            checked[v] = 1;
            parent[v] = u;
            q.push(v);
            if (v == y) return;
        }
     }   
    }
}

void findPath(){
    if (!checked[y]){
        cout << 0 <<endl;
        return;
    }
    int cur = y;
    while (cur != -1){
        path.push_back(cur);
        cur = parent[cur];
    }
    reverse(path.begin(),path.end());
    cout << path.size() << "\n";
    for (int i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i < path.size()-1) cout << " ";
    }
    cout << "\n";
}

int main(){
    Nhap();
    BFS();
    findPath();
    system("pause");
    return 0;
}