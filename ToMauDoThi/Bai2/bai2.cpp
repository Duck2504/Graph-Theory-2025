#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> color;

void Nhap()
{
    cin >> n >> m;
    adj.assign(n + 1, {});
    color.assign(n + 1, 0);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void Welshpowell()
{
    vector<pair<int, int>> deg; 
    for (int i = 1; i <= n; i++)
    {
        deg.push_back({(int)adj[i].size(), i});
    }

    sort(deg.begin(), deg.end(), [](auto &a, auto &b)
         {
             if (a.first != b.first)
                 return a.first > b.first;
             return a.second < b.second; 
         });

    int maxColor = 0;
    for (auto [degree, u] : deg)
    {
        set<int> used;
        for (int v : adj[u])
        {
            if (color[v])
                used.insert(color[v]);
        }
        int c = 1;
        while (used.count(c))
            c++;
        color[u] = c;
        maxColor = max(maxColor, c);
    }

    cout << maxColor << "\n";
    vector<vector<int>> groups(maxColor + 1);
    for (int i = 1; i <= n; i++)
    {
        groups[color[i]].push_back(i);
    }

    for (int c = 1; c <= maxColor; c++)
    {
        for (int x : groups[c])
            cout << x << " ";
        cout << "\n";
    }
}

int main()
{
    Nhap();
    Welshpowell();
    system("pause");
}
