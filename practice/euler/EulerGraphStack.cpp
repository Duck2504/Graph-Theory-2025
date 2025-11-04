#include "bits/stdc++.h"
using namespace std;

vector<vector<int>> adj;
vector<int> euler;
int n,m;

void RemoveEdge(int u,int v){
    for (auto it = adj[u].begin();it!=adj[u].end();it++){
        if (*it == v){
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

void Findpath(int start){
    stack<int> st;
    st.push(start);
    while (!st.empty()){
        int u = st.top();
        if (!adj[u].empty()){
            int v = adj[u].back();
            RemoveEdge(u,v);
            st.push(v);
        }
        else {
            euler.push_back(u);
            st.pop();
        }
    }
}

int main (){
    cin >> n >> m;
    adj.assign(n+1,{});
    for (int i = 1;i<=m;i++){
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Findpath(1);
    cout << "chu trinh euler: ";
    for (auto x : euler) cout << x <<" ";
    cout << endl;
    system("pause");
    return 0;
}