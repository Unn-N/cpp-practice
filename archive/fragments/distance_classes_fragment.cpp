#include<iostream>
#include<cmath>

using namespace std;

class Distance {
protected:
	int x1, y1, x2, y2;
public:
	Distance() {
		x1 = y1 = x2 = y2 = 0;
	}
	Distance(int a, int b, int c, int d) {
		x1 = a;
		y1 = b;
		x2 = c;
		y2 = d;
	}
	virtual int calculate()const = 0;
	virtual ~Distance() = default;
};

class EuclideanDistance : public Distance {
public:
	EuclideanDistance() : Distance() {}
	EuclideanDistance(int a, int b, int c, int d) : Distance(a, b, c, d) {}
	int calculate()const override {
		return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	}

};

class ManhattanDistance : public Distance {
public:
	ManhattanDistance() : Distance() {}
	ManhattanDistance(int a, int b, int c, int d) : Distance(a, b, c, d) {}
	int calculate()const override {
		return abs(x2 - x1) + abs(y2 - y1);
	}
};