#include<iostream>
#include<string>

using namespace std;

class String {
protected:
	string str;
public:
	String() {
		str = "1234567890";
	}
	~String() {}
	void setStr(string in) {
		str = in;
	}
	string getStr() {
		return str;
	}
	int getSize() {
		return str.size();
	}
	void print() {
		cout << str << endl;
	}
};

class EditableString :public String {
public:
	void insert(int pos, char c) {
		if (pos<1 || pos>(int)str.size() + 1) {
			return;
		}
		str.resize(str.size() + 1);
		for (int i = str.size() - 2; i >= pos - 1; i--) {
			str[i + 1] = str[i];
		}
		str[pos - 1] = c;
	}
	void remove(int pos) {
		if (pos<1 || pos>(int)str.size()) {
			return;
		}
		for (int i = pos - 1; i < str.size()-1; i++) {
			str[i] = str[i + 1];
		}
		str.resize(str.size() - 1);
	}
	void replace(int pos, char c) {
		if (pos<1 || pos>(int)str.size()) {
			return;
		}
		str[pos - 1] = c;
	}
};
int main() {
	EditableString str;
	char cmd;
	while (cin >> cmd) {
		if (cmd == 'i') {
			int p;
			char c;
			cin >> p >> c;
			str.insert(p, c);
			str.print();
		}
		else if (cmd == 'd') {
			int p;
			cin >> p;
			str.remove(p);
			str.print();
		}
		else if (cmd == 'r') {
			int p;
			char c;
			cin >> p >> c;
			str.replace(p, c);
			str.print();
		}
		else break;
	}
	return 0;
}