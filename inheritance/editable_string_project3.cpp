#include<iostream>
#include<string>

using namespace std;

class String {
public:
	string str;
	String() :str("1234567890") {}
	~String() {}
	String(string s) :str(s) {}
	void print() {
		cout << str << endl;
	}
};

class EString :public String {
public:
	void insert(int pos, char c) {
		if (pos<1 || pos>str.size() + 1)return;
		str.insert(pos - 1, 1, c);
	}
	void remove(int pos) {
		if (pos<1 || pos>str.size() + 1)return;
		str.erase(pos - 1, 1);
	}
	void replace(int pos, char c) {
		if (pos<1 || pos>str.size() + 1)return;
		str[pos - 1] = c;
	}

};

int main() {
	EString str;
	string cmd;
	while (cin >> cmd) {
		if (cmd == "q")break;
		if (cmd == "i") {
			int pos;
			char c;
			cin >> pos >> c;
			str.insert(pos, c);
			str.print();
		}
		if (cmd == "d") {
			int pos;
			cin >> pos;
			str.remove(pos);
			str.print();
		}
		if (cmd == "r") {
			int pos;
			char c;
			cin >> pos >> c;
			str.replace(pos, c);
			str.print();
		}
	}
	return 0;
}

