#include <iostream>
using namespace std;

long long dem(long long n) {
	long long res = 0;
	while (n > 0) {
		n /= 5;
		res += n;
		}
	return res;
}

int main() {
	long long n;
	while (cin >> n) {
		cout << dem(n) << endl;
	}
	return 0;
}