#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
	string str;
	cin >> str;
	string dir;
	vector<string>path;

	for (char c : str) {
		if (c == '/') {
			if (!dir.empty()) {
				path.push_back(dir);
				dir.clear();
			}
		}
		else {
			dir += c;
		}
	}
	if (!dir.empty()) {
		path.push_back(dir);
	}

	vector<string>realPath(0);
	for (auto x : path) {
		if ((x == "..") && (!realPath.empty())) {
			realPath.erase(realPath.end() - 1);
			continue;
		}
		if (x == "..") {
			continue;
		}
		if (x == ".") {
			continue;
		}
		else {
			realPath.push_back(x);
		}
	}

	if (realPath.empty()) {
		cout << "/";
		return 0;
	}

	for (auto x : realPath) {
		cout << "/" << x;
	}

	return 0;
}