#include<iostream>
#include<string>
using namespace std;

template <typename T>
void Print(T* p, int n) {
	for (int i = 0; i < n; i++) {
		cout << p[i] << " ";
	}cout << endl;
}

template <typename T>
void GtLever(T* p, int n, T lever) {
	T* arr = new T[n];
	int index = 0;
	for (int i = 0; i < n; i++) {
		if(p[i]> lever) {
			arr[index] = p[i];
			index++;
		}
	}
	Print(arr, index);
	delete[] arr;
}

int main() {
	string type;
	int len, n;
	cin >> type >> len >> n;
	if(type=="int") {
		int* arr = new int[len];
		for (int i = 0; i < len; i++) {
			cin >> arr[i];
		}
		int lever;
		cin >> lever;
		GtLever(arr, n, lever);
	}
	else if(type=="float") {
		float* arr = new float[len];
		for (int i = 0; i < len; i++) {
			cin >> arr[i];
		}
		float lever;
		cin >> lever;
		GtLever(arr, n, lever);
	}
	else if(type=="char") {
		char* arr = new char[len];
		for (int i = 0; i < len; i++) {
			cin >> arr[i];
		}
		char lever;
		cin >> lever;
		GtLever(arr, n, lever);
	}
	return 0;
}