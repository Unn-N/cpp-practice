#include<iostream>
#include<cmath>

using namespace std;

class Distance {
protected:
	int x1, y1, x2, y2;
public:
	Distance(int a, int b, int c, int d) :x1(a), y1(b), x2(c), y2(d) {}
	virtual int calculate() const = 0;
	virtual ~Distance() = default;
};

class ManhattanDistance :public Distance {
public:
	ManhattanDistance(int a,int b,int c,int d):Distance(a,b,c,d){}
	int calculate()const override {
		return abs(x1 - x2) + abs(y1 - y2);
	}
};

class EuclideanDistance :public Distance {
public:
	EuclideanDistance(int a,int b,int c,int d):Distance(a,b,c,d){}
	int calculate()const override {
		int dx = x1 - x2;
		int dy = y1 - y2;
		return dx * dx + dy * dy;
	}
};

int main() {
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	Distance* manhattan = new ManhattanDistance(x1, y1, x2, y2);
	Distance* euclidean = new EuclideanDistance(x1, y1, x2, y2);

	cout << manhattan->calculate() << " "
		<< euclidean->calculate() << endl;

	delete manhattan;
	delete euclidean;
	
	return 0;
}