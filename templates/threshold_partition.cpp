#include<iostream>
#include<string>

using namespace std;

template<typename T>
void Print(T* p, int n) {
	for (int i = 0; i < n; i++) {
		cout << p[i] << " ";
	}
}

template<typename T>
void GtLever(T* p, int n, T lever) {
	int j = 0;
	for (int i = 0; i < n; i++) {
		if(p[i] > lever) {
			T temp = p[i];
			p[i] = p[j];
			p[j] = temp;
			j++;
		}
	}
	
	Print(p, j);
	
}

template<typename T>
void solve(int len,int n) {
	T* arr = new T[len];
	for (int i = 0; i < len; i++) {
		cin >> arr[i];
	}
	T lever;
	cin >> lever;
	GtLever<T>(arr, n, lever);
	delete[]arr;
}

int main() {
	string type;
	int len;
	int n;
	cin >> type >> len >> n;
	if (type == "char")solve<char>(len, n);
	if (type == "int")solve<int>(len, n);
	if (type == "float")solve<float>(len, n);
	return 0;
}