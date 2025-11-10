#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj;
vector<int> checked;
vector<int> result;
int n, start;

void Nhap(){
    cin >> n >> start;
    adj.assign(n+1, {});
    for (int i = 1; i <= n; i++){
        while (true){
            int v;
            cin >> v;
            if (v == -1) break;
            adj[i].push_back(v);
        }
    }
}

void BFS(){
    result.clear();
    checked.assign(n+1, 0);
    queue<int> q;

    checked[start] = 1;
    q.push(start);

    while (!q.empty()){
        int u = q.front(); q.pop();
        result.push_back(u);
        for (int v : adj[u]){
            if (!checked[v]){
                checked[v] = 1;
                q.push(v);
            }
        }
    }

    cout << result.size() << endl;
    for (int x : result) cout << x << " ";
}

int main(){
    Nhap();
    BFS();
    system("pause");
    return 0;
}
