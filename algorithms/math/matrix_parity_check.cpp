#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

bool isduichen(const vector<vector<int>>& matrix, int n, vector<int>& oddRows, vector<int>& oddCols) {
	bool isduichen = true;

	for (int i = 0; i < n; i++) {
		int sum = accumulate(matrix[i].begin(), matrix[i].end(), 0);
		if (sum % 2 == 0)continue;
		else {
			oddRows.push_back(i);
			isduichen = false;
		}
	}

	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			sum += matrix[j][i];
		}
		if (sum % 2 == 0)continue;
		else {
			oddCols.push_back(i);
			isduichen = false;
		}
	}

	return isduichen;
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>>matrix(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}

	vector<int>oddRows;
	vector<int>oddCols;

	bool is = isduichen(matrix, n, oddRows, oddCols);
	if (is) {
		cout << "OK";
		return 0;
	}
	else {
		if (oddCols.size() * oddRows.size() == 1) {
			cout << "Change bit (" << oddRows[0] + 1 << "," << oddCols[0] + 1 << ")";
			return 0;
		}
		else cout << "Corrupt";
	}
	return 0;
}