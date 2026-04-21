#include<iostream>
#include<string>

using namespace std;

class String {
protected:
	string data;
public:
	String() :data("1234567890") {}
	String(const string& s) :data(s) {} // 修改此处，参数类型加const和引用

	void setContent(const string& s) { data = s; }
	string getContent() { return data; }
	int getlen() { return data.size(); }
};

class EditableString :public String {
public:
	EditableString() :String() {}
	EditableString(const string& s) :String(s) {}

	bool insert(int pos, char c) {
		if (pos<1 || pos>data.size() + 1) {
			return false;
		}
		data.insert(pos - 1, 1, c);
		return true;
	}

	bool replace(int pos, char c) {
		if (pos<1 || pos>data.size() + 1) {
			return false;
		}
		data[pos - 1] = c;
		return true;
	}

	bool remove(int pos) {
		if (pos<1 || pos>data.size() + 1) {
			return false;
		}
		data.erase(pos - 1, 1);
		return true;
	}
};

int main() {
	EditableString str;
	string cmd;
	while (cin >> cmd) {
		if (cmd == "q")
			break;

		if (cmd == "i") {
			int pos;
			char c;
			cin >> pos >> c;
			str.insert(pos, c);
			cout << str.getContent() << endl;
		}
		if (cmd == "d") {
			int pos;
			cin >> pos;
			str.remove(pos);
			cout << str.getContent() << endl;
		}
		if (cmd == "r") {
			int pos;
			char c;
			cin >> pos >> c;
			str.replace(pos, c);
			cout << str.getContent() << endl;
		}
	}
	return 0;
}