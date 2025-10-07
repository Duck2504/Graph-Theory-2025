#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> a;
vector<int> x;
vector<int> visited;
int n;
bool found = false;

void Nhap() {
    cin >> n;
    a.assign(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
}

void Try(int k) {
    if (found) return;

    for (int v = 2; v <= n; v++) {
        if (!visited[v] && a[x[k - 1]][v] == 1) {
            x[k] = v;
            visited[v] = 1;
            if (k == n) {
                if (a[x[n]][x[1]] == 1) {
                    found = true;
                    cout << 1 << "\n";
                    for (int i = 1; i <= n; i++) cout << x[i] << " ";
                    cout << x[1] << "\n";
                    return;
                }
            } else {
                Try(k + 1);
            }

            visited[v] = 0;
        }
    }
}

int main() {
    Nhap();
    x.assign(n + 1, 0);
    visited.assign(n + 1, 0);
    x[1] = 1;
    visited[1] = 1;
    Try(2);
    if (!found) cout << 0;
    system("pause");
    return 0;
}
