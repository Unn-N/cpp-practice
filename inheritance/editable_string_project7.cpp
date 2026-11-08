#include<iostream>
#include<string>							

using namespace std;

class String {
public:
	string str;
	String (){
		str = "1234567890";
	}
	~String() {};
	String (string s) {
		str = s;
	}
	void print () {
		cout << str << endl;
	}
};

class EString : public String {
public:
	void insert(int pos, char c) {
		if(pos<1 || pos>str.length()+1) {
			return;
		}
		str.insert(pos - 1, 1, c);
	}
	void remove(int pos) {
		if(pos<1 || pos>str.length()) {
			return;
		}
		str.erase(pos - 1, 1);
	}
	void replace(int pos, char c) {
		if(pos<1 || pos>str.length()) {
			return;
		}
		//str.replace(pos - 1, 1, 1, c);
		str[pos - 1] = c;
	}
};

int main() {
	EString s;
	string cmd;
	while (cin >> cmd) {
		if (cmd == "i") {
			int pos;
			char c;
			cin >> pos >> c;
			s.insert(pos, c);
			s.print();
		}
		else if (cmd == "d") {
			int pos;
			cin >> pos;
			s.remove(pos);
			s.print();
		}
		else if (cmd == "r") {
			int pos;
			char c;
			cin >> pos >> c;
			s.replace(pos, c);
			s.print();
		}
		else {
			break;
		}
	}
	return 0;
}
