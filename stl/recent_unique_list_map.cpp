#include<iostream>
#include<list>
#include<map>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		int t;
		cin >> t;
		list<int> l;
		map<int,bool>mp;
		while (t--) {
			int x;
			cin >> x;
			if(mp[x]==true){
				auto it = find(l.begin(), l.end(), x);
				l.erase(it);
			}
			mp[x] = true;
			
			l.push_front(x);

		}
		for (auto val : l) {
			cout << val << " ";
		}
		cout << endl;
	}
	return 0;
}