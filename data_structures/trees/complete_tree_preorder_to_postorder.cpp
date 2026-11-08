#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

int getLeftSize(int n) {
	if (n <= 1)return 0;
	int h = 0;
	while ((1 << (h + 1)) <= n) {
		h++;
	}
	int lastLevel = n - ((1 << h) - 1);
	int leftSize = (n - lastLevel - 1) / 2 + min(lastLevel, (1 << (h - 1)));
	return leftSize;
}

void dfs(const string& pre, int start, int n, string& result) {
	if (n == 0) return;
	if (n == 1) {
		result += pre[start];
		return;
	}
	int leftSize = getLeftSize(n);
	int rightSize = n - 1 - leftSize;

	dfs(pre, start + 1, leftSize, result);

	dfs(pre, start + 1 + leftSize, rightSize, result);
	result += pre[start];
}

int main() {
	string str;
	cin >> str;
	int len = str.length();

	string res = "";

	dfs(str, 0, len, res);
	cout << res;

	return 0;

	
}