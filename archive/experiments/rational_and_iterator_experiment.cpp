#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

class Rational {
private:
	int up;
	int down;
public:
	Rational() { up = 0; down = 1; }
	Rational(int a, int b) :up(a), down(b) {}

	Rational operator+(Rational& other) {
		int a = this->up * other.down+other.up*this->down;
		int b = this->down * other.down;
		Rational ans(a, b);
		return ans;
	}
	friend Rational operator+(Rational& a, Rational& b) {
		int nup = a.up * b.down + b.up * a.down;
		int ndown = a.down * b.down;
		Rational ans(nup, ndown);
		return ans;
	}
	Rational& operator++() {
		this->up = this->up + this->down;
		return *this;
	}
	Rational operator++(int) {
		Rational temp = *this;
		this->up = this->up + this->down;
		return temp;
	}
};

class Rational2 :public Rational {
public:
	int fuhao;
	Rational2(int zhengfu, int a, int b) :Rational(a, b), fuhao(zhengfu) {}
};
int main() {
	vector<int>arr = { 1,2,3,4,5 };

	for (vector<int>::iterator it = arr.begin(); it != arr.end(); it++) {
		cout << *it << " ";
	}
	return 0;
}