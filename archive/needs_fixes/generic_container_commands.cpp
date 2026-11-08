#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

template<typename T>
class MyContainer {
private:
	vector<T>arr;
public:
	MyContainer(T array[], int len) {
		for (int i = 0; i < len; i++) {
			arr.push_back(array[i]);
		}
	}

	void append(const T& val) {
		arr.push_back(val);
	}

	void insert(const T& val, int idx) {
		if (idx<0 || idx>arr.size()) {
			cout << "BoundsLimit" << endl;
			return;
		}
		arr.insert(arr.begin() + idx, val);
	}

	bool empty() {
		return arr.empty();
	}

	int size() {
		return arr.size();
	}

	void display() {
		if (arr.empty()) {
			cout << "None" << endl;
			return;
		}
		cout << "[";
		for (int i = 0; i < (int)data.size(); i++) {
			if (i) cout << ",";
			cout << data[i];
		}
		cout << "]" << endl;
	}

	void clear() {
		arr.clear();
	}
};

template<typename T>
void process(MyContainer<T>& c, const string& line) {
	istringstream ss(line);
	string op;
	while (ss >> op) {
		if (op == "d") c.display();
		else if (op == "c")c.clear();
		else if (op == "s")break;
		else if (op == "a") {
			T val;
			ss >> val;
			c.append(val);
		}
		else if (op == "i") {
			T val;
			int idx;
			ss >> val >> idx;
			c.insert(val, idx);
		}
	}
}

int main() {
	int iarray[] = { 0,1,1,2,3,5,8,13,21,34,55,89 };
	float farray[] = { 0,0.125,0.25,0.375,0.5,0.625,0.75,0.875,1.0 };
	char carray[] = "I_love_Nankai_University";

	MyContainer<int> ic(iarray, 12);
	MyContainer<float> fc(farray, 9);
	MyContainer<char> cc(carray, 24);

	string line;
	getline(cin, line);
	process(ic, line);
	getline(cin, line);
	process(fc, line);
	getline(cin, line);
	process(cc, line);

	return 0;
}