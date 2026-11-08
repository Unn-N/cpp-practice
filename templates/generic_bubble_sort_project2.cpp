#include<iostream>
#include <string>
#include<iomanip>

using namespace std;

template<typename T>
class Sort {
public:
	Sort() {}
	Sort(T* arr, int n) :arr(arr), n(n) {}
	~Sort() {}
	T* arr;
	int n;
	void sort() {
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				if (arr[j] > arr[j + 1]) {
					swap(arr[j], arr[j + 1]);
				}
			}
		}
	}

	void print() {
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	int n1;
	cin >> n1;
	int intarr[100];
	for (int i = 0; i < n1; i++) {
		cin >> intarr[i];
	}
	Sort<int > arr1(intarr, n1);
	arr1.sort();
	arr1.print();

	int n2;
	cin >>n2;
	char chararr[100];
	for (int i = 0; i < n2; i++) {
		cin >> chararr[i];
	}
	Sort<char> arr2(chararr, n2);
	arr2.sort();
	arr2.print();

	int n3;
	cin >> n3;
	string strarr[100];
	for (int i = 0; i < n3; i++) {
		cin >> strarr[i];
	}
	Sort<string> arr3(strarr, n3);
	arr3.sort();
	arr3.print();

	return 0;
}