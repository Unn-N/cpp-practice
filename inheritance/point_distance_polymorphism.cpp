#include<iostream>	
#include<cmath>

using namespace std;

struct Point {
	int x;
	int y;
	Point(int x, int y) :x(x), y(y) {}
};

class Distance {
public:
	Point p1;
	Point p2;
	virtual long long calculateDistance() = 0;
	Distance(Point p1, Point p2) :p1(p1), p2(p2) {}
	virtual ~Distance() {}

};

class EuclideanDistance : public Distance {
public:
	EuclideanDistance(Point p1, Point p2) : Distance(p1, p2) {}
	long long calculateDistance() override {
		long long dx = p2.x - p1.x, dy = p2.y - p1.y;
		return dx * dx + dy * dy;
	}
};

class ManhattanDistance : public Distance {
public:
	ManhattanDistance(Point p1, Point p2) : Distance(p1, p2) {}
	long long calculateDistance() override {
		return abs(p2.x - p1.x) + abs(p2.y - p1.y);
	}
};

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	Point p1(a, b);
	Point p2(c, d);
	Distance* d1 = new EuclideanDistance(p1, p2);
	Distance* d2 = new ManhattanDistance(p1, p2);
	cout << d2->calculateDistance() << " " << d1->calculateDistance();
	return 0;
}