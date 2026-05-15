#include<iostream>

using namespace std;

class Fruit {
protected:
	int Price;
	int Weight;
public:
	virtual double SumMoney(int p, int w) = 0;
};

class Apple :public Fruit {
public:
	double SumMoney(int p, int w) override {
		return p * w * 0.9;
	}
};

class Banana :public Fruit {
public:
	double SumMoney(int p, int w)override {
		if (w >= 10)return w * p / 2.0;
		if (w >= 5)return w * p * 0.8;
		return w * p;
	}
};

class Orange :public Fruit {
public:
	double SumMoney(int p, int w)override {
		return p * w / 2.0;
	}
};

int main() {
	char c;
	double sum = 0;
	while (cin >> c && c != 'q') {
		int w, p;
		cin >> w >> p;
		Fruit* f = nullptr;
		if (c == 'a')f = new Apple();
		else if (c == 'o') f = new Orange();
		else if (c == 'b') f = new Banana();
		sum += f->SumMoney(p,w);
		delete f;
	}
	cout << sum << endl;
	return 0;
}