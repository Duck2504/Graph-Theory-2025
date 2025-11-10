#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int nx, ny, nz;
    cin >> nx;
    vector<int> x(nx);
    for (int i = 0; i < nx; i++) cin >> x[i];
    cin >> ny;
    vector<int> y(ny);
    for (int i = 0; i < ny; i++) cin >> y[i];
    cin >> nz;
    vector<int> z(nz);
    for (int i = 0; i < nz; i++) cin >> z[i];
    set<int> sx(x.begin(), x.end());
    set<int> sy(y.begin(), y.end());
    set<int> sz(z.begin(), z.end());
    set<int> temp, result;
    for (int v : sx) {
        if (sy.count(v)) temp.insert(v);
    }
    for (int v : temp) {
        if (sz.count(v)) result.insert(v);
    }
    cout << result.size() << endl;
    for (int v : result) cout << v << " ";
    cout << endl;

    return 0;
}