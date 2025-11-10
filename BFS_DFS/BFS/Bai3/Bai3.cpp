#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<vector<int>> Matran;
vector<int> checked;
queue<int>q;

void Nhap(){
    cin >> n;
    Matran.assign(n+1,{});
    for (int i= 1;i<=n;i++){
        while (true){
        int v;
        cin >>v;
        if (v==-1) break;
        Matran[i].push_back(v);
        }
    }
}

vector<int> BFS(int start){
    vector<int> result;
    checked[start] = 1;
    q.push(start);
    while (!q.empty()){
        int u = q.front(); q.pop();
        result.push_back(u);
        for (int v:Matran[u]){
            if (!checked[v]){
                checked[v] = 1;
                q.push(v);
            }
        }
    }
    return result;
}

int main(){
    Nhap();
    vector<vector<int>> component;
    checked.assign(n+1,0);
    for (int i = 1;i<=n;i++){
        if (!checked[i]){
            vector<int> temp = BFS(i);
            component.push_back(temp);
        }
    }
    cout << component.size()<<endl;
    for (auto v: component){
        for (int i = 0;i<v.size();i++){
            cout << v[i]<<" ";
        }
        cout <<endl;
    }
    system("pause");
}