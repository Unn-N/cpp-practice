#include<iostream>
#include<string>
#include<algorithm>


using namespace std;

template<typename T>
class ArraySorter{
public:
	void sort(T arr[], int n) {
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				if (arr[j] > arr[j + 1]) {
					T temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}

	void print(const T arr[], int n) {
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

int main() {

	int n1;
	cin >> n1;
	int intArr[100];
	for (int i = 0; i < n1; i++) {
		cin >> intArr[i];
	}
	ArraySorter<int>intSorter;
	intSorter.sort(intArr, n1);
	intSorter.print(intArr, n1);

	int n2;
	cin >> n2;
	char charArr[100];
	for (int i = 0; i < n2; i++) {
		cin >> charArr[i];
	}
	ArraySorter<char>charSorter;
	charSorter.sort(charArr, n2);
	charSorter.print(charArr, n2);

	int n3;
	cin >> n3;
	string strArr[100];
	for (int i = 0; i < n3; i++) {
		cin >> strArr[i];
	}
	ArraySorter<string>strSorter;
	strSorter.sort(strArr, n3);
	strSorter.print(strArr, n3);

	return 0;
}