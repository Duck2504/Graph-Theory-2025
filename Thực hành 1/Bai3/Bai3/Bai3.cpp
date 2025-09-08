#include <iostream>
#include <vector>
using namespace std;

vector<int> SNT(int n) {
	vector<bool> isPrime(n + 1, true);
	vector<int> Primes;
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) {
			Primes.push_back(i);
			for (int j = i * i; j <= n; j += i) {
				isPrime[j] = false;
			}
		}
	}
	return Primes;
}

int Count(int n, int p) {
	int dem = 0;
	while (n > 0) {
		n = n / p;
		dem += n;
	}
	return dem;
}

int main() {
	int n;
	vector<int> Primes = SNT(1000);
	while (cin >>n){
		vector<int> result;
		for (int p : Primes) {
			if (p > n) break;
			result.push_back(Count(n, p));
		}
		while (!result.empty() && result.back() == 0) {
			result.pop_back();
		}
		for (int x : result) {
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}