#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int>a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	long long maxVal = *max_element(a.begin(), a.end());

	long long exp = 1;

	

	while (maxVal / exp > 0) {
		vector<vector<int>>buckets(10);
		for (auto x : a) {
			int digit = (x / exp) % 10;
			buckets[digit].push_back(x);
		}

		int index = 0;
		for (int i = 0; i < 10; i++) {
			for (auto x : buckets[i]) {
				a[index++] = x;
			}
		}
		for (int i = 0; i < n; i++) {
			if (i > 0)cout << " ";
			cout << a[i];
		}
		cout << endl;
		exp *= 10;

	}
	return 0;
}