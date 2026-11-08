#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

struct three {
	int x;
	int y;
	int val;
	three(int x, int y, int val) : x(x), y(y), val(val) {}
};

bool cmp(const three& a, const three& b) {
	if (a.x != b.x) {
		return a.x < b.x;
	}
	return a.y < b.y;
}

int main() {
	vector<three>threes1;
	vector<three>threes2;

	int row1, column1, count1;
	cin >> row1 >> column1 >> count1;
	for (int i = 0; i < count1; i++) {
		int x, y, val;
		cin >> x >> y >> val;
		three t = three(x, y, val);
		threes1.push_back(t);
	}

	int row2, column2, count2;
	cin >> row2 >> column2 >> count2;
	for (int i = 0; i < count2; i++) {
		int x, y, val;
		cin >> x >> y >> val;
		three t = three(x, y, val);
		threes2.push_back(t);
	}

	if (column1 != row2) {
		cout << "ERROR";
		return 0;
	}

	vector<three>results;

	for (auto t : threes1) {
		for (auto u : threes2) {
			if (u.x == t.y) {
				int targetx = t.x;
				int targety = u.y;
				int contribution = t.val * u.val;

				bool found = false;

				for (auto& r : results) {
					if (r.x == targetx && r.y == targety) {
						found = true;
					}
				}
				if (found == true) {
					for (auto& r : results) {
						if (r.x == targetx && r.y == targety) {
							r.val += contribution;
						}
					}
				}
				else {
					three newr = three(targetx, targety, contribution);
					results.push_back(newr);
				}

			}
		}
	}

	if (results.empty()) {
		cout << "The answer is a Zero Matrix";
		return 0;
	}
	else {
		sort(results.begin(), results.end(), cmp);
		for (auto r : results) {
			cout << r.x << " " << r.y << " " << r.val;
			cout << endl;
		}
	}
	return 0;
}