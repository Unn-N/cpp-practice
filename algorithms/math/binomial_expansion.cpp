#include<iostream>
#include<vector>

using namespace std;

long long factorial(int n) {
	long long res = 1;
	for (int i = 1; i <= n; i++) {
		res *= i;
	}
	return res;
}

long long C(int n, int k) {
	return factorial(n) / (factorial(k) * factorial(n - k));
}

long long power(int a, int n) {
	long long res = 1;

	for (int i = 0; i < n; i++) {
		res *= a;
	}

	return res;
}

struct Term {
	long long coef;
	int x;
	int y;
	Term(long long a, int b, int c) :coef(a), x(b), y(c) {}
};

void print(Term term) {
	bool isConstant = (term.x == 0 && term.y == 0);

	if (term.coef == 1 && !isConstant) {
	}
	else if (term.coef == -1 && !isConstant) {
		cout << "-";
	}
	else {
		cout << term.coef;
	}

	if (term.x > 0) {
		cout << "x";

		if (term.x > 1) {
			cout << "^" << term.x;
		}
	}

	if (term.y > 0) {
		cout << "y";

		if (term.y > 1) {
			cout << "^" << term.y;
		}
	}
}

int main() {
	int a, b, n;
	cin >> a >> b >> n;

	vector<Term>terms;

	for (int i = 0; i < n + 1; i++) {
		Term term = Term(C(n, i) * power(a, n - i) * power(b, i), n - i, i);
		if (term.coef != 0)
			terms.push_back(term);
	}
	for (int i = 0; i < terms.size(); i++)
	{
		if (i != 0)
		{
			if (terms[i].coef > 0)
				cout << "+";
		}

		print(terms[i]);
	}
	return 0;
}