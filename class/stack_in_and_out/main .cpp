#include<iostream>

using namespace std;

const int MAX = 100;

class Stack {
public:
	int arr[MAX];
	int top;
	Stack() { top = -1; }
	void push(int n) { arr[++top] = n; }
	void pop() { top--; }
	int getTop() { return arr[top]; }
	bool empty() { return top == -1; }
};

int main() {
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		int in[MAX], out[MAX];

		for (int i = 0; i < n; i++) {
			cin >> in[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> out[i];
		}

		Stack st;
		int idx = 0;

		for (int i = 0; i < n; i++) {
			st.push(in[i]);
			while (!st.empty() && st.getTop() == out[idx]) {
				st.pop();
				idx++;
			}
		}

		cout << (st.empty() ? "Yes" : "No") << endl;
	}
	return 0;
}
