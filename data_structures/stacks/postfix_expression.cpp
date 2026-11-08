#include<iostream>

using namespace std;

const int MAX = 100;

class Stack {
public:
	int arr[MAX];
	int top;
	Stack() { top = -1; }
	void push(int n) { arr[++top] = n; }
	void pop() {
		if (!empty()) {
			top--;
		}
	}
	int getTop() {
		if (!empty()) {
			return arr[top];
		}
		return -1;
	}
	bool empty() { return top == -1; }
};

int main() {
	char s[MAX];
	cin >> s;
	Stack st;
	int num = 0;

	for (int i = 0; s[i] != '@'; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			num = num * 10 + (s[i] - '0');
		}
		else if (s[i] == '.') {
			st.push(num);
			num = 0;
		}
		else {
			int b = st.getTop();
			st.pop();
			int a = st.getTop();
			st.pop();
			int res = 0;
			switch (s[i]) {
			case'+':res = a + b; break;
			case'-':res = a - b; break;
			case'*':res = a * b; break;
			case'/':res = a / b; break;
			}
			st.push(res);
		}
	}
	cout << st.getTop() << endl;
	return 0;
}