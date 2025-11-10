#include <iostream>
#include <map>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		map<string, int> count;
		int n = s.size();
		for (int i = 0; i + 2 < n; i++) {
			string boBa = s.substr(i, 3); 
			count[boBa]++;
		}
		int kq = 0;
		for (auto& p : count) {
			kq = max(kq, p.second);
		}
		cout << kq << endl;
	}
	return 0;
}