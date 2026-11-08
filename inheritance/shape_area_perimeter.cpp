#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

class Shape {
public:
	virtual double getArea() const = 0;
	virtual double getPerimeter() const = 0;
};

class Circle : public Shape {
private:
	double radius;
public:
	Circle(double r) : radius(r) {}
	double getArea() const override {
		if (radius <= 0) {
			return (int)0;
		}
		return 3.14 * radius * radius;
	}
	double getPerimeter() const override {
		if (radius <= 0) {
			return (int)0;
		}
		return 2 * 3.14 * radius;
	}

	double operator-(const Circle& other) const {
		if (radius <= 0 || other.radius <= 0) return 0;
		return fabs(getArea() - other.getArea());
	}
};

class Rectangle : public Shape {
private:
	double width, height;
public:
	Rectangle(double w, double h) : width(w), height(h) {}
	double getArea() const override {
		if (width <= 0 || height <= 0) {
			return 0;
		}
		return width * height;
	}
	double getPerimeter() const override {
		if (width <= 0 || height <= 0) {
			return 0;
		}
		return 2 * (width + height);
	}
};

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	Circle circle1(a);
	Circle circle2(b);
	Rectangle rect(c, d);

	

	cout << circle1.getArea() << " " << circle1.getPerimeter() << endl;
	cout << rect.getArea() << " " << rect.getPerimeter() << endl;
	cout << (circle1 - circle2) << endl;

	return 0;
}