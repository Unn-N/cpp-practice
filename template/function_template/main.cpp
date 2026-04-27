#include<iostream>
#include<string>

using namespace std;

template <class T>
void Print(T* p, int n) {
	for (int i = 0; i < n; i++) {
		if (i > 0) {
			cout << " "; 
		}
		cout << p[i];
	}
	cout << endl;
}

template<class T>
void GtLever(T* p, int n, T lever) {
	T temp[100] = {0};
	int count = 0;

	for (int i = 0; i < n; i++) {
		if (p[i] > lever) {
			temp[count++] = p[i];
			
		}
	}

	for (int i = 0; i < count; i++) {
		p[i] = temp[i];
	}

	Print(p, count);
}

int main() {
	string type;
	int len;
	int n;
	cin >> type >> len >> n;

	if (type == "int") {
		int arr[100], lever;
		for (int i = 0; i < len; i++) {
			cin >> arr[i];
		}
		cin >> lever;
		GtLever(arr, n, lever);
	}

	else if (type == "float") {
		float arr[100], lever;
		for (int i = 0; i < len; i++) {
			cin >> arr[i];
		}
		cin >> lever;
		GtLever(arr, n, lever);
	}

	else if (type == "char") {
		char arr[100], lever;
		for (int i = 0; i < len; i++) {
			cin >> arr[i];
		}
		cin >> lever;
		GtLever(arr, n, lever);
	}

	return 0;
}
