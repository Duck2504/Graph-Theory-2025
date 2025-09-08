#include <map>
#include <iostream>
using namespace std;

int main() {
	map<int, int> a;
	a.insert({ 0,2 });
	a.insert({ 1,3 });
	a.insert({ 4,3 });
	a.insert({ 5,6 });
	a.insert({ 7,4 });
	for (auto x : a) {
		cout << x.second;
	}
	return 0;


}