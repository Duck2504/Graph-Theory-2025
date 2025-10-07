#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> a;
vector<int> euler;
int n;

void Nhap() {
    cin >> n;
    a.assign(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
}

bool isEuler() {
    for (int i = 1; i <= n; i++) {
        int deg = 0;
        for (int j = 1; j <= n; j++) {
            deg += a[i][j];
        }
        if (deg % 2 != 0) return false;
    }
    return true;
}
void EulerKhongDeQuy(int start) {
    stack<int> st;
    vector<vector<int>> temp = a;
    euler.clear();
    st.push(start);
    while (!st.empty()) {
        int u = st.top();
        bool hasEdge = false;

        for (int v = 1; v <= n; v++) {
            if (temp[u][v] == 1) {
                st.push(v);
                temp[u][v] = temp[v][u] = 0;
                hasEdge = true;
                break;
            }
        }
        if (!hasEdge) {
            euler.push_back(u);
            st.pop();
        }
    }
}
int main() {
    Nhap();
    if (!isEuler()) {
        cout << 0;
        return 0;
    }
    EulerKhongDeQuy(1);
    cout << 1 << "\n";
    reverse(euler.begin(), euler.end());
    for (int x : euler) cout << x << " ";
    return 0;
}
