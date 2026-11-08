#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

struct Point {
	int x;
	int y;

	Point(int x, int y) :x(x), y(y) {}
};

class MyLine {
public:
	Point e1;
	Point e2;
	MyLine(Point p1, Point p2) :e1(p1), e2(p2) {}
	double length();
	int  intersect();
	friend int  parallel(MyLine l1, MyLine l2);
};

double MyLine::length() {
	int dx = abs(e1.x - e2.x);
	int dy = abs(e1.y - e2.y);
	double len = sqrt(dx * dx + dy * dy);
	return len;
}
//有0也算相交
int  MyLine::intersect() {
	if (e1.x * e2.x <= 0 || e1.y * e2.y <= 0) {
		return 1;
	}
	else {
		return 0;
	}
}	
//用叉乘而不是斜率防止除0
int  parallel(MyLine l1, MyLine l2) {
	int dx1 = l1.e1.x - l1.e2.x;
	int dy1 = l1.e1.y - l1.e2.y;
	int dx2 = l2.e1.x - l2.e2.x;
	int dy2 = l2.e1.y - l2.e2.y;
	if (dx1 * dy2 == dx2 * dy1)return 1;
	else return 0;
}

int main() {
	int x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	Point p1(x1, y1);
	Point p2(x2, y2);
	Point p3(x3, y3);
	Point p4(x4, y4);
	MyLine l1(p1, p2);
	MyLine l2(p3, p4);

	cout <<fixed<<setprecision(2)<< l1.length() << " "
	<<l1.intersect();
	cout << endl;

	cout <<fixed<<setprecision(2)<< l2.length() << " "
	<<l2.intersect();
	cout << endl;

	cout<<parallel(l1, l2);

	return 0;
}
