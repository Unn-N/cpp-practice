#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n;
	cin >> n;

	vector<int> nxt(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> nxt[i];
	}

	int h;
	cin >> h;

	int cur = h;
	for (int i = 0; i < n; i++) {
		cout << cur;
		if (i < n - 1)cout << " ";
		cur = nxt[cur];
	}
	cout << endl;

	return 0;
}