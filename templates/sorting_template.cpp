#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

template<typename T>
class SortArr {
public:
	T* arr;
	int len;
	SortArr(int n, T* arr) :len(n), arr(arr) {};
	void sort();
	void print()const;
};

template<typename T>
void SortArr<T>::sort() {
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

template<typename T>
void SortArr<T>::print()const {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int n1;
	cin >> n1;
	int* arr1 = new int[n1];
	for (int i = 0; i < n1; i++) {
		cin >> arr1[i];
	}
	SortArr<int>s1(n1, arr1);
	s1.sort();
	s1.print();
	delete[] arr1;

	int n2;
	cin >> n2;
	char* arr2 = new char[n2];
	for (int i = 0; i < n2; i++) {
		cin >> arr2[i];
	}
	SortArr<char>s2(n2, arr2);
	s2.sort();
	s2.print();
	delete[] arr2;

	int n3;
	cin >> n3;
	string* arr3 = new string[n3];
	for (int i = 0; i < n3; i++) {
		cin >> arr3[i];
	}
	SortArr<string>s3(n3, arr3);
	s3.sort();
	s3.print();
	delete[] arr3;

	return 0;
}