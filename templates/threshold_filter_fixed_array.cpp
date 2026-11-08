#include<iostream>
#include<string>
using namespace std;

template<typename T>
void Print(T* p, int n) {
	for (int i = 0; i < n; i++) {
		cout << p[i] << " ";
	}
	cout << endl;
}

template<typename T>
void GtLever(T* p, int n, T lever) {
	T temp[100];
	int index = 0;
	for (int i = 0; i < n; i++) {
		if (p[i] > lever) {
			temp[index++] = p[i];
		}
	}
	Print(temp, index);
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