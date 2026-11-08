#include<iostream>
#include<cmath>

using namespace std;

/*int gcd(int a, int b) {
	a = abs(a);
	b = abs(b);
	while (b) {
		int t = a % b; a = b; b = t;
	}
	return a;
}*/

int gcd(int a, int b) {
	a = abs(a);
	b = abs(b);
	while (b) {
		int t = a % b;
		a = b; 
		b = t;
	}
	return a;
}

class Rational {
private:
	int up;
	int down;
public:
	Rational() { up = 0; down = 1; };
	Rational(int a, int b) :up(a), down(b) {
		format();
	}

	void format() {
		if (down < 0) {
			up = -up;
			down = -down;
		}
		int g = gcd(up, down);
		if (g) {
			up = up / g;
			down = down / g;
		}
	}

	Rational operator+(const Rational& other)const {
		int newup = this->up * other.down + this->down * other.up;
		int newdown = this->down * other.down;
		Rational res(newup, newdown);
		return res;
	}

	Rational operator-(const Rational& other)const {
		int newup = this->up * other.down - this->down * other.up;
		int newdown = this->down * other.down;
		Rational res(newup, newdown);
		return res;
	}

	friend Rational operator*(const Rational& a, const Rational& b) {
		return Rational(a.up * b.up, a.down * b.down);
	}

	friend Rational operator/(const Rational& a, const Rational& b) {
		return Rational(a.up * b.down, a.down * b.up);
	}

	Rational& operator++() {
		up += down;        // 加 1/1：(up+down)/down
		format();          // 保险起见重新规约（其实互质性保住了，可省）
		return *this;
	}

	Rational operator++(int) {
		Rational temp = *this;
		this->up += this->down;
		return temp;
	}

	Rational& operator=(Rational& other) {
		int a = other.up;
		int b = other.down;
		up = b;
		down = a;
		return *this;
	}

	friend ostream& operator<<(ostream& os, const Rational& r) {
		if (r.down == 1) os << r.up;
		else os << r.up << "/" << r.down;
		return os;
	}
};


int main() {
	int up1, down1, up2, down2;
	cin >> up1 >> down1 >> up2 >> down2;

	Rational r1(up1, down1);
	Rational r2(up2, down2);

	cout << (r1 + r2) << endl;
	cout << (r1 - r2) << endl;
	cout << (r1 * r2) << endl;
	cout << (r1 / r2) << endl;

	Rational r1_inc = r1;
	r1_inc++;
	Rational r2_inc = r2;
	r2_inc++;
	cout << r1_inc << " " << r2_inc << endl;

	Rational R1, R2;
	R1 = r1;
	R2 = r2;
	cout << R1 << " " << R2 << endl;

	return 0;
}