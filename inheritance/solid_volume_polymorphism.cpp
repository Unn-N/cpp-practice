#include<iostream>

using namespace std;

class Circle {
public:
	int radius;
	virtual int getVolume() = 0;
};

class Cylinder : public Circle {
public:
	int height;
	int getVolume() override {
		return radius * radius * height;
	}
};

class Cone : public Circle {
public:
	int height;
	int getVolume() override {
		return (radius * radius * height) / 3;
	}
};

class Sphere : public Circle {
public:
	int getVolume() override {
		return (4 * radius * radius * radius) / 3;
	}
};

int main() {
	int n;
	cin >> n;
	while (n--) {
		int type;
		cin >> type;
		Circle* ptr = nullptr;
		if (type == 1) {
			Cylinder c;
			cin >> c.radius >> c.height;
			ptr = &c;
		}
		else if (type == 2) {
			Cone c;
			cin >> c.radius >> c.height;
			ptr = &c;
		}
		else if (type == 3) {
			Sphere s;
			cin >> s.radius;
			ptr = &s;
		}
		cout << ptr->getVolume() << endl;
	}
	return 0;
}