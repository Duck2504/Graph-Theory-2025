#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,x,y,z;
vector<vector<int>> adj;
vector<int> checked;

void Nhap(){
    cin >> n >> x >> y >> z;
    adj.assign(n+1,{});
    for (int i = 1;i<=n;i++){
        while(true){
            int v;
            cin >>v;
            if(v==-1) break;
            adj[i].push_back(v);
        }
    }
}

void BFS(int start, int skipNote , int skipV,int skipU){
    queue<int> q;
    checked[start] = 1;
    q.push(start);
    while (!q.empty()){
        int u = q.front();q.pop();
        for (int v:adj[u]){
            if(v == skipNote || u == skipNote) continue;
            if((v == skipU&&u == skipV)||(v==skipV&&u==skipV)) continue;
            if (!checked[v]){
                checked[v] =1;
                q.push(v);
            }
        }
    }
}

int Count(int skipNote, int skipV, int skipU){
    checked.assign(n+1,0);
    int count = 0;
    for (int i = 1;i<=n;i++){
       if(!checked[i] && i!=skipNote){
        BFS(i,skipNote,skipV,skipU);
        count++;
       }
    }
    return count;
}