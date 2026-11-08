#include<iostream>
#include<list>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		int t;
		cin >> t;
		list<int>ls;
		while (t--) {
			int id;
			cin >> id;
			auto it = find(ls.begin(), ls.end(), id);
			if (it != ls.end()) {
				ls.erase(it);
			}
			ls.push_front(id);
		}
		for(int id : ls) {
			cout << id << " ";
		}
		cout << endl;
	}
	return 0;
}