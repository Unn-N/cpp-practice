#include<iostream>
#include<string>

using namespace std;

template<typename T>
T compare(T a, T b) {
	if (a > b)return b;
	else return a;
}

int main() {
	int a1, b1;
	string a2, b2;
	cin >> a1 >> b1 >> a2 >> b2;
	cout << compare(a1, b1) << endl;
	cout << compare(a2, b2);
	return 0;
}