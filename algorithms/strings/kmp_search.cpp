#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<int> buildNext(const string& p) {
	int m = p.size();
	vector<int> nxt(m);

	nxt[0] = -1;

	int i = 0;
	int j = -1;

	while (i < m - 1) {
		if (j == -1 || p[i] == p[j]) {
			i++;
			j++;
			nxt[i] = j;
		}
		else {
			j = nxt[j];
		}
	}

	return nxt;
}

int kmpSearch(const string& s, const string& p) {
	vector<int> nxt = buildNext(p);

	int n = s.size();
	int m = p.size();

	int i = 0;
	int j = 0;

	while (i < n && j < m) {
		if (j == -1 || s[i] == p[j]) {
			i++;
			j++;
		}
		else {
			j = nxt[j];
		}
	}

	if (j == m) {
		return i - j;
	}

	return -1;
}

int main() {
	string s, p;
	cin >> s >> p;

	int pos = kmpSearch(s, p);

	if (pos == -1) {
		cout << "no";
	}
	else {
		cout << pos;
	}

	return 0;
}