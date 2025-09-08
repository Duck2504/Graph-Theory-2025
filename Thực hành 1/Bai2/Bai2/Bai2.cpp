#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>a(n);
	vector<bool>check(n+1, false);
	for (int i=0; i < n; i++) {
		cin >> a[i];
	}
	bool yes = true;
	for (int i = 0; i < n; i++) {
		int temp = a[i];
		if (temp < 1 || temp >n) {
			yes = false;
			break;
		}
		if (check[temp]) {
			yes = false;
			break;
		}
		check[temp] = true;
	}
	if (yes) cout << "YES";
	else cout << "NO";
	return 0;
}