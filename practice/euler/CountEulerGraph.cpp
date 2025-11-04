#include <iostream>
#include <vector>
using namespace std;

int n,m;
vector<vector<int>> adj;
vector<int> cycle;

void RemoveEdge(int u , int v){
    for (auto it = adj[u].begin();it != adj[u].end();it++){
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

void GoFrom(int x){
    int u = x;
    cycle.clear();
    cycle.push_back(u);

    while (!adj[u].empty()){
        int v = adj[u].back();
        RemoveEdge(u,v);
        u = v ;
        cycle.push_back(u);
        if (u==x) break;
    }
}

int FindVertex(){
    for (int i = 0;i<cycle.size();i++){
        if(!adj[cycle[i]].empty()) return i;
    }
    return -1;
}

void Reverse(vector<int>&cycle,int k1,int k2){
    while(k1<k2) swap(cycle[k1++],cycle[k2--]);
}

void ReverseCycle(vector<int>&a,int k){
    Reverse(a,0,k-1);
    Reverse(a,k,a.size()-1);
    Reverse(a,0,a.size()-1);
}

void FindEulerCycle(){
    GoFrom(1);

    while (true){
        int k =  FindVertex();
        if (k==-1) break;

        ReverseCycle(cycle,k);
        vector<int> subCycle;
        int u = cycle[0];
        subCycle.push_back(u);

        while (!adj[u].empty()){
            int v = adj[u].back();
            RemoveEdge(u,v);
            u = v;
            subCycle.push_back(u);
            if (u == cycle[0]) break;
        }
        subCycle.pop_back();
        cycle.insert(cycle.begin(),subCycle.begin(),subCycle.end());
    }
    for (int v:cycle) cout << v<<" ";
    cout <<endl;
}
int main(){
    cin >> n >> m;
    adj.assign(n+1,{});
    for (int i=0;i<m;i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    FindEulerCycle();
    return 0;
}

