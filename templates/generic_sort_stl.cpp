#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

template<typename T>
class Sorter {
private:
	vector<T>arr;
public:
	
	void sortandprint() {
		sort(arr.begin(), arr.end());
		for (int i = 0; i < arr.size(); i++) {
			cout << arr[i] << " ";
			
		}
		cout << endl;
	}

	void read(int n) {
		T p;
		for (int i = 0; i < n; i++) {
			cin >> p;
			arr.push_back(p);
		}
	}
};

template<typename T>
void solve() {
	int n;
	cin >> n;
	Sorter<T>arr;
	arr.read(n);
	arr.sortandprint();

}

int main() {
	solve<int>();
	solve<char>();
	solve<string>();
	
	return 0;
}