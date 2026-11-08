#include<iostream>
#include<algorithm>

using namespace std;

template<typename T>
class Sorter {
public:
	T* arr;
	int n;
	Sorter(T* arr, int n) : arr(arr), n(n) {}
	void sort() {
		for(int i=0;i<n;i++) {
			for(int j=0;j<n-i-1;j++) {
				if(arr[j]>arr[j+1]) {
					swap(arr[j], arr[j+1]);
				}
			}
		}
	}
};


int main() {
	int len1;
	cin >> len1;
	int* arr1 = new int[len1];
	for(int i=0;i<len1;i++) {
		cin >> arr1[i];
	}
	Sorter<int> sorter1(arr1,len1);
	sorter1.sort();
	for(int i=0;i<len1;i++) {
		cout << arr1[i] << " ";
	}
	cout << endl;

	int len2;
	cin >> len2;
	char* arr2 = new char[len2];
	for(int i=0;i<len2;i++) {
		cin >> arr2[i];
	}
	Sorter<char> sorter2(arr2,len2);
	sorter2.sort();
	for(int i=0;i<len2;i++) {
		cout << arr2[i] << " ";
	}
	cout << endl;

	int len3;
	cin >> len3;
	string* arr3 = new string[len3];
	for(int i=0;i<len3;i++) {
		cin >> arr3[i];
	}
	Sorter<string> sorter3(arr3,len3);
	sorter3.sort();
	for(int i=0;i<len3;i++) {
		cout << arr3[i] << " ";
	}
	cout << endl;
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	return 0;
}