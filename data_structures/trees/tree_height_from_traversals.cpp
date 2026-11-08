#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int dfs(const string& pre, const string& in, int preStart, int inStart, int n) {
	if (n == 0)return 0;
	if (n == 1)return 1;
	char root = pre[preStart];
	int k = in.find(root, inStart);

	int leftSize = k - inStart;
	int rightSize = n - 1 - leftSize;

	int leftPreStart = preStart + 1;
	int leftInStart = inStart;

	int rightPreStart = preStart + 1 + leftSize;
	int rightInStart = k + 1;

	int leftH = dfs(pre, in, leftPreStart, leftInStart, leftSize);
	int rightH = dfs(pre, in, rightPreStart, rightInStart, rightSize);

	return max(leftH, rightH) + 1;
}

int getHeight(const string& pre, const string& in) {
	return dfs(pre, in, 0, 0, pre.size());
}

int main() {
	int n;
	string pre, in;
	cin >> n >> pre >> in;
	int H = getHeight(pre, in);
	cout << H;
	return 0;
}