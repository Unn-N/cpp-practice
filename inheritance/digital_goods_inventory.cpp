#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<sstream>
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
	virtual int getCount() = 0;
	
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
	int getCount()override {
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
	int getCount() override{
		return count;
	}
};

int main() {
	vector<Goods*>goods;
	string line;
	while (getline(cin, line)) {
		string cmd;
		istringstream iss(line);
		iss >> cmd;
		if (cmd == "create") {
			int n;
			string b;
			double c;
			int count;
			string v;
			iss >> n >> b >> c >> count;
			if (iss >> v) {
				Goods* g = new FlagDig(n, b, c, count, v);//////////////////
				goods.push_back(g);
			}
			else {
				Goods* g = new NormalDig(n, b, c, count);
				goods.push_back(g);
			}
		}
		else if (cmd == "search") {
			int n;
			iss >> n;
			bool found = false;
			for (auto it : goods) {
				if (it->getNum() == n) {
					it->printMsg();/////////////////////////////////////////////
					found = true;
					break;
				}
			}
			if (found == false) {
				cout << "no item" << endl;
			}
		}
		else if (cmd == "sum") {
			int sum = 0;
			for (auto it : goods) {
				sum += it->getCount();/////////////////
			}
			cout << sum << endl;
		}
		else if (cmd == "quit") {
			break;
		}
	}
	for (auto it : goods) { delete it; }
	return 0;
}