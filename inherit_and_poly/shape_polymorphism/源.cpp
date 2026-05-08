#include<iostream>
#include<cmath>
using namespace std;

class Shape {
public:
	virtual double getArea() const = 0;
	virtual double getPerimeter() const = 0;
	virtual ~Shape() = default;
};

class Circle : public Shape {
private:
	int r;
public:
	Circle(int r) : r(r) {}

	double getArea() const override {
		if (r <= 0) return 0;
		return 3.14 * r * r;
	}

	double getPerimeter() const override {
		if (r <= 0) return 0;
		return 2 * 3.14 * r;
	}

	double operator-(const Circle& other) const {
		return fabs(getArea() - other.getArea());
	}
};

class Rectangle : public Shape {
private:
	int a, b;
public:
	Rectangle(int a, int b) : a(a), b(b) {}

	double getArea() const override {
		if (a <= 0 || b <= 0) return 0;
		return a * b;
	}

	double getPerimeter() const override {
		if (a <= 0 || b <= 0) return 0;
		return 2 * (a + b);
	}
};

int main() {
	int r1, r2, len, wid;
	cin >> r1 >> r2 >> len >> wid;

	Circle c1(r1);
	Circle c2(r2);
	Rectangle rec(len, wid);

	Shape* s1 = &c1;
	Shape* s2 = &rec;

	cout << s1->getArea() << " " << s1->getPerimeter() << endl;
	cout << s2->getArea() << " " << s2->getPerimeter() << endl;
	cout << (c1 - c2) << endl;

	return 0;
}