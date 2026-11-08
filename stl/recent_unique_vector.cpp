#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	while (N--) {
		int n;
		cin >> n;
		vector<int>arr;
		while (n--) {
			int p;
			cin >> p;
			auto it = find(arr.begin(), arr.end(), p);
			if (it == arr.end())arr.push_back(p);
			else {
				arr.erase(it);
				arr.push_back(p);
			}
		}
		for (auto it = arr.rbegin(); it != arr.rend(); ++it) {
			cout << *it << " ";
			
		}
		cout << endl;
	}
	return 0;

}