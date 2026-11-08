#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	vector<int>v = { 1,2,3,4,5 };
	auto it = find_if(v.begin(), v.end(), [](int x) {
		return x % 2 == 0;
		});

	if (it != v.end()) {
		cout << *it << endl;
	}
	else {
		cout << "not found" << endl;
	}

	sort(v.begin(), v.end());
	for (auto x : v) {
		cout << x;
	}
	sort(v.begin(), v.end(), [](int a, int b) {
		return a < b;
	});
	for (auto x : v) {
		cout << x;
	}
	return 0;
}