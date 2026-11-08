#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<strstream>
#include<algorithm>

using namespace std;

class Goods {
protected:
	int num;
	string brand;
public:
	Goods(int n, string b) :num(n), brand(b) {}
	virtual void printMsg() = 0;
	int getNum() {
		return num;
	}
	virtual ~Goods() {}
};

class NormalDig :public Goods {
private:
	double cost;
	int count;
public:
	NormalDig(int n, string b, double c, int count) :Goods(n, b), cost(c), count(count) {}
	void printMsg()override {
		cout << num << " " << brand << " " << cost << " " << count << endl;
	}
	int getCount() {
		return count;
	}
};

class FlagDig :public Goods {
private:
	double cost;
	int count;
	string version;
public:
	FlagDig(int n, string b, double c, int count, string v) :Goods(n, b), cost(c), count(count), version(v) {}
	void printMsg()override {
		cout << num << " " << brand << " " << cost << " " << count << " " << version << endl;
	}
	int getCount() {
		return count;
	}
};

int main() {
	string cmd;
	vector<Goods>goods;
	while (cin >> cmd) {
		if (cmd == "create") {
			string line;
			int n;
			int num;
			string brand;
			double cost;
			int count;
			string version;
			cin.getline() >> num >> brand >> cost >> count >> version;
			if (version == "") {
				Goods* a = new NormalDig(num, brand, cost, count);
				goods.push_back(*a);
			}
			else {
				Goods* a = new FlagDig(num, brand, cost, count);
				goods.push_back(*a);
			}
		}
		else if (cmd == "search") {
			int num;
			cin >> num;
			for (auto it : goods) {
				if (it.num == num) {
					it.printMsg();
				}
			}
			if (it == goods.end()) {
				cout << "no item" << endl;
			}
		}
		else if (cmd == "sum") {
			int sum;
			for (auto it : goods) {
				sum += it.count;
			}
			cout << sum << endl;
		}
		else if (cmd == "quit") {
			break;
		}
		return 0;
	}